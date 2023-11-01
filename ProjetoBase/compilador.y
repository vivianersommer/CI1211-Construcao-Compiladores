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
int num_vars, novas_vars; 
int nivel, deslocamento;
int nivel_destino, deslocamento_destino;
int inicioRotulos;
int identificadorRotulo;
char nome_comando[50];
char conteudo_comando[50];

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO

%token T_LABEL T_TYPE T_IF NUMERO
%token T_ARRAY T_PROCEDURE T_FUNCTION T_GOTO MENOR
%token T_THEN T_ELSE T_WHILE T_DO T_OR T_DIVISAO_INT
%token T_AND T_NOT READ WRITE INTEGER BOOLEAN TRUE FALSE
%token OF REPEAT UNTIL MAIS MENOS MULTIPLICACAO MAIOR
%token MENOR_OU_IGUAL MAIOR_OU_IGUAL DIFERENTE IGUAL
%token T_DIVISAO_real ABRE_COLCHETES FECHA_COLCHETES

%%

programa    :  {
                  geraCodigo (NULL, "INPP");
                  inicioRotulos = geraRotulos(rotulos);
               }
               PROGRAM IDENT
               ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
               bloco PONTO 
               { 
                  removeNodoTabelaSimbolos(&tabelaSimbolos, num_vars);
                  strcpy(nome_comando, "DMEM \0");
                  sprintf(conteudo_comando, "%d", num_vars);
                  strcat(nome_comando, conteudo_comando);
                  geraCodigo(NULL, nome_comando);
                  geraCodigo (NULL, "PARA");
               }
;

bloco       :parte_declara_vars
	    {
	    }
            comando_composto
;

parte_declara_vars:  var  
                     {
                        strcpy(nome_comando, "AMEM \0");
                        sprintf(conteudo_comando, "%d", num_vars);
                        strcat(nome_comando, conteudo_comando);
                        geraCodigo(NULL, nome_comando);
                     }
;

var         : { } VAR declara_vars
            | declara_vars
;

declara_vars: declara_vars declara_var
            | declara_var
;

declara_var :  { 
                  novas_vars = 0; 
               }
               lista_id_var DOIS_PONTOS
               tipo
               PONTO_E_VIRGULA
               { 
                  num_vars += novas_vars; 
               }
;

tipo        : INTEGER
	      {
	      	adicionaTipoVariavel(&tabelaSimbolos, novas_vars, INTEIRO);
	      }
;

lista_id_var: lista_id_var VIRGULA IDENT
               { 
                  novas_vars++;
                  nodo = criaNodo(token, nivel, deslocamento);
                  insereNodoTabelaSimbolos(&tabelaSimbolos, nodo);
                  deslocamento++;
               }
               | IDENT               
               { 
                  novas_vars++;
                  nodo = criaNodo(token, nivel, deslocamento);
                  insereNodoTabelaSimbolos(&tabelaSimbolos, nodo);
                  deslocamento++;
               }
;

lista_idents: lista_idents VIRGULA IDENT
            | IDENT
;


comando_composto: T_BEGIN comandos T_END
;

comandos:   comandos comando 
            | comando
;

comando: numero_ou_regra_vazia comando_sem_rotulo
;

numero_ou_regra_vazia:   numero
              		 | regra_vazia
;

numero:  NUMERO
         {
            strcpy(nome_comando, "CRCT \0");
            strcat(nome_comando, token);
            geraCodigo(NULL, nome_comando);
	 }
;

regra_vazia:
;

comando_sem_rotulo:  atribuicao
                     | READ ABRE_PARENTESES leitura FECHA_PARENTESES PONTO_E_VIRGULA
                     | WRITE ABRE_PARENTESES impressao FECHA_PARENTESES PONTO_E_VIRGULA
                     | repeticao
;

leitura: leitura VIRGULA IDENT  
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

impressao:  impressao VIRGULA fator
            {
               geraCodigo(NULL, "IMPR");
            }
            | fator
            { 
               geraCodigo(NULL, "IMPR"); 
            } 
;

atribuicao:    variavel 
               {
                  nivel_destino = nodo->nivel;
                  deslocamento_destino = nodo->deslocamento;
               }
               ATRIBUICAO expressao 
               {
                  strcpy(nome_comando, "ARMZ \0");
                  sprintf(conteudo_comando, "%d, %d", nivel_destino, deslocamento_destino);
                  strcat(nome_comando, conteudo_comando);
                  geraCodigo(NULL, nome_comando);
               }
               PONTO_E_VIRGULA
;

variavel:   IDENT 
            {
               nodo = buscaNodoTabelaSimbolos(&tabelaSimbolos, token);
               if (!nodo) {
                  fprintf(stderr, "Erro");
                  exit(1);
               }
				}
;

expressao   :  expressao_simples MAIOR expressao_simples
               { 
                  geraCodigo (NULL, "CMMA"); 
               }
               | expressao_simples MENOR expressao_simples  
               { 
                  geraCodigo (NULL, "CMME"); 
               }
               | expressao_simples MAIOR_OU_IGUAL expressao_simples  
               { 
                  geraCodigo (NULL, "CMAG"); 
               }
               | expressao_simples MENOR_OU_IGUAL expressao_simples  
               { 
                  geraCodigo (NULL, "CMEG"); 
               }
               | expressao_simples IGUAL expressao_simples  
               { 
                  geraCodigo (NULL, "CMIG"); 
               }
               | expressao_simples
;

expressao_simples:   expressao_simples MAIS termo       
                     { 
                        geraCodigo (NULL, "SOMA"); 
                     }
                     | expressao_simples MENOS termo  
                     { 
                        geraCodigo (NULL, "SUBT"); 
                     }
                     | expressao_simples T_OR termo         
                     { 
                        geraCodigo (NULL, "DISJ"); 
                     }
                     | termo
;

termo:   fator MULTIPLICACAO fator 
         { 
            geraCodigo (NULL, "MULT"); 
         }
         | fator T_DIVISAO_INT fator       
         { 
            geraCodigo (NULL, "DIVI"); 
         }
         | fator T_AND fator           
         { 
            geraCodigo (NULL, "CONJ"); 
         }
         | fator
;

fator:   variavel
         | NUMERO  
         { 
            strcpy(nome_comando, "CRCT \0");
            strcat(nome_comando, token);
            geraCodigo(NULL, nome_comando);
         }
         | ABRE_PARENTESES expressao FECHA_PARENTESES                
         | TRUE    
         { 
            geraCodigo(NULL, "CRCT 1"); 
         }
         | FALSE   
         { 
            geraCodigo(NULL, "CRCT 0"); 
         }
         | T_NOT fator
         {
            geraCodigo(NULL, "NEGA");
         }
;

repeticao:     T_WHILE
	       {
		  identificadorRotulo = geraRotulos(rotulos);
		  if (identificadorRotulo<9){
			sprintf(nome_comando, "%s%d", "R0", identificadorRotulo);
		  } else{
			sprintf(nome_comando, "%s%d", "R", identificadorRotulo);
		  }
		  geraCodigo(nome_comando, "NADA");
	       }
	       expressao
	       {
		  identificadorRotulo = geraRotulos(rotulos);
		  if (identificadorRotulo<9){
			sprintf(nome_comando, "%s%d", "R0", identificadorRotulo);
		  } else{
			sprintf(nome_comando, "%s%d", "R", identificadorRotulo);
		  }
		  geraCodigo(NULL, nome_comando);
	       }
	       T_DO comando_composto
	       {
		  int rotulo_1 = desempilhaRotulo(rotulos);
		  int rotulo_2 = desempilhaRotulo(rotulos);
		  if (identificadorRotulo<9){
			sprintf(nome_comando, "%s%d", "R0", identificadorRotulo);
		  } else{
			sprintf(nome_comando, "%s%d", "R", identificadorRotulo);
		  }
		  geraCodigo(NULL, nome_comando);
		  if (identificadorRotulo<9){
			sprintf(nome_comando, "%s%d", "R0", identificadorRotulo);
		  } else{
			sprintf(nome_comando, "%s%d", "R", identificadorRotulo);
		  }
		  geraCodigo(NULL, nome_comando);
		}
;

// comando_repetitivo:  T_WHILE 
//                      expressao 
//                      T_DO
//                      comando_sem_rotulo
// ;

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
   novas_vars = 0;
   num_vars = 0;
   nivel = 0;
   deslocamento = 0;
   nivel_destino = 0;
   deslocamento_destino = 0;

   yyin=fp;
   yyparse();

   return 0;
}
