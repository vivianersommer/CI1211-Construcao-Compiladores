%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "tabelaSimbolos.h"


TabelaSimbolos tabelaSimbolos;
NodoSimbolo* nodo;
int num_vars, novas_vars, nivel, deslocamento;
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
               }
               PROGRAM IDENT
               ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
               bloco PONTO 
               { 
                  remove_nodo(&tabelaSimbolos, num_vars);
                  strcpy(nome_comando, "DMEM \0");
                  sprintf(conteudo_comando, "%d", num_vars);
                  strcat(nome_comando, conteudo_comando);
                  geraCodigo(NULL, nome_comando);
                  geraCodigo (NULL, "PARA");
               }
;

bloco       :parte_declara_vars{}
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
;

lista_id_var: lista_id_var VIRGULA IDENT
               { 
                  novas_vars++;
                  nodo = cria_nodo(token, nivel, deslocamento);
                  insereTabelaSimbolos(&tabelaSimbolos, nodo);
                  deslocamento++;
               }
            | IDENT               
               { 
                  novas_vars++;
                  nodo = cria_nodo(token, nivel, deslocamento);
                  insereTabelaSimbolos(&tabelaSimbolos, nodo);
                  deslocamento++;
               }
;

lista_idents: lista_idents VIRGULA IDENT
            | IDENT
;


comando_composto: T_BEGIN comandos T_END

comandos:
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
/* -------------------------------------------------------------------*/

/* Inicia variaveis globais ------------------------------------------*/
   novas_vars = 0;
   num_vars = 0;
   nivel = 0;
   deslocamento = 0;
/* -------------------------------------------------------------------*/

   yyin=fp;
   yyparse();

   return 0;
}
