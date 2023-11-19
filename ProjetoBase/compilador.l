%{


#include<stdio.h>
#include<string.h>

#include "compilador.h"
#include "compilador.tab.h"

//#define IMPRIME(STR) {};
#define IMPRIME(STR) printf("%s    # %s \n", STR, token);

int nl = 1;

%}

pulo_linha [\n]

descarte [\t ]+

ident [a-zA-Z][a-zA-Z0-9]*

numero [0-9]+

comentario "(*".*"*)"

%%

{pulo_linha} {nl++;}

{descarte}

{comentario}

program { simbolo  = simb_program;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("program ");
          return PROGRAM;
 }

var      { simbolo = simb_var;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("var  ");
          return VAR;
 }

begin { simbolo = simb_begin;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("begin ");
          return T_BEGIN;
 }

end { simbolo = simb_end;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("end  ");
          return T_END;
 }

label { simbolo = simb_label;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("label  ");
          return T_LABEL;
 }

type { simbolo = simb_type;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("type  ");
          return T_TYPE;
 }

array { simbolo = simb_array;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("array  ");
          return T_ARRAY;
 }

procedure { simbolo = simb_procedure;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("procedure  ");
          return T_PROCEDURE;
 }

function { simbolo = simb_function;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("function  ");
          return T_FUNCTION;
 }

goto { simbolo = simb_goto;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("goto  ");
          return T_GOTO;
 }

if { simbolo = simb_if;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("if  ");
          return T_IF;
 }

then { simbolo = simb_then;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("then  ");
          return T_THEN;
 }

else { simbolo = simb_else;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("else  ");
          return T_ELSE;
 }

while { simbolo = simb_while;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" while ");
          return T_WHILE;
 }

do { simbolo = simb_do;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" do ");
          return T_DO;
 }

or { simbolo = simb_or;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("or  ");
          return T_OR;
 }

div { simbolo = simb_divisao_int;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("divisao_int  ");
          return T_DIVISAO_INT;
 }

and { simbolo = simb_and;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("and  ");
          return T_AND;
 }

not { simbolo = simb_not;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("not  ");
          return T_NOT;
 }

read { simbolo = simb_read;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" read");
          return READ;
}

write { simbolo = simb_write;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" write");
          return WRITE;
}

true { simbolo = simb_true;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" true");
          return TRUE;
}

false { simbolo = simb_false;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" false");
          return FALSE;
}

of  { simbolo = simb_of;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" of ");
          return OF;
}

repeat { simbolo = simb_repete;
        strncpy (token, yytext, TAM_TOKEN);
        return REPEAT;
}

until { simbolo = simb_ate;
       strncpy (token, yytext, TAM_TOKEN);
       return UNTIL;
}

:= { simbolo = simb_atribuicao;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" atribuicao  ");
          return ATRIBUICAO;
 }

\; { simbolo = simb_ponto_e_virgula;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" pt_virgula  ");
          return PONTO_E_VIRGULA;
 }

\: { simbolo = simb_dois_pontos;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" dois pontos ");
          return DOIS_PONTOS;
 }

\, { simbolo = simb_virgula;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" virgula  ");
          return VIRGULA;
 }


\. { simbolo = simb_ponto;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" ponto  ");
          return PONTO;
    }

\(  { simbolo = simb_abre_parenteses;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" abre_parenteses  ");
          return ABRE_PARENTESES;
    }

\)  { simbolo = simb_fecha_parenteses;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" fecha_parenteses ");
          return FECHA_PARENTESES;
 }

\+  { simbolo = simb_mais;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" mais ");
          return MAIS;
 }

\-  { simbolo = simb_menos;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" menos ");
          return MENOS;
 }

\*  { simbolo = simb_multiplicacao;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" multiplicacao ");
          return MULTIPLICACAO;
 }

\>  { simbolo = simb_maior;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" maior ");
          return MAIOR;
 }

\<  { simbolo = simb_menor;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" menor ");
          return MENOR;
 }

\>=  { simbolo = simb_maior_ou_igual;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" maior_ou_igual ");
          return MAIOR_OU_IGUAL;
 }

\<=  { simbolo = simb_menor_ou_igual;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" menor_ou_igual ");
          return MENOR_OU_IGUAL;
 }

\<>  { simbolo = simb_diferente;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" diferente ");
          return DIFERENTE;
 }

\=   { simbolo = simb_igual;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" igual ");
          return IGUAL;
 }

\/ { simbolo = simb_div_real;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" div_real ");
          return T_DIVISAO_real;
}

\[ { simbolo = simb_abre_colchetes;
          strncpy(token, yytext, TAM_TOKEN);
          IMPRIME(" abre_colchetes ");
          return ABRE_COLCHETES;
}

\]   { simbolo = simb_fecha_colchetes;
          strncpy(token, yytext, TAM_TOKEN);
          IMPRIME(" fecha_colchetes ");
          return FECHA_COLCHETES;
}

{numero} { simbolo = simb_numero;
  strncpy (token, yytext, TAM_TOKEN);
  IMPRIME(" numero");
  return NUMERO;
}

{ident} { simbolo = simb_identificador;
  strncpy (token, yytext, TAM_TOKEN);
  IMPRIME(" ident  ");
  return IDENT;
}


%%
