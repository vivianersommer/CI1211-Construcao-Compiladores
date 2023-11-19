%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "estruturas/tabelaSimbolos.h"
#include "estruturas/rotulos.h"
#include "estruturas/deslocamentos.h"


TabelaSimbolos tabelaSimbolos;
NodoSimbolo* nodo;
PilhaRotulos* rotulos;
PilhaDeslocamentos* deslocamentos;
int variaveis_inicializacao;
int nivel, deslocamento;
int nivel_destino, deslocamento_destino;
int inicioRotulos;
int identificadorRotulo;
char nome_comando[1000], nome_comando_2[1000];
char conteudo_comando[1000], ident_aux[1000];

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO

%token T_LABEL T_TYPE T_IF NUMERO
%token T_ARRAY T_PROCEDURE T_FUNCTION T_GOTO MENOR
%token T_THEN T_ELSE T_WHILE T_DO T_OR T_DIVISAO_INT
%token T_AND T_NOT READ WRITE BOOLEAN TRUE FALSE
%token OF REPEAT UNTIL MAIS MENOS MULTIPLICACAO MAIOR
%token MENOR_OU_IGUAL MAIOR_OU_IGUAL DIFERENTE IGUAL
%token T_DIVISAO_real ABRE_COLCHETES FECHA_COLCHETES

%%

programa:	{
			geraCodigo (NULL, "INPP");
		}
		PROGRAM tipo_inicio PONTO_E_VIRGULA bloco PONTO
		{
			geraCodigo (NULL, "PARA");
		}
;

tipo_inicio:	IDENT
    	        | IDENT ABRE_PARENTESES lista_idents FECHA_PARENTESES

bloco:		part_decl_vars
		{
			inicioRotulos = geraRotulos(rotulos);
			sprintf(nome_comando, "%s %s%d", "DSVS", "R0", inicioRotulos);
			geraCodigo(NULL, nome_comando);
			sprintf(nome_comando, "R%02d", inicioRotulos);
		  	geraCodigo(nome_comando, "NADA");
		}
        	comand_compos
        	{
			for (int i = 0; i < deslocamento; i++){
				removeNodoTabelaSimbolos(&tabelaSimbolos, i);
			}
			sprintf(nome_comando, "%s %d", "DMEM", deslocamento);
			geraCodigo(NULL, nome_comando);
       		}
;

part_decl_vars:	var
;

var:		{
			deslocamento = 0;
	      	}
	     	VAR declara_vars
    	     	|
;

declara_vars:	declara_vars declara_var
            	| declara_var
;

declara_var :	{
			variaveis_inicializacao = 0;
               	}
            	lista_id_var DOIS_PONTOS tipo
             	{
	       		adicionaTipoVariavel(&tabelaSimbolos, variaveis_inicializacao, INTEIRO);
    			sprintf(nome_comando, "%s %d", "AMEM", variaveis_inicializacao);
			geraCodigo(NULL, nome_comando);

             	}
               	PONTO_E_VIRGULA
;

tipo:	      	IDENT
;

lista_id_var:	lista_id_var VIRGULA IDENT
               	{ 
                	variaveis_inicializacao++;
                	nodo = criaNodo(token, nivel, deslocamento);
                	insereNodoTabelaSimbolos(&tabelaSimbolos, nodo);
                	deslocamento++;
               	}
               	| IDENT               
               	{ 
                	variaveis_inicializacao++;
                	nodo = criaNodo(token, nivel, deslocamento);
                	insereNodoTabelaSimbolos(&tabelaSimbolos, nodo);
                	deslocamento++;
              	}
;	

lista_idents:	lista_idents VIRGULA IDENT
           	| IDENT
;

comand_compos:	T_BEGIN comandos T_END
               	| T_BEGIN comandos T_END PONTO_E_VIRGULA
               	{
               	}
;

comandos:	comandos comando
          	| comando
;

comando:	comand_s_rot
		|
;

comand_s_rot:	comand_ident
		| comando_repetitivo
                | READ ABRE_PARENTESES leitura FECHA_PARENTESES PONTO_E_VIRGULA
                | WRITE ABRE_PARENTESES impressao FECHA_PARENTESES PONTO_E_VIRGULA
;


comand_ident:	IDENT
            	{
              		strncpy(ident_aux, token, 100);
           	}
           	atri_proced
;

atri_proced: 	atribuicao
;

atribuicao:	ATRIBUICAO expressao PONTO_E_VIRGULA
		{
			nodo = buscaNodoTabelaSimbolos(&tabelaSimbolos, ident_aux);
			sprintf(nome_comando, "%s %d, %d", "ARMZ", nodo->nivel, nodo->deslocamento);
			geraCodigo(NULL, nome_comando);
		}
;

leitura: 	leitura VIRGULA IDENT
            	{
		       geraCodigo(NULL, "LEIT");
		       nodo = buscaNodoTabelaSimbolos(&tabelaSimbolos, token);
		       strcpy(nome_comando, "ARMZ \0");
		       sprintf(conteudo_comando, "%d, %d", nivel_destino, deslocamento_destino);
		       strcat(nome_comando, conteudo_comando);
		       geraCodigo(NULL, nome_comando);
            	}
            	| IDENT
            	{
		       geraCodigo(NULL, "LEIT");
		       nodo = buscaNodoTabelaSimbolos(&tabelaSimbolos, token);
		       strcpy(nome_comando, "ARMZ \0");
		       sprintf(conteudo_comando, "%d, %d", nivel_destino, deslocamento_destino);
		       strcat(nome_comando, conteudo_comando);
		       geraCodigo(NULL, nome_comando);
            	}
;

impressao:  	impressao VIRGULA fator
           	{
               		geraCodigo(NULL, "IMPR");
            	}
            	| fator
            	{
               		geraCodigo(NULL, "IMPR");
            	}
;


expressao:	expressao_sim expressa_com
;

expressa_com:	IGUAL expressao_sim
		{
			geraCodigo(NULL, "CMIG");
		}
		| DIFERENTE expressao_sim
		{
			geraCodigo(NULL, "CMDG");
		}
		| MENOR expressao_sim
		{
			geraCodigo(NULL, "CMME");
		}
		| MENOR_OU_IGUAL expressao_sim
		{
			geraCodigo(NULL, "CMEG");
		}
		| MAIOR_OU_IGUAL expressao_sim
		{
			geraCodigo(NULL, "CMAG");
		}
		| MAIOR expressao_sim
		{
			geraCodigo(NULL, "CMMA");
		}
		|
;

expressao_sim:	termo
		| MAIS termo
		| MENOS termo
		{
			geraCodigo(NULL, "CRCT -1");
			geraCodigo(NULL, "MULT");
		}
		| expressao_sim MAIS termo
		{
			geraCodigo(NULL, "SOMA");
		}
		| expressao_sim MENOS termo
		{
			geraCodigo(NULL, "SUBT");
		}
		| expressao_sim T_OR termo
		{
			geraCodigo(NULL, "DISJ");
		}
;

termo:		fator
		| termo MULTIPLICACAO fator
		{
			geraCodigo (NULL, "MULT");
		}
		| termo T_DIVISAO_INT fator
		{
			geraCodigo (NULL, "DIVI");
		}
		| termo T_AND fator
		{
			geraCodigo (NULL, "CONJ");
		}
;

fator:		var_func
		| NUMERO
	 	{
		 	strcpy(nome_comando, "CRCT \0");
			strcat(nome_comando, token);
			geraCodigo(NULL, nome_comando);
		}
		| ABRE_PARENTESES expressao FECHA_PARENTESES
		| T_NOT fator
		{
			geraCodigo(NULL, "NEGA");
		}
;

var_func:	IDENT
		{
		       strncpy(nome_comando, token, 100);
		}
		funcao_lista
;

funcao_lista:	{
			nodo = buscaNodoTabelaSimbolos(&tabelaSimbolos, token);
			sprintf(nome_comando, "%s %d,%d", "CRVL", nodo->nivel, nodo->deslocamento);
        		geraCodigo(NULL, nome_comando);
		}
;

assinatura:
;


comando_repetitivo:     T_WHILE
	       {
		  identificadorRotulo = geraRotulos(rotulos);
		  sprintf(nome_comando, "R%02d", identificadorRotulo);
		  geraCodigo(nome_comando, "NADA");
	       }
	       expressao
	       {
		  identificadorRotulo = geraRotulos(rotulos);
		  sprintf(nome_comando, "%s %s%d", "DSVF", "R0", identificadorRotulo);
		  geraCodigo(NULL, nome_comando);
	       }
	       T_DO comand_s_rot
	       {
		  int rotulo_1 = desempilhaRotulo(rotulos);
		  int rotulo_2 = desempilhaRotulo(rotulos);
		  sprintf(nome_comando, "%s %s%d", "DSVS", "R0", rotulo_2);
		  geraCodigo(NULL, nome_comando);
		  sprintf(nome_comando, "%s%d", "R0", rotulo_1);
		  geraCodigo(NULL, nome_comando);
		}
;



%%

int main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }


/* Inicia a Tabela de Simbolos -------------------------------------- */
   inicializaTabelaSimbolos(&tabelaSimbolos);

/* Inicia a Pilha de Rótulos ---------------------------------------- */
   rotulos = inicializaPilhaRotulos();

/* Inicia a Tabela de Simbolos -------------------------------------- */
   deslocamentos = inicializaPilhaDeslocamentos();

/* Inicia variaveis globais ------------------------------------------*/
   variaveis_inicializacao = 0;
   nivel = 0;
   deslocamento = 0;
   nivel_destino = 0;
   deslocamento_destino = 0;

   yyin=fp;
   yyparse();

   return 0;
}
