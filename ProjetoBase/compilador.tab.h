/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_COMPILADOR_TAB_H_INCLUDED
# define YY_YY_COMPILADOR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PROGRAM = 258,                 /* PROGRAM  */
    ABRE_PARENTESES = 259,         /* ABRE_PARENTESES  */
    FECHA_PARENTESES = 260,        /* FECHA_PARENTESES  */
    VIRGULA = 261,                 /* VIRGULA  */
    PONTO_E_VIRGULA = 262,         /* PONTO_E_VIRGULA  */
    DOIS_PONTOS = 263,             /* DOIS_PONTOS  */
    PONTO = 264,                   /* PONTO  */
    T_BEGIN = 265,                 /* T_BEGIN  */
    T_END = 266,                   /* T_END  */
    VAR = 267,                     /* VAR  */
    IDENT = 268,                   /* IDENT  */
    ATRIBUICAO = 269,              /* ATRIBUICAO  */
    T_LABEL = 270,                 /* T_LABEL  */
    T_TYPE = 271,                  /* T_TYPE  */
    T_IF = 272,                    /* T_IF  */
    NUMERO = 273,                  /* NUMERO  */
    T_ARRAY = 274,                 /* T_ARRAY  */
    T_PROCEDURE = 275,             /* T_PROCEDURE  */
    T_FUNCTION = 276,              /* T_FUNCTION  */
    T_GOTO = 277,                  /* T_GOTO  */
    MENOR = 278,                   /* MENOR  */
    T_THEN = 279,                  /* T_THEN  */
    T_ELSE = 280,                  /* T_ELSE  */
    T_WHILE = 281,                 /* T_WHILE  */
    T_DO = 282,                    /* T_DO  */
    T_OR = 283,                    /* T_OR  */
    T_DIVISAO_INT = 284,           /* T_DIVISAO_INT  */
    T_AND = 285,                   /* T_AND  */
    T_NOT = 286,                   /* T_NOT  */
    READ = 287,                    /* READ  */
    WRITE = 288,                   /* WRITE  */
    INTEGER = 289,                 /* INTEGER  */
    BOOLEAN = 290,                 /* BOOLEAN  */
    TRUE = 291,                    /* TRUE  */
    FALSE = 292,                   /* FALSE  */
    OF = 293,                      /* OF  */
    REPEAT = 294,                  /* REPEAT  */
    UNTIL = 295,                   /* UNTIL  */
    MAIS = 296,                    /* MAIS  */
    MENOS = 297,                   /* MENOS  */
    MULTIPLICACAO = 298,           /* MULTIPLICACAO  */
    MAIOR = 299,                   /* MAIOR  */
    MENOR_OU_IGUAL = 300,          /* MENOR_OU_IGUAL  */
    MAIOR_OU_IGUAL = 301,          /* MAIOR_OU_IGUAL  */
    DIFERENTE = 302,               /* DIFERENTE  */
    IGUAL = 303,                   /* IGUAL  */
    T_DIVISAO_real = 304,          /* T_DIVISAO_real  */
    ABRE_COLCHETES = 305,          /* ABRE_COLCHETES  */
    FECHA_COLCHETES = 306          /* FECHA_COLCHETES  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_COMPILADOR_TAB_H_INCLUDED  */
