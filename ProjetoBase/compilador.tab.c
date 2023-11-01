/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "compilador.y"

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


#line 96 "compilador.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "compilador.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_ABRE_PARENTESES = 4,            /* ABRE_PARENTESES  */
  YYSYMBOL_FECHA_PARENTESES = 5,           /* FECHA_PARENTESES  */
  YYSYMBOL_VIRGULA = 6,                    /* VIRGULA  */
  YYSYMBOL_PONTO_E_VIRGULA = 7,            /* PONTO_E_VIRGULA  */
  YYSYMBOL_DOIS_PONTOS = 8,                /* DOIS_PONTOS  */
  YYSYMBOL_PONTO = 9,                      /* PONTO  */
  YYSYMBOL_T_BEGIN = 10,                   /* T_BEGIN  */
  YYSYMBOL_T_END = 11,                     /* T_END  */
  YYSYMBOL_VAR = 12,                       /* VAR  */
  YYSYMBOL_IDENT = 13,                     /* IDENT  */
  YYSYMBOL_ATRIBUICAO = 14,                /* ATRIBUICAO  */
  YYSYMBOL_T_LABEL = 15,                   /* T_LABEL  */
  YYSYMBOL_T_TYPE = 16,                    /* T_TYPE  */
  YYSYMBOL_T_IF = 17,                      /* T_IF  */
  YYSYMBOL_NUMERO = 18,                    /* NUMERO  */
  YYSYMBOL_T_ARRAY = 19,                   /* T_ARRAY  */
  YYSYMBOL_T_PROCEDURE = 20,               /* T_PROCEDURE  */
  YYSYMBOL_T_FUNCTION = 21,                /* T_FUNCTION  */
  YYSYMBOL_T_GOTO = 22,                    /* T_GOTO  */
  YYSYMBOL_MENOR = 23,                     /* MENOR  */
  YYSYMBOL_T_THEN = 24,                    /* T_THEN  */
  YYSYMBOL_T_ELSE = 25,                    /* T_ELSE  */
  YYSYMBOL_T_WHILE = 26,                   /* T_WHILE  */
  YYSYMBOL_T_DO = 27,                      /* T_DO  */
  YYSYMBOL_T_OR = 28,                      /* T_OR  */
  YYSYMBOL_T_DIVISAO_INT = 29,             /* T_DIVISAO_INT  */
  YYSYMBOL_T_AND = 30,                     /* T_AND  */
  YYSYMBOL_T_NOT = 31,                     /* T_NOT  */
  YYSYMBOL_READ = 32,                      /* READ  */
  YYSYMBOL_WRITE = 33,                     /* WRITE  */
  YYSYMBOL_INTEGER = 34,                   /* INTEGER  */
  YYSYMBOL_BOOLEAN = 35,                   /* BOOLEAN  */
  YYSYMBOL_TRUE = 36,                      /* TRUE  */
  YYSYMBOL_FALSE = 37,                     /* FALSE  */
  YYSYMBOL_OF = 38,                        /* OF  */
  YYSYMBOL_REPEAT = 39,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 40,                     /* UNTIL  */
  YYSYMBOL_MAIS = 41,                      /* MAIS  */
  YYSYMBOL_MENOS = 42,                     /* MENOS  */
  YYSYMBOL_MULTIPLICACAO = 43,             /* MULTIPLICACAO  */
  YYSYMBOL_MAIOR = 44,                     /* MAIOR  */
  YYSYMBOL_MENOR_OU_IGUAL = 45,            /* MENOR_OU_IGUAL  */
  YYSYMBOL_MAIOR_OU_IGUAL = 46,            /* MAIOR_OU_IGUAL  */
  YYSYMBOL_DIFERENTE = 47,                 /* DIFERENTE  */
  YYSYMBOL_IGUAL = 48,                     /* IGUAL  */
  YYSYMBOL_T_DIVISAO_real = 49,            /* T_DIVISAO_real  */
  YYSYMBOL_ABRE_COLCHETES = 50,            /* ABRE_COLCHETES  */
  YYSYMBOL_FECHA_COLCHETES = 51,           /* FECHA_COLCHETES  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_programa = 53,                  /* programa  */
  YYSYMBOL_54_1 = 54,                      /* $@1  */
  YYSYMBOL_bloco = 55,                     /* bloco  */
  YYSYMBOL_56_2 = 56,                      /* $@2  */
  YYSYMBOL_parte_declara_vars = 57,        /* parte_declara_vars  */
  YYSYMBOL_var = 58,                       /* var  */
  YYSYMBOL_59_3 = 59,                      /* $@3  */
  YYSYMBOL_declara_vars = 60,              /* declara_vars  */
  YYSYMBOL_declara_var = 61,               /* declara_var  */
  YYSYMBOL_62_4 = 62,                      /* $@4  */
  YYSYMBOL_tipo = 63,                      /* tipo  */
  YYSYMBOL_lista_id_var = 64,              /* lista_id_var  */
  YYSYMBOL_lista_idents = 65,              /* lista_idents  */
  YYSYMBOL_comando_composto = 66,          /* comando_composto  */
  YYSYMBOL_comandos = 67,                  /* comandos  */
  YYSYMBOL_comando = 68,                   /* comando  */
  YYSYMBOL_numero_ou_regra_vazia = 69,     /* numero_ou_regra_vazia  */
  YYSYMBOL_numero = 70,                    /* numero  */
  YYSYMBOL_regra_vazia = 71,               /* regra_vazia  */
  YYSYMBOL_comando_sem_rotulo = 72,        /* comando_sem_rotulo  */
  YYSYMBOL_leitura = 73,                   /* leitura  */
  YYSYMBOL_impressao = 74,                 /* impressao  */
  YYSYMBOL_atribuicao = 75,                /* atribuicao  */
  YYSYMBOL_76_5 = 76,                      /* $@5  */
  YYSYMBOL_77_6 = 77,                      /* $@6  */
  YYSYMBOL_variavel = 78,                  /* variavel  */
  YYSYMBOL_expressao = 79,                 /* expressao  */
  YYSYMBOL_expressao_simples = 80,         /* expressao_simples  */
  YYSYMBOL_termo = 81,                     /* termo  */
  YYSYMBOL_fator = 82,                     /* fator  */
  YYSYMBOL_repeticao = 83,                 /* repeticao  */
  YYSYMBOL_84_7 = 84,                      /* $@7  */
  YYSYMBOL_85_8 = 85                       /* $@8  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   98

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  109

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    40,    40,    40,    58,    57,    63,    72,    72,    73,
      76,    77,    80,    80,    91,    97,   104,   113,   114,   118,
     121,   122,   125,   128,   129,   132,   140,   143,   144,   145,
     146,   149,   158,   169,   173,   180,   185,   179,   194,   204,
     208,   212,   216,   220,   224,   227,   231,   235,   239,   242,
     246,   250,   254,   257,   258,   264,   265,   269,   273,   280,
     290,   279
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM",
  "ABRE_PARENTESES", "FECHA_PARENTESES", "VIRGULA", "PONTO_E_VIRGULA",
  "DOIS_PONTOS", "PONTO", "T_BEGIN", "T_END", "VAR", "IDENT", "ATRIBUICAO",
  "T_LABEL", "T_TYPE", "T_IF", "NUMERO", "T_ARRAY", "T_PROCEDURE",
  "T_FUNCTION", "T_GOTO", "MENOR", "T_THEN", "T_ELSE", "T_WHILE", "T_DO",
  "T_OR", "T_DIVISAO_INT", "T_AND", "T_NOT", "READ", "WRITE", "INTEGER",
  "BOOLEAN", "TRUE", "FALSE", "OF", "REPEAT", "UNTIL", "MAIS", "MENOS",
  "MULTIPLICACAO", "MAIOR", "MENOR_OU_IGUAL", "MAIOR_OU_IGUAL",
  "DIFERENTE", "IGUAL", "T_DIVISAO_real", "ABRE_COLCHETES",
  "FECHA_COLCHETES", "$accept", "programa", "$@1", "bloco", "$@2",
  "parte_declara_vars", "var", "$@3", "declara_vars", "declara_var", "$@4",
  "tipo", "lista_id_var", "lista_idents", "comando_composto", "comandos",
  "comando", "numero_ou_regra_vazia", "numero", "regra_vazia",
  "comando_sem_rotulo", "leitura", "impressao", "atribuicao", "$@5", "$@6",
  "variavel", "expressao", "expressao_simples", "termo", "fator",
  "repeticao", "$@7", "$@8", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-13)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -67,     6,    28,   -67,    23,    48,    43,   -67,    34,    50,
      46,    47,   -67,    52,   -67,   -67,    51,    47,   -67,    53,
     -67,    54,   -67,   -67,   -67,    45,    44,   -67,    47,    55,
      24,   -67,     0,   -67,     9,   -67,   -67,   -67,   -67,    58,
     -67,   -67,   -67,   -67,    63,    65,   -67,   -67,   -67,   -67,
     -67,     1,    57,     1,    59,     1,   -67,     1,   -67,   -67,
     -67,   -67,   -21,   -67,   -17,   -67,    40,    49,   -67,     1,
      66,   -67,    56,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,    67,    62,    69,     1,   -67,   -67,
      54,   -25,   -67,   -67,   -67,   -25,   -25,   -25,   -25,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,    70,   -67,   -67
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,    18,     0,     0,
       0,     7,    17,     0,     4,     6,     0,     9,    11,     0,
       3,     0,    12,    10,    16,     0,    26,     5,     8,     0,
       0,    25,    26,    21,     0,    23,    24,    15,    14,     0,
      19,    20,    38,    59,     0,     0,    22,    27,    35,    30,
      13,     0,     0,     0,     0,     0,    54,     0,    56,    57,
      53,    60,    44,    48,    52,    32,     0,     0,    34,     0,
       0,    58,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,    55,
       0,    40,    47,    45,    46,    39,    42,    41,    43,    50,
      51,    49,    28,    31,    29,    33,     0,    61,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,    60,    16,
     -67,   -67,   -67,   -67,   -18,   -67,    61,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,    64,   -54,   -30,   -66,
     -53,   -67,   -67,   -67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    13,    21,    14,    15,    16,    17,    18,
      19,    39,    25,     8,    27,    32,    33,    34,    35,    36,
      46,    66,    67,    47,    54,   106,    60,    61,    62,    63,
      64,    49,    51,    72
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      68,    70,    73,    74,    71,    55,     3,    74,    92,    93,
      94,    40,    81,    82,    42,    88,    75,    76,    31,    56,
      75,    76,    42,    77,    78,    79,    83,    80,    99,   100,
     101,     4,    57,    23,   105,    43,     5,    58,    59,     9,
      10,    44,    45,    91,    23,    84,    85,    95,    96,    97,
      98,    29,     6,    30,    86,    87,     7,    11,    38,    12,
     -12,    20,    31,    22,    26,    50,    24,    52,    37,    53,
      65,    89,   107,    69,   102,   103,   104,   108,     0,     0,
       0,     0,    28,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,     0,    48
};

static const yytype_int8 yycheck[] =
{
      53,    55,    23,    28,    57,     4,     0,    28,    74,    75,
      76,    11,    29,    30,    13,    69,    41,    42,    18,    18,
      41,    42,    13,    44,    45,    46,    43,    48,    81,    82,
      83,     3,    31,    17,    87,    26,    13,    36,    37,     5,
       6,    32,    33,    73,    28,     5,     6,    77,    78,    79,
      80,     6,     4,     8,     5,     6,    13,     7,    34,    13,
      13,     9,    18,    12,    10,     7,    13,     4,    13,     4,
      13,     5,    90,    14,     7,    13,     7,     7,    -1,    -1,
      -1,    -1,    22,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    53,    54,     0,     3,    13,     4,    13,    65,     5,
       6,     7,    13,    55,    57,    58,    59,    60,    61,    62,
       9,    56,    12,    61,    13,    64,    10,    66,    60,     6,
       8,    18,    67,    68,    69,    70,    71,    13,    34,    63,
      11,    68,    13,    26,    32,    33,    72,    75,    78,    83,
       7,    84,     4,     4,    76,     4,    18,    31,    36,    37,
      78,    79,    80,    81,    82,    13,    73,    74,    82,    14,
      79,    82,    85,    23,    28,    41,    42,    44,    45,    46,
      48,    29,    30,    43,     5,     6,     5,     6,    79,     5,
      27,    80,    81,    81,    81,    80,    80,    80,    80,    82,
      82,    82,     7,    13,     7,    82,    77,    66,     7
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    54,    53,    56,    55,    57,    59,    58,    58,
      60,    60,    62,    61,    63,    64,    64,    65,    65,    66,
      67,    67,    68,    69,    69,    70,    71,    72,    72,    72,
      72,    73,    73,    74,    74,    76,    77,    75,    78,    79,
      79,    79,    79,    79,    79,    80,    80,    80,    80,    81,
      81,    81,    81,    82,    82,    82,    82,    82,    82,    84,
      85,    83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     9,     0,     3,     1,     0,     3,     1,
       2,     1,     0,     5,     1,     3,     1,     3,     1,     3,
       2,     1,     2,     1,     1,     1,     0,     1,     5,     5,
       1,     3,     1,     3,     1,     0,     0,     6,     1,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     3,     1,     1,     1,     3,     1,     1,     2,     0,
       0,     6
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 40 "compilador.y"
               {
                  geraCodigo (NULL, "INPP");
                  inicioRotulos = geraRotulos(rotulos);
               }
#line 1248 "compilador.tab.c"
    break;

  case 3: /* programa: $@1 PROGRAM IDENT ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA bloco PONTO  */
#line 47 "compilador.y"
               { 
                  removeNodoTabelaSimbolos(&tabelaSimbolos, num_vars);
                  strcpy(nome_comando, "DMEM \0");
                  sprintf(conteudo_comando, "%d", num_vars);
                  strcat(nome_comando, conteudo_comando);
                  geraCodigo(NULL, nome_comando);
                  geraCodigo (NULL, "PARA");
               }
#line 1261 "compilador.tab.c"
    break;

  case 4: /* $@2: %empty  */
#line 58 "compilador.y"
            {
	    }
#line 1268 "compilador.tab.c"
    break;

  case 6: /* parte_declara_vars: var  */
#line 64 "compilador.y"
                     {
                        strcpy(nome_comando, "AMEM \0");
                        sprintf(conteudo_comando, "%d", num_vars);
                        strcat(nome_comando, conteudo_comando);
                        geraCodigo(NULL, nome_comando);
                     }
#line 1279 "compilador.tab.c"
    break;

  case 7: /* $@3: %empty  */
#line 72 "compilador.y"
              { }
#line 1285 "compilador.tab.c"
    break;

  case 12: /* $@4: %empty  */
#line 80 "compilador.y"
               { 
                  novas_vars = 0; 
               }
#line 1293 "compilador.tab.c"
    break;

  case 13: /* declara_var: $@4 lista_id_var DOIS_PONTOS tipo PONTO_E_VIRGULA  */
#line 86 "compilador.y"
               { 
                  num_vars += novas_vars; 
               }
#line 1301 "compilador.tab.c"
    break;

  case 14: /* tipo: INTEGER  */
#line 92 "compilador.y"
              {
	      	adicionaTipoVariavel(&tabelaSimbolos, novas_vars, INTEIRO);
	      }
#line 1309 "compilador.tab.c"
    break;

  case 15: /* lista_id_var: lista_id_var VIRGULA IDENT  */
#line 98 "compilador.y"
               { 
                  novas_vars++;
                  nodo = criaNodo(token, nivel, deslocamento);
                  insereNodoTabelaSimbolos(&tabelaSimbolos, nodo);
                  deslocamento++;
               }
#line 1320 "compilador.tab.c"
    break;

  case 16: /* lista_id_var: IDENT  */
#line 105 "compilador.y"
               { 
                  novas_vars++;
                  nodo = criaNodo(token, nivel, deslocamento);
                  insereNodoTabelaSimbolos(&tabelaSimbolos, nodo);
                  deslocamento++;
               }
#line 1331 "compilador.tab.c"
    break;

  case 25: /* numero: NUMERO  */
#line 133 "compilador.y"
         {
            strcpy(nome_comando, "CRCT \0");
            strcat(nome_comando, token);
            geraCodigo(NULL, nome_comando);
	 }
#line 1341 "compilador.tab.c"
    break;

  case 31: /* leitura: leitura VIRGULA IDENT  */
#line 150 "compilador.y"
            { 
               geraCodigo(NULL, "LEIT"); 
               nodo = buscaNodoTabelaSimbolos(&tabelaSimbolos, token); 
               strcpy(nome_comando, "ARMZ \0");
               sprintf(conteudo_comando, "%d, %d", nivel_destino, deslocamento_destino);
               strcat(nome_comando, conteudo_comando);
               geraCodigo(NULL, nome_comando);
            }
#line 1354 "compilador.tab.c"
    break;

  case 32: /* leitura: IDENT  */
#line 159 "compilador.y"
            { 
               geraCodigo(NULL, "LEIT"); 
               nodo = buscaNodoTabelaSimbolos(&tabelaSimbolos, token); 
               strcpy(nome_comando, "ARMZ \0");
               sprintf(conteudo_comando, "%d, %d", nivel_destino, deslocamento_destino);
               strcat(nome_comando, conteudo_comando);
               geraCodigo(NULL, nome_comando);
            }
#line 1367 "compilador.tab.c"
    break;

  case 33: /* impressao: impressao VIRGULA fator  */
#line 170 "compilador.y"
            {
               geraCodigo(NULL, "IMPR");
            }
#line 1375 "compilador.tab.c"
    break;

  case 34: /* impressao: fator  */
#line 174 "compilador.y"
            { 
               geraCodigo(NULL, "IMPR"); 
            }
#line 1383 "compilador.tab.c"
    break;

  case 35: /* $@5: %empty  */
#line 180 "compilador.y"
               {
                  nivel_destino = nodo->nivel;
                  deslocamento_destino = nodo->deslocamento;
               }
#line 1392 "compilador.tab.c"
    break;

  case 36: /* $@6: %empty  */
#line 185 "compilador.y"
               {
                  strcpy(nome_comando, "ARMZ \0");
                  sprintf(conteudo_comando, "%d, %d", nivel_destino, deslocamento_destino);
                  strcat(nome_comando, conteudo_comando);
                  geraCodigo(NULL, nome_comando);
               }
#line 1403 "compilador.tab.c"
    break;

  case 38: /* variavel: IDENT  */
#line 195 "compilador.y"
            {
               nodo = buscaNodoTabelaSimbolos(&tabelaSimbolos, token);
               if (!nodo) {
                  fprintf(stderr, "Erro");
                  exit(1);
               }
				}
#line 1415 "compilador.tab.c"
    break;

  case 39: /* expressao: expressao_simples MAIOR expressao_simples  */
#line 205 "compilador.y"
               { 
                  geraCodigo (NULL, "CMMA"); 
               }
#line 1423 "compilador.tab.c"
    break;

  case 40: /* expressao: expressao_simples MENOR expressao_simples  */
#line 209 "compilador.y"
               { 
                  geraCodigo (NULL, "CMME"); 
               }
#line 1431 "compilador.tab.c"
    break;

  case 41: /* expressao: expressao_simples MAIOR_OU_IGUAL expressao_simples  */
#line 213 "compilador.y"
               { 
                  geraCodigo (NULL, "CMAG"); 
               }
#line 1439 "compilador.tab.c"
    break;

  case 42: /* expressao: expressao_simples MENOR_OU_IGUAL expressao_simples  */
#line 217 "compilador.y"
               { 
                  geraCodigo (NULL, "CMEG"); 
               }
#line 1447 "compilador.tab.c"
    break;

  case 43: /* expressao: expressao_simples IGUAL expressao_simples  */
#line 221 "compilador.y"
               { 
                  geraCodigo (NULL, "CMIG"); 
               }
#line 1455 "compilador.tab.c"
    break;

  case 45: /* expressao_simples: expressao_simples MAIS termo  */
#line 228 "compilador.y"
                     { 
                        geraCodigo (NULL, "SOMA"); 
                     }
#line 1463 "compilador.tab.c"
    break;

  case 46: /* expressao_simples: expressao_simples MENOS termo  */
#line 232 "compilador.y"
                     { 
                        geraCodigo (NULL, "SUBT"); 
                     }
#line 1471 "compilador.tab.c"
    break;

  case 47: /* expressao_simples: expressao_simples T_OR termo  */
#line 236 "compilador.y"
                     { 
                        geraCodigo (NULL, "DISJ"); 
                     }
#line 1479 "compilador.tab.c"
    break;

  case 49: /* termo: fator MULTIPLICACAO fator  */
#line 243 "compilador.y"
         { 
            geraCodigo (NULL, "MULT"); 
         }
#line 1487 "compilador.tab.c"
    break;

  case 50: /* termo: fator T_DIVISAO_INT fator  */
#line 247 "compilador.y"
         { 
            geraCodigo (NULL, "DIVI"); 
         }
#line 1495 "compilador.tab.c"
    break;

  case 51: /* termo: fator T_AND fator  */
#line 251 "compilador.y"
         { 
            geraCodigo (NULL, "CONJ"); 
         }
#line 1503 "compilador.tab.c"
    break;

  case 54: /* fator: NUMERO  */
#line 259 "compilador.y"
         { 
            strcpy(nome_comando, "CRCT \0");
            strcat(nome_comando, token);
            geraCodigo(NULL, nome_comando);
         }
#line 1513 "compilador.tab.c"
    break;

  case 56: /* fator: TRUE  */
#line 266 "compilador.y"
         { 
            geraCodigo(NULL, "CRCT 1"); 
         }
#line 1521 "compilador.tab.c"
    break;

  case 57: /* fator: FALSE  */
#line 270 "compilador.y"
         { 
            geraCodigo(NULL, "CRCT 0"); 
         }
#line 1529 "compilador.tab.c"
    break;

  case 58: /* fator: T_NOT fator  */
#line 274 "compilador.y"
         {
            geraCodigo(NULL, "NEGA");
         }
#line 1537 "compilador.tab.c"
    break;

  case 59: /* $@7: %empty  */
#line 280 "compilador.y"
               {
		  identificadorRotulo = geraRotulos(rotulos);
		  if (identificadorRotulo<9){
			sprintf(nome_comando, "%s%d", "R0", identificadorRotulo);
		  } else{
			sprintf(nome_comando, "%s%d", "R", identificadorRotulo);
		  }
		  geraCodigo(nome_comando, "NADA");
	       }
#line 1551 "compilador.tab.c"
    break;

  case 60: /* $@8: %empty  */
#line 290 "compilador.y"
               {
		  identificadorRotulo = geraRotulos(rotulos);
		  if (identificadorRotulo<9){
			sprintf(nome_comando, "%s%d", "R0", identificadorRotulo);
		  } else{
			sprintf(nome_comando, "%s%d", "R", identificadorRotulo);
		  }
		  geraCodigo(NULL, nome_comando);
	       }
#line 1565 "compilador.tab.c"
    break;

  case 61: /* repeticao: T_WHILE $@7 expressao $@8 T_DO comando_composto  */
#line 300 "compilador.y"
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
#line 1586 "compilador.tab.c"
    break;


#line 1590 "compilador.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 324 "compilador.y"


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
