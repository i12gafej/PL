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
#line 7 "interpreter.y"

#include <iostream>
#include <string>
#include <sstream>

/*******************************************/
/* NEW in example 5 */
/* pow */
#include <math.h>
/*******************************************/

/*******************************************/
/* NEW in example 6 */
/* Use for recovery of runtime errors */
#include <setjmp.h>
#include <signal.h>
/*******************************************/

/* Error recovery functions */
#include "../error/error.hpp"

/* Macros for the screen */
#include "../includes/macros.hpp"


/*******************************************/
/* 
  NEW in example 16
  AST class
  IMPORTANT: this file must be before init.hpp
*/
#include "../ast/ast.hpp"


/*******************************************/
/* NEW in example 7 */
/* Table of symbol */
#include "../table/table.hpp"
/*******************************************/

/*******************************************/
#include "../table/numericVariable.hpp"
/*******************************************/

/* NEW in example 15 */
#include "../table/logicalVariable.hpp"

/*******************************************/
/* NEW in example 11 */
#include "../table/numericConstant.hpp"
/*******************************************/

/*******************************************/
/* NEW in example 15 */
#include "../table/logicalConstant.hpp"
/*******************************************/

/*******************************************/
/* NUEVO DE LA ULTIMA PRACTICA */
#include "../table/StringVariable.hpp"
#include "../table/StringConstant.hpp"
/*******************************************/

/*******************************************/
/* NEW in example 13 */
#include "../table/builtinParameter1.hpp"
/*******************************************/

/*******************************************/
/* NEW in example 14 */
#include "../table/builtinParameter0.hpp"
#include "../table/builtinParameter2.hpp"
/*******************************************/


/*******************************************/
/* NEW in example 10 */
#include "../table/init.hpp"
/*******************************************/

/*! 
	\brief  Lexical or scanner function
	\return int
	\note   C++ requires that yylex returns an int value
	\sa     yyparser
*/
int yylex();


extern int lineNumber; //!< External line counter


/* NEW in example 15 */
extern bool interactiveMode; //!< Control the interactive mode of execution of the interpreter

/* New in example 17 */
extern int control; //!< External: to control the interactive mode in "if" and "while" sentences 




/***********************************************************/
/* NEW in example 2 */
extern std::string progname; //!<  Program name
/***********************************************************/

/*******************************************/
/* NEW in example 6 */
/*
 jhmp_buf
    This is an array type capable of storing the information of a calling environment to be restored later.
   This information is filled by calling macro setjmp and can be restored by calling function longjmp.
*/
jmp_buf begin; //!<  It enables recovery of runtime errors 
/*******************************************/


/*******************************************/
/* NEW in example 7 */
extern lp::Table table; //!< Extern Table of Symbols

/*******************************************/
/* NEW in example 16 */
extern lp::AST *root; //!< External root of the abstract syntax tree AST


#line 198 "interpreter.tab.c"

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

#include "interpreter.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_COLON = 4,                      /* COLON  */
  YYSYMBOL_ALT = 5,                        /* ALT  */
  YYSYMBOL_COMMENT = 6,                    /* COMMENT  */
  YYSYMBOL_PRINT = 7,                      /* PRINT  */
  YYSYMBOL_READ = 8,                       /* READ  */
  YYSYMBOL_READ_STRING = 9,                /* READ_STRING  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_THEN = 13,                      /* THEN  */
  YYSYMBOL_END_IF = 14,                    /* END_IF  */
  YYSYMBOL_END_WHILE = 15,                 /* END_WHILE  */
  YYSYMBOL_REPEAT = 16,                    /* REPEAT  */
  YYSYMBOL_FOR = 17,                       /* FOR  */
  YYSYMBOL_FROM = 18,                      /* FROM  */
  YYSYMBOL_UNTIL = 19,                     /* UNTIL  */
  YYSYMBOL_END_FOR = 20,                   /* END_FOR  */
  YYSYMBOL_STEP = 21,                      /* STEP  */
  YYSYMBOL_CASES = 22,                     /* CASES  */
  YYSYMBOL_VALUE = 23,                     /* VALUE  */
  YYSYMBOL_DEFAULT = 24,                   /* DEFAULT  */
  YYSYMBOL_END_CASES = 25,                 /* END_CASES  */
  YYSYMBOL_DO = 26,                        /* DO  */
  YYSYMBOL_CLEAR = 27,                     /* CLEAR  */
  YYSYMBOL_PLACE = 28,                     /* PLACE  */
  YYSYMBOL_LETFCURLYBRACKET = 29,          /* LETFCURLYBRACKET  */
  YYSYMBOL_RIGHTCURLYBRACKET = 30,         /* RIGHTCURLYBRACKET  */
  YYSYMBOL_ASSIGNMENT = 31,                /* ASSIGNMENT  */
  YYSYMBOL_PLUS_ASSIGNMENT = 32,           /* PLUS_ASSIGNMENT  */
  YYSYMBOL_MINUS_ASSIGNMENT = 33,          /* MINUS_ASSIGNMENT  */
  YYSYMBOL_MULTIPLICATION_ASSIGNMENT = 34, /* MULTIPLICATION_ASSIGNMENT  */
  YYSYMBOL_DIVISION_ASSIGNMENT = 35,       /* DIVISION_ASSIGNMENT  */
  YYSYMBOL_INT_DIVISION_ASSIGNMENT = 36,   /* INT_DIVISION_ASSIGNMENT  */
  YYSYMBOL_MODULO_ASSIGNMENT = 37,         /* MODULO_ASSIGNMENT  */
  YYSYMBOL_POWER_ASSIGNMENT = 38,          /* POWER_ASSIGNMENT  */
  YYSYMBOL_COMMA = 39,                     /* COMMA  */
  YYSYMBOL_STRING = 40,                    /* STRING  */
  YYSYMBOL_NUMBER = 41,                    /* NUMBER  */
  YYSYMBOL_BOOL = 42,                      /* BOOL  */
  YYSYMBOL_VARIABLE = 43,                  /* VARIABLE  */
  YYSYMBOL_UNDEFINED = 44,                 /* UNDEFINED  */
  YYSYMBOL_CONSTANT = 45,                  /* CONSTANT  */
  YYSYMBOL_BUILTIN = 46,                   /* BUILTIN  */
  YYSYMBOL_OR = 47,                        /* OR  */
  YYSYMBOL_AND = 48,                       /* AND  */
  YYSYMBOL_GREATER_OR_EQUAL = 49,          /* GREATER_OR_EQUAL  */
  YYSYMBOL_LESS_OR_EQUAL = 50,             /* LESS_OR_EQUAL  */
  YYSYMBOL_GREATER_THAN = 51,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN = 52,                 /* LESS_THAN  */
  YYSYMBOL_EQUAL = 53,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 54,                 /* NOT_EQUAL  */
  YYSYMBOL_NOT = 55,                       /* NOT  */
  YYSYMBOL_CONCAT = 56,                    /* CONCAT  */
  YYSYMBOL_PLUS = 57,                      /* PLUS  */
  YYSYMBOL_MINUS = 58,                     /* MINUS  */
  YYSYMBOL_MULTIPLICATION = 59,            /* MULTIPLICATION  */
  YYSYMBOL_DIVISION = 60,                  /* DIVISION  */
  YYSYMBOL_MODULO = 61,                    /* MODULO  */
  YYSYMBOL_INT_DIVISION = 62,              /* INT_DIVISION  */
  YYSYMBOL_LPAREN = 63,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 64,                    /* RPAREN  */
  YYSYMBOL_UNARY = 65,                     /* UNARY  */
  YYSYMBOL_INCREMENT = 66,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 67,                 /* DECREMENT  */
  YYSYMBOL_POWER = 68,                     /* POWER  */
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_program = 70,                   /* program  */
  YYSYMBOL_stmtlist = 71,                  /* stmtlist  */
  YYSYMBOL_stmt = 72,                      /* stmt  */
  YYSYMBOL_preincstmt = 73,                /* preincstmt  */
  YYSYMBOL_postincstmt = 74,               /* postincstmt  */
  YYSYMBOL_predecstmt = 75,                /* predecstmt  */
  YYSYMBOL_postdecstmt = 76,               /* postdecstmt  */
  YYSYMBOL_block = 77,                     /* block  */
  YYSYMBOL_controlSymbol = 78,             /* controlSymbol  */
  YYSYMBOL_if = 79,                        /* if  */
  YYSYMBOL_dowhile = 80,                   /* dowhile  */
  YYSYMBOL_while = 81,                     /* while  */
  YYSYMBOL_repeat = 82,                    /* repeat  */
  YYSYMBOL_for = 83,                       /* for  */
  YYSYMBOL_cases = 84,                     /* cases  */
  YYSYMBOL_value_list = 85,                /* value_list  */
  YYSYMBOL_default = 86,                   /* default  */
  YYSYMBOL_clear = 87,                     /* clear  */
  YYSYMBOL_place = 88,                     /* place  */
  YYSYMBOL_cond = 89,                      /* cond  */
  YYSYMBOL_asgn = 90,                      /* asgn  */
  YYSYMBOL_print = 91,                     /* print  */
  YYSYMBOL_read = 92,                      /* read  */
  YYSYMBOL_readstring = 93,                /* readstring  */
  YYSYMBOL_alternative = 94,               /* alternative  */
  YYSYMBOL_exp = 95,                       /* exp  */
  YYSYMBOL_preinc = 96,                    /* preinc  */
  YYSYMBOL_postinc = 97,                   /* postinc  */
  YYSYMBOL_predec = 98,                    /* predec  */
  YYSYMBOL_postdec = 99,                   /* postdec  */
  YYSYMBOL_listOfExp = 100,                /* listOfExp  */
  YYSYMBOL_restOfListOfExp = 101           /* restOfListOfExp  */
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
typedef yytype_uint8 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYLAST   1007

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  232

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   323


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   259,   259,   273,   278,   301,   312,   318,   323,   328,
     333,   338,   343,   348,   353,   358,   364,   370,   376,   382,
     387,   392,   398,   403,   409,   416,   421,   426,   431,   436,
     444,   462,   472,   481,   492,   502,   510,   519,   528,   536,
     543,   549,   555,   559,   566,   575,   582,   587,   592,   597,
     602,   607,   612,   617,   622,   627,   632,   637,   642,   647,
     652,   657,   663,   668,   672,   678,   686,   693,   699,   706,
     710,   715,   720,   725,   731,   737,   743,   749,   754,   760,
     765,   771,   776,   780,   784,   788,   792,   799,   805,   811,
     818,   865,   871,   877,   883,   889,   895,   901,   907,   913,
     919,   924,   929,   934,   942,   947,   958,   963
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "COLON",
  "ALT", "COMMENT", "PRINT", "READ", "READ_STRING", "IF", "ELSE", "WHILE",
  "THEN", "END_IF", "END_WHILE", "REPEAT", "FOR", "FROM", "UNTIL",
  "END_FOR", "STEP", "CASES", "VALUE", "DEFAULT", "END_CASES", "DO",
  "CLEAR", "PLACE", "LETFCURLYBRACKET", "RIGHTCURLYBRACKET", "ASSIGNMENT",
  "PLUS_ASSIGNMENT", "MINUS_ASSIGNMENT", "MULTIPLICATION_ASSIGNMENT",
  "DIVISION_ASSIGNMENT", "INT_DIVISION_ASSIGNMENT", "MODULO_ASSIGNMENT",
  "POWER_ASSIGNMENT", "COMMA", "STRING", "NUMBER", "BOOL", "VARIABLE",
  "UNDEFINED", "CONSTANT", "BUILTIN", "OR", "AND", "GREATER_OR_EQUAL",
  "LESS_OR_EQUAL", "GREATER_THAN", "LESS_THAN", "EQUAL", "NOT_EQUAL",
  "NOT", "CONCAT", "PLUS", "MINUS", "MULTIPLICATION", "DIVISION", "MODULO",
  "INT_DIVISION", "LPAREN", "RPAREN", "UNARY", "INCREMENT", "DECREMENT",
  "POWER", "$accept", "program", "stmtlist", "stmt", "preincstmt",
  "postincstmt", "predecstmt", "postdecstmt", "block", "controlSymbol",
  "if", "dowhile", "while", "repeat", "for", "cases", "value_list",
  "default", "clear", "place", "cond", "asgn", "print", "read",
  "readstring", "alternative", "exp", "preinc", "postinc", "predec",
  "postdec", "listOfExp", "restOfListOfExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-46)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -59,     1,    85,   -59,   -59,   -59,   -59,   732,   -42,   -22,
     -59,   -59,   -59,   -59,   -11,   -59,    41,   -10,   -59,   -19,
      23,    12,    29,   -59,    70,    71,    72,    81,   -59,   -59,
      87,   -59,   -59,   -59,   -59,   -59,   -59,    93,    95,    96,
      97,   -59,   -59,   -33,   -59,    40,   732,   732,   732,   732,
      61,    62,   898,   -59,   -59,   -59,   -59,   -21,    -3,    43,
      43,   -59,    65,   732,   -59,   -59,   732,   117,   739,   767,
     767,   767,   767,   767,   767,   767,   -59,   -59,   767,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   732,    21,    42,    42,   788,   -59,   -59,   732,
     732,   732,   732,   732,   732,   732,   732,   732,   732,   732,
     732,   732,   732,   732,   732,    45,    51,    52,    53,   732,
     108,   105,   308,   104,   810,   494,   684,   -59,   512,    23,
     732,   127,   -59,   -59,   898,   -59,   898,   -59,   898,   -59,
     898,   -59,   898,   -59,   898,   -59,   898,   -59,   898,   -59,
     898,   708,    73,   -59,   919,   609,   939,   939,   939,   939,
     939,   939,   110,   -23,   -23,    42,    42,    42,    42,    42,
     -59,   -59,   -59,   -59,   832,   -59,   -59,    43,   732,   119,
     -59,   732,   854,   732,   732,   -59,   -59,   -59,   278,   340,
     -59,   588,   732,    27,    43,   876,   143,   515,   708,   -59,
     -59,   -59,   732,   537,   732,   146,   128,   105,   151,   732,
     -59,   370,   631,   -59,   566,   -59,   -59,   -59,   898,   -59,
     732,   -59,   205,   -59,   402,   660,   432,   235,   -59,   -59,
     464,   -59
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     5,     7,     6,     0,     0,     0,
      30,    30,    30,    30,     0,    30,     0,     0,     3,     0,
       0,     0,     0,     4,     0,     0,     0,     0,    22,    16,
       0,    18,    19,    20,    21,    23,    24,     0,     0,     0,
       0,    72,    71,    88,    89,     0,     0,     0,     0,     0,
       0,     0,    65,    82,    83,    84,    85,     0,     0,     0,
       0,     3,     0,     0,     3,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,    28,     0,    25,
      27,     9,    10,    11,    12,    17,     8,    13,    14,    15,
     101,   103,   104,    99,    80,    81,     0,   100,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    88,    89,
       0,     0,    61,    64,    46,    48,    47,    50,    49,    52,
      51,    54,    53,    56,    55,    58,    57,    60,    59,    63,
      62,   106,     0,    79,    98,    97,    92,    94,    91,    93,
      95,    96,    73,    74,    75,    76,    77,    86,    78,    87,
      66,    67,    68,    69,     0,     3,     3,     0,     0,     0,
      30,     0,     0,     0,     0,   105,    90,    45,     0,     0,
      35,     0,     0,    42,     0,     0,    79,     0,   106,     3,
      31,    34,     0,     0,     0,     0,     0,    33,     0,     0,
     107,     0,     0,     3,     0,     3,    38,    44,    70,    32,
       0,     3,     0,     3,     0,     0,     0,     0,     3,    36,
       0,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -59,   -59,   -18,   -59,   -59,   -59,   -59,   -59,   -59,    -4,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -58,   118,   -59,   -59,   -59,   -59,   -43,   -59,   -59,   -59,
     -59,   -59,   -35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    23,    24,    25,    26,    27,    28,    59,
      29,    30,    31,    32,    33,    34,   193,   206,    35,    36,
     120,    37,    38,    39,    40,   133,    52,    53,    54,    55,
      56,   152,   185
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,     3,   121,    93,    94,    95,    96,    60,    61,    62,
     131,    64,    68,    69,    70,    71,    72,    73,    74,    75,
     124,    57,   115,   126,   116,   134,   136,   138,   140,   142,
     144,   146,   148,    90,    91,   150,   110,   111,   112,   113,
     117,    58,   118,   122,    65,   114,   125,    76,    77,   151,
     204,   205,    63,    66,    78,    79,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    80,    81,    82,    83,   174,   107,   108,   109,
     110,   111,   112,   113,    84,    -2,     4,   182,     5,   114,
      85,     6,     7,     8,     9,    10,    86,    11,    87,    88,
      89,    12,    13,    92,    97,    98,   119,    14,   123,   170,
     114,    15,    16,    17,    18,   171,   172,   173,     4,   190,
       5,   175,   178,     6,     7,     8,     9,    10,    19,    11,
      20,   176,   183,    12,    13,   191,   207,   186,   195,    14,
     197,   198,   192,    15,    16,    17,    18,   127,   -45,   203,
     215,    21,    22,   216,   217,     0,     0,   188,   189,   212,
      19,   214,    20,   210,     0,     0,   218,   108,   109,   110,
     111,   112,   113,     0,     0,     0,   194,   225,   114,     0,
       0,   211,     0,    21,    22,     0,   132,   135,   137,   139,
     141,   143,   145,   147,     0,   222,   149,   224,     0,     0,
       0,     0,     0,   226,     0,   227,     4,     0,     5,     0,
     230,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,    12,    13,     0,     0,     0,     0,    14,   -39,   -39,
     -39,    15,    16,    17,    18,     0,     4,     0,     5,     0,
       0,     6,     7,     8,     9,    10,     0,    11,    19,     0,
      20,    12,    13,     0,     0,     0,     0,    14,   -40,   -40,
     -40,    15,    16,    17,    18,     0,     0,     0,     0,     0,
       0,    21,    22,     0,     0,     0,     0,     0,    19,     4,
      20,     5,     0,     0,     6,     7,     8,     9,    10,   199,
      11,     0,   200,     0,    12,    13,     0,     0,     0,     0,
      14,    21,    22,     0,    15,    16,    17,    18,     0,     4,
       0,     5,     0,     0,     6,     7,     8,     9,    10,     0,
      11,    19,     0,    20,    12,    13,     0,   177,     0,     0,
      14,     0,     0,     0,    15,    16,    17,    18,     0,     0,
       0,     4,     0,     5,    21,    22,     6,     7,     8,     9,
      10,    19,    11,    20,     0,   201,    12,    13,     0,     0,
       0,     0,    14,     0,     0,     0,    15,    16,    17,    18,
       0,     4,     0,     5,    21,    22,     6,     7,     8,     9,
      10,     0,    11,    19,   219,    20,    12,    13,     0,     0,
       0,     0,    14,     0,     0,     0,    15,    16,    17,    18,
       0,     0,     0,     4,     0,     5,    21,    22,     6,     7,
       8,     9,    10,    19,    11,    20,     0,     0,    12,    13,
       0,     0,     0,     0,    14,     0,     0,   -41,    15,    16,
      17,    18,     0,     4,     0,     5,    21,    22,     6,     7,
       8,     9,    10,     0,    11,    19,     0,    20,    12,    13,
       0,     0,   229,     0,    14,     0,     0,     0,    15,    16,
      17,    18,     0,     0,     0,     4,     0,     5,    21,    22,
       6,     7,     8,     9,    10,    19,    11,    20,     0,     0,
      12,    13,     0,     0,   231,     0,    14,     0,     0,     0,
      15,    16,    17,    18,     0,     4,     0,     5,    21,    22,
       6,     7,     8,     9,    10,     0,   180,    19,     0,    20,
      12,    13,     0,     0,     0,     0,    14,     0,     0,   209,
      15,    16,    17,    18,     0,     0,     0,     0,     0,     0,
      21,    22,     0,     0,     0,     0,     0,    19,     0,    20,
       0,   213,     0,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,    22,    99,   100,   101,   102,   103,   104,   105,   106,
     223,   107,   108,   109,   110,   111,   112,   113,    90,    91,
       0,     0,     0,   114,    99,   100,   101,   102,   103,   104,
     105,   106,     0,   107,   108,   109,   110,   111,   112,   113,
       0,     0,     0,     0,     0,   114,     0,   202,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,   105,
     106,     0,   107,   108,   109,   110,   111,   112,   113,     0,
       0,     0,     0,     0,   114,    99,   100,   101,   102,   103,
     104,   105,   106,     0,   107,   108,   109,   110,   111,   112,
     113,     0,   220,     0,     0,     0,   114,   221,   101,   102,
     103,   104,   105,   106,     0,   107,   108,   109,   110,   111,
     112,   113,     0,     0,     0,     0,     0,   114,    99,   100,
     101,   102,   103,   104,   105,   106,   228,   107,   108,   109,
     110,   111,   112,   113,     0,     0,     0,     0,     0,   114,
       0,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,   105,   106,     0,   107,   108,   109,   110,
     111,   112,   113,   181,     0,     0,     0,     0,   114,     0,
       0,    99,   100,   101,   102,   103,   104,   105,   106,     0,
     107,   108,   109,   110,   111,   112,   113,   184,     0,     0,
       0,     0,   114,     0,     0,    99,   100,   101,   102,   103,
     104,   105,   106,     0,   107,   108,   109,   110,   111,   112,
     113,     0,    41,    42,     0,    43,   114,    44,    45,    41,
      42,     0,   128,     0,   129,    45,     0,    46,     0,    47,
      48,     0,     0,     0,    46,    49,    47,    48,    50,    51,
       0,     0,   130,     0,     0,    50,    51,    41,    42,     0,
     128,     0,   129,    45,     0,     0,     0,     0,     0,     0,
       0,     0,    46,     0,    47,    48,     0,     0,     0,     0,
      49,     0,     0,    50,    51,    99,   100,   101,   102,   103,
     104,   105,   106,     0,   107,   108,   109,   110,   111,   112,
     113,     0,   153,     0,     0,     0,   114,    99,   100,   101,
     102,   103,   104,   105,   106,     0,   107,   108,   109,   110,
     111,   112,   113,     0,   179,     0,     0,     0,   114,    99,
     100,   101,   102,   103,   104,   105,   106,     0,   107,   108,
     109,   110,   111,   112,   113,     0,   187,     0,     0,     0,
     114,    99,   100,   101,   102,   103,   104,   105,   106,     0,
     107,   108,   109,   110,   111,   112,   113,     0,   196,     0,
       0,     0,   114,    99,   100,   101,   102,   103,   104,   105,
     106,     0,   107,   108,   109,   110,   111,   112,   113,     0,
     208,     0,     0,     0,   114,    99,   100,   101,   102,   103,
     104,   105,   106,     0,   107,   108,   109,   110,   111,   112,
     113,     0,     0,     0,     0,     0,   114,   100,   101,   102,
     103,   104,   105,   106,     0,   107,   108,   109,   110,   111,
     112,   113,     0,     0,     0,     0,     0,   114,   -46,   -46,
     -46,   -46,   -46,   -46,     0,   107,   108,   109,   110,   111,
     112,   113,     0,     0,     0,     0,     0,   114
};

static const yytype_int16 yycheck[] =
{
      18,     0,    60,    46,    47,    48,    49,    11,    12,    13,
      68,    15,    31,    32,    33,    34,    35,    36,    37,    38,
      63,    63,    43,    66,    45,    68,    69,    70,    71,    72,
      73,    74,    75,    66,    67,    78,    59,    60,    61,    62,
      43,    63,    45,    61,     3,    68,    64,    66,    67,    92,
      23,    24,    63,    63,    31,    43,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    43,     3,     3,     3,   119,    56,    57,    58,
      59,    60,    61,    62,     3,     0,     1,   130,     3,    68,
       3,     6,     7,     8,     9,    10,     3,    12,     3,     3,
       3,    16,    17,    63,    43,    43,    63,    22,    43,    64,
      68,    26,    27,    28,    29,    64,    64,    64,     1,   177,
       3,    13,    18,     6,     7,     8,     9,    10,    43,    12,
      45,    26,     5,    16,    17,   178,   194,    64,   181,    22,
     183,   184,    23,    26,    27,    28,    29,    30,     5,   192,
       4,    66,    67,    25,     3,    -1,    -1,   175,   176,   202,
      43,   204,    45,   198,    -1,    -1,   209,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,   180,   220,    68,    -1,
      -1,   199,    -1,    66,    67,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,   213,    78,   215,    -1,    -1,
      -1,    -1,    -1,   221,    -1,   223,     1,    -1,     3,    -1,
     228,     6,     7,     8,     9,    10,    -1,    12,    -1,    -1,
      -1,    16,    17,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,     1,    -1,     3,    -1,
      -1,     6,     7,     8,     9,    10,    -1,    12,    43,    -1,
      45,    16,    17,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    43,     1,
      45,     3,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    -1,    16,    17,    -1,    -1,    -1,    -1,
      22,    66,    67,    -1,    26,    27,    28,    29,    -1,     1,
      -1,     3,    -1,    -1,     6,     7,     8,     9,    10,    -1,
      12,    43,    -1,    45,    16,    17,    -1,    19,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27,    28,    29,    -1,    -1,
      -1,     1,    -1,     3,    66,    67,     6,     7,     8,     9,
      10,    43,    12,    45,    -1,    15,    16,    17,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    28,    29,
      -1,     1,    -1,     3,    66,    67,     6,     7,     8,     9,
      10,    -1,    12,    43,    14,    45,    16,    17,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    28,    29,
      -1,    -1,    -1,     1,    -1,     3,    66,    67,     6,     7,
       8,     9,    10,    43,    12,    45,    -1,    -1,    16,    17,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    25,    26,    27,
      28,    29,    -1,     1,    -1,     3,    66,    67,     6,     7,
       8,     9,    10,    -1,    12,    43,    -1,    45,    16,    17,
      -1,    -1,    20,    -1,    22,    -1,    -1,    -1,    26,    27,
      28,    29,    -1,    -1,    -1,     1,    -1,     3,    66,    67,
       6,     7,     8,     9,    10,    43,    12,    45,    -1,    -1,
      16,    17,    -1,    -1,    20,    -1,    22,    -1,    -1,    -1,
      26,    27,    28,    29,    -1,     1,    -1,     3,    66,    67,
       6,     7,     8,     9,    10,    -1,    12,    43,    -1,    45,
      16,    17,    -1,    -1,    -1,    -1,    22,    -1,    -1,     4,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    43,    -1,    45,
      -1,     4,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    47,    48,    49,    50,    51,    52,    53,    54,
       4,    56,    57,    58,    59,    60,    61,    62,    66,    67,
      -1,    -1,    -1,    68,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    -1,    21,    -1,    -1,    -1,    68,    26,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    47,    48,
      49,    50,    51,    52,    53,    54,    26,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    39,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    39,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    -1,    40,    41,    -1,    43,    68,    45,    46,    40,
      41,    -1,    43,    -1,    45,    46,    -1,    55,    -1,    57,
      58,    -1,    -1,    -1,    55,    63,    57,    58,    66,    67,
      -1,    -1,    63,    -1,    -1,    66,    67,    40,    41,    -1,
      43,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    66,    67,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    -1,    -1,    -1,    68,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    -1,    64,    -1,    -1,    -1,    68,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    -1,    -1,    -1,
      68,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    -1,
      -1,    -1,    68,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    -1,
      64,    -1,    -1,    -1,    68,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    68,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    70,    71,     0,     1,     3,     6,     7,     8,     9,
      10,    12,    16,    17,    22,    26,    27,    28,    29,    43,
      45,    66,    67,    72,    73,    74,    75,    76,    77,    79,
      80,    81,    82,    83,    84,    87,    88,    90,    91,    92,
      93,    40,    41,    43,    45,    46,    55,    57,    58,    63,
      66,    67,    95,    96,    97,    98,    99,    63,    63,    78,
      78,    78,    78,    63,    78,     3,    63,    71,    31,    32,
      33,    34,    35,    36,    37,    38,    66,    67,    31,    43,
      43,     3,     3,     3,     3,     3,     3,     3,     3,     3,
      66,    67,    63,    95,    95,    95,    95,    43,    43,    47,
      48,    49,    50,    51,    52,    53,    54,    56,    57,    58,
      59,    60,    61,    62,    68,    43,    45,    43,    45,    63,
      89,    89,    71,    43,    95,    71,    95,    30,    43,    45,
      63,    89,    90,    94,    95,    90,    95,    90,    95,    90,
      95,    90,    95,    90,    95,    90,    95,    90,    95,    90,
      95,    95,   100,    64,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      64,    64,    64,    64,    95,    13,    26,    19,    18,    64,
      12,    39,    95,     5,    39,   101,    64,    64,    71,    71,
      89,    95,    23,    85,    78,    95,    64,    95,    95,    11,
      14,    15,    19,    95,    23,    24,    86,    89,    64,     4,
     101,    71,    95,     4,    95,     4,    25,     3,    95,    14,
      21,    26,    71,     4,    71,    95,    71,    71,    26,    20,
      71,    20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    69,    70,    71,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    73,    74,    75,    76,    77,
      78,    79,    79,    80,    81,    82,    83,    83,    84,    85,
      85,    86,    86,    87,    88,    89,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    91,    92,    92,    93,    93,
      94,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      96,    97,    98,    99,   100,   100,   101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     3,
       0,     6,     8,     6,     6,     5,    10,    12,     7,     4,
       5,     3,     0,     2,     7,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     4,     4,     4,     4,
       5,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     1,     1,     1,     3,     3,     1,     1,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     2,     0,     2,     0,     3
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* program: stmtlist  */
#line 260 "interpreter.y"
                  { 
		    // Create a new AST
			(yyval.prog) = new lp::AST((yyvsp[0].stmts)); 

			// Assign the AST to the root
			root = (yyval.prog); 

			// End of parsing
			//	return 1;
		  }
#line 1879 "interpreter.tab.c"
    break;

  case 3: /* stmtlist: %empty  */
#line 273 "interpreter.y"
                  { 
			// create a empty list of statements
			(yyval.stmts) = new std::list<lp::Statement *>(); 
		  }
#line 1888 "interpreter.tab.c"
    break;

  case 4: /* stmtlist: stmtlist stmt  */
#line 279 "interpreter.y"
                  { 
			// copy up the list and add the stmt to it
			(yyval.stmts) = (yyvsp[-1].stmts);
			(yyval.stmts)->push_back((yyvsp[0].st));

			// Control the interative mode of execution of the interpreter
			if (interactiveMode == true && control == 0)
 			{
				for(std::list<lp::Statement *>::iterator it = (yyval.stmts)->begin(); 
						it != (yyval.stmts)->end(); 
						it++)
				{
					//(*it)->printAST();
					(*it)->evaluate();
					
				}

				// Delete the AST code, because it has already run in the interactive mode.
				(yyval.stmts)->clear();
			}
		}
#line 1914 "interpreter.tab.c"
    break;

  case 5: /* stmtlist: stmtlist error  */
#line 302 "interpreter.y"
      { 
			 // just copy up the stmtlist when an error occurs
			 (yyval.stmts) = (yyvsp[-1].stmts);

			 // The previous look-ahead token ought to be discarded with `yyclearin;'
			 yyclearin; 
       }
#line 1926 "interpreter.tab.c"
    break;

  case 6: /* stmt: COMMENT  */
#line 313 "interpreter.y"
        {
		(yyval.st) = new lp::CommentStmt((yyvsp[0].comentario));
		
	
	}
#line 1936 "interpreter.tab.c"
    break;

  case 7: /* stmt: SEMICOLON  */
#line 319 "interpreter.y"
          {
		// Create a new empty statement node
		(yyval.st) = new lp::EmptyStmt(); 
	  }
#line 1945 "interpreter.tab.c"
    break;

  case 8: /* stmt: asgn SEMICOLON  */
#line 324 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1954 "interpreter.tab.c"
    break;

  case 9: /* stmt: preincstmt SEMICOLON  */
#line 329 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1963 "interpreter.tab.c"
    break;

  case 10: /* stmt: postincstmt SEMICOLON  */
#line 334 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1972 "interpreter.tab.c"
    break;

  case 11: /* stmt: predecstmt SEMICOLON  */
#line 339 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1981 "interpreter.tab.c"
    break;

  case 12: /* stmt: postdecstmt SEMICOLON  */
#line 344 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1990 "interpreter.tab.c"
    break;

  case 13: /* stmt: print SEMICOLON  */
#line 349 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1999 "interpreter.tab.c"
    break;

  case 14: /* stmt: read SEMICOLON  */
#line 354 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 2008 "interpreter.tab.c"
    break;

  case 15: /* stmt: readstring SEMICOLON  */
#line 359 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 2017 "interpreter.tab.c"
    break;

  case 16: /* stmt: if  */
#line 365 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 2026 "interpreter.tab.c"
    break;

  case 17: /* stmt: dowhile SEMICOLON  */
#line 371 "interpreter.y"
        {
		// Default action
		// $$ = $1;
	 }
#line 2035 "interpreter.tab.c"
    break;

  case 18: /* stmt: while  */
#line 377 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 2044 "interpreter.tab.c"
    break;

  case 19: /* stmt: repeat  */
#line 383 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 2053 "interpreter.tab.c"
    break;

  case 20: /* stmt: for  */
#line 388 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 2062 "interpreter.tab.c"
    break;

  case 21: /* stmt: cases  */
#line 393 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 2071 "interpreter.tab.c"
    break;

  case 22: /* stmt: block  */
#line 399 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 2080 "interpreter.tab.c"
    break;

  case 23: /* stmt: clear  */
#line 404 "interpreter.y"
        {
		// Default action
		// $$ = $1;
	
	}
#line 2090 "interpreter.tab.c"
    break;

  case 24: /* stmt: place  */
#line 410 "interpreter.y"
        {
		// Default action
		// $$ = $1;
	}
#line 2099 "interpreter.tab.c"
    break;

  case 25: /* preincstmt: INCREMENT VARIABLE  */
#line 417 "interpreter.y"
                {
			(yyval.st) = new lp::PreIncrementStmt((yyvsp[0].string));
		}
#line 2107 "interpreter.tab.c"
    break;

  case 26: /* postincstmt: VARIABLE INCREMENT  */
#line 422 "interpreter.y"
                {
			(yyval.st) = new lp::PostIncrementStmt((yyvsp[-1].string));
		}
#line 2115 "interpreter.tab.c"
    break;

  case 27: /* predecstmt: DECREMENT VARIABLE  */
#line 427 "interpreter.y"
                {
			(yyval.st) = new lp::PreDecrementStmt((yyvsp[0].string));
		}
#line 2123 "interpreter.tab.c"
    break;

  case 28: /* postdecstmt: VARIABLE DECREMENT  */
#line 432 "interpreter.y"
                {
			(yyval.st) = new lp::PostDecrementStmt((yyvsp[-1].string));
		}
#line 2131 "interpreter.tab.c"
    break;

  case 29: /* block: LETFCURLYBRACKET stmtlist RIGHTCURLYBRACKET  */
#line 437 "interpreter.y"
                {
			// Create a new block of statements node
			(yyval.st) = new lp::BlockStmt((yyvsp[-1].stmts)); 
		}
#line 2140 "interpreter.tab.c"
    break;

  case 30: /* controlSymbol: %empty  */
#line 444 "interpreter.y"
                {
			// To control the interactive mode in "if" and "while" sentences
			control++;
		}
#line 2149 "interpreter.tab.c"
    break;

  case 31: /* if: IF controlSymbol cond THEN stmtlist END_IF  */
#line 463 "interpreter.y"
    {
		// Create a new if statement node
		(yyval.st) = new lp::IfStmt((yyvsp[-3].expNode), (yyvsp[-1].stmts));

		// To control the interactive mode
		control--;
	}
#line 2161 "interpreter.tab.c"
    break;

  case 32: /* if: IF controlSymbol cond THEN stmtlist ELSE stmtlist END_IF  */
#line 473 "interpreter.y"
         {
		// Create a new if statement node
		(yyval.st) = new lp::IfStmt((yyvsp[-5].expNode), (yyvsp[-3].stmts), (yyvsp[-1].stmts));

		// To control the interactive mode
		control--;
	 }
#line 2173 "interpreter.tab.c"
    break;

  case 33: /* dowhile: DO controlSymbol stmtlist WHILE controlSymbol cond  */
#line 482 "interpreter.y"
                {
			// Create a new do-while statement node
			(yyval.st) = new lp::DoWhileStmt((yyvsp[0].expNode), (yyvsp[-3].stmts));

			control--;
			control--;
		}
#line 2185 "interpreter.tab.c"
    break;

  case 34: /* while: WHILE controlSymbol cond DO stmtlist END_WHILE  */
#line 493 "interpreter.y"
                {
			// Create a new while statement node
			(yyval.st) = new lp::WhileStmt((yyvsp[-3].expNode), (yyvsp[-1].stmts));

			// To control the interactive mode
			control--;
    }
#line 2197 "interpreter.tab.c"
    break;

  case 35: /* repeat: REPEAT controlSymbol stmtlist UNTIL cond  */
#line 503 "interpreter.y"
                {
			// Create a new repeat statement node
			(yyval.st) = new lp::RepeatStmt((yyvsp[0].expNode), (yyvsp[-2].stmts));

			control--;
		}
#line 2208 "interpreter.tab.c"
    break;

  case 36: /* for: FOR controlSymbol VARIABLE FROM exp UNTIL exp DO stmtlist END_FOR  */
#line 511 "interpreter.y"
                {
			// Comprobamos en el caso de que la variable ya exista en la tabla de símbolos y la inicializamos al valor INICIAL

			(yyval.st) = new lp::ForStmt((yyvsp[-7].string), (yyvsp[-5].expNode), (yyvsp[-3].expNode), (yyvsp[-1].stmts));

		control--;
		}
#line 2220 "interpreter.tab.c"
    break;

  case 37: /* for: FOR controlSymbol VARIABLE FROM exp UNTIL exp STEP exp DO stmtlist END_FOR  */
#line 520 "interpreter.y"
                {
			// Comprobamos en el caso de que la variable ya exista en la tabla de símbolos y la inicializamos al valor INICIAL
			(yyval.st) = new lp::ForStmt((yyvsp[-9].string), (yyvsp[-7].expNode), (yyvsp[-5].expNode), (yyvsp[-1].stmts), (yyvsp[-3].expNode));

		control--;
		}
#line 2231 "interpreter.tab.c"
    break;

  case 38: /* cases: CASES LPAREN exp RPAREN value_list default END_CASES  */
#line 529 "interpreter.y"
                {
			// Create a new cases statement node
			(yyval.st) = new lp::CasesStmt((yyvsp[-4].expNode), (std::list<lp::ValueStmt *> *) (yyvsp[-2].valuestmts), (lp::DefaultStmt *) (yyvsp[-1].st));
			
		}
#line 2241 "interpreter.tab.c"
    break;

  case 39: /* value_list: VALUE exp COLON stmtlist  */
#line 537 "interpreter.y"
                {
			std::list<lp::ValueStmt *> * stmts = new std::list<lp::ValueStmt *>();
			stmts->push_back(new lp::ValueStmt((yyvsp[-2].expNode), (yyvsp[0].stmts)));
			(yyval.valuestmts) = stmts;
		}
#line 2251 "interpreter.tab.c"
    break;

  case 40: /* value_list: value_list VALUE exp COLON stmtlist  */
#line 544 "interpreter.y"
                {
			(yyval.valuestmts) = (yyvsp[-4].valuestmts);
			(yyval.valuestmts)->push_back(new lp::ValueStmt((yyvsp[-2].expNode), (yyvsp[0].stmts)));
		}
#line 2260 "interpreter.tab.c"
    break;

  case 41: /* default: DEFAULT COLON stmtlist  */
#line 550 "interpreter.y"
                {
			// Create a new default node
			(yyval.st) = new lp::DefaultStmt((yyvsp[0].stmts));
		}
#line 2269 "interpreter.tab.c"
    break;

  case 42: /* default: %empty  */
#line 555 "interpreter.y"
                {
			(yyval.st) = new lp::DefaultStmt(new std::list<lp::Statement *>());
		}
#line 2277 "interpreter.tab.c"
    break;

  case 43: /* clear: CLEAR SEMICOLON  */
#line 560 "interpreter.y"
                {
			// Create a new clear node
			(yyval.st) = new lp::ClearScreenStmt();
		}
#line 2286 "interpreter.tab.c"
    break;

  case 44: /* place: PLACE LPAREN exp COMMA exp RPAREN SEMICOLON  */
#line 567 "interpreter.y"
                {
			// Create a new place node
			(yyval.st) = new lp::PlaceStmt((yyvsp[-4].expNode), (yyvsp[-2].expNode));
		}
#line 2295 "interpreter.tab.c"
    break;

  case 45: /* cond: LPAREN exp RPAREN  */
#line 576 "interpreter.y"
                { 
			(yyval.expNode) = (yyvsp[-1].expNode);
		}
#line 2303 "interpreter.tab.c"
    break;

  case 46: /* asgn: VARIABLE ASSIGNMENT exp  */
#line 583 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (yyvsp[0].expNode));
		}
#line 2312 "interpreter.tab.c"
    break;

  case 47: /* asgn: VARIABLE PLUS_ASSIGNMENT exp  */
#line 588 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), new lp::PlusNode(new lp::VariableNode((yyvsp[-2].string)), (yyvsp[0].expNode)));
		}
#line 2321 "interpreter.tab.c"
    break;

  case 48: /* asgn: VARIABLE PLUS_ASSIGNMENT asgn  */
#line 593 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (lp::AssignmentStmt *) (yyvsp[0].st));
		}
#line 2330 "interpreter.tab.c"
    break;

  case 49: /* asgn: VARIABLE MINUS_ASSIGNMENT exp  */
#line 598 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), new lp::MinusNode(new lp::VariableNode((yyvsp[-2].string)), (yyvsp[0].expNode)));
		}
#line 2339 "interpreter.tab.c"
    break;

  case 50: /* asgn: VARIABLE MINUS_ASSIGNMENT asgn  */
#line 603 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (lp::AssignmentStmt *) (yyvsp[0].st));
		}
#line 2348 "interpreter.tab.c"
    break;

  case 51: /* asgn: VARIABLE MULTIPLICATION_ASSIGNMENT exp  */
#line 608 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), new lp::MultiplicationNode(new lp::VariableNode((yyvsp[-2].string)), (yyvsp[0].expNode)));
		}
#line 2357 "interpreter.tab.c"
    break;

  case 52: /* asgn: VARIABLE MULTIPLICATION_ASSIGNMENT asgn  */
#line 613 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (lp::AssignmentStmt *) (yyvsp[0].st));
		}
#line 2366 "interpreter.tab.c"
    break;

  case 53: /* asgn: VARIABLE DIVISION_ASSIGNMENT exp  */
#line 618 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), new lp::DivisionNode(new lp::VariableNode((yyvsp[-2].string)), (yyvsp[0].expNode)));
		}
#line 2375 "interpreter.tab.c"
    break;

  case 54: /* asgn: VARIABLE DIVISION_ASSIGNMENT asgn  */
#line 623 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (lp::AssignmentStmt *) (yyvsp[0].st));
		}
#line 2384 "interpreter.tab.c"
    break;

  case 55: /* asgn: VARIABLE INT_DIVISION_ASSIGNMENT exp  */
#line 628 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), new lp::IntDivisionNode(new lp::VariableNode((yyvsp[-2].string)), (yyvsp[0].expNode)));
		}
#line 2393 "interpreter.tab.c"
    break;

  case 56: /* asgn: VARIABLE INT_DIVISION_ASSIGNMENT asgn  */
#line 633 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (lp::AssignmentStmt *) (yyvsp[0].st));
		}
#line 2402 "interpreter.tab.c"
    break;

  case 57: /* asgn: VARIABLE MODULO_ASSIGNMENT exp  */
#line 638 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), new lp::ModuloNode(new lp::VariableNode((yyvsp[-2].string)), (yyvsp[0].expNode)));
		}
#line 2411 "interpreter.tab.c"
    break;

  case 58: /* asgn: VARIABLE MODULO_ASSIGNMENT asgn  */
#line 643 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (lp::AssignmentStmt *) (yyvsp[0].st));
		}
#line 2420 "interpreter.tab.c"
    break;

  case 59: /* asgn: VARIABLE POWER_ASSIGNMENT exp  */
#line 648 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), new lp::PowerNode(new lp::VariableNode((yyvsp[-2].string)), (yyvsp[0].expNode)));
		}
#line 2429 "interpreter.tab.c"
    break;

  case 60: /* asgn: VARIABLE POWER_ASSIGNMENT asgn  */
#line 653 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (lp::AssignmentStmt *) (yyvsp[0].st));
		}
#line 2438 "interpreter.tab.c"
    break;

  case 61: /* asgn: VARIABLE ASSIGNMENT asgn  */
#line 658 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (lp::AssignmentStmt *) (yyvsp[0].st));
		}
#line 2447 "interpreter.tab.c"
    break;

  case 62: /* asgn: CONSTANT ASSIGNMENT exp  */
#line 664 "interpreter.y"
                {   
 			execerror("Semantic error in assignment: it is not allowed to modify a constant ", (yyvsp[-2].string));
		}
#line 2455 "interpreter.tab.c"
    break;

  case 63: /* asgn: CONSTANT ASSIGNMENT asgn  */
#line 669 "interpreter.y"
                {   
 			execerror("Semantic error in multiple assignment: it is not allowed to modify a constant ",(yyvsp[-2].string));
		}
#line 2463 "interpreter.tab.c"
    break;

  case 64: /* asgn: VARIABLE ASSIGNMENT alternative  */
#line 673 "interpreter.y"
                {
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (yyvsp[0].expNode));
		}
#line 2471 "interpreter.tab.c"
    break;

  case 65: /* print: PRINT exp  */
#line 679 "interpreter.y"
                {
			// Create a new print node
			 (yyval.st) = new lp::PrintStmt((yyvsp[0].expNode));

		}
#line 2481 "interpreter.tab.c"
    break;

  case 66: /* read: READ LPAREN VARIABLE RPAREN  */
#line 687 "interpreter.y"
                {
			// Create a new read node
			 (yyval.st) = new lp::ReadStmt((yyvsp[-1].string));
		}
#line 2490 "interpreter.tab.c"
    break;

  case 67: /* read: READ LPAREN CONSTANT RPAREN  */
#line 694 "interpreter.y"
                {   
 			execerror("Semantic error in \"read statement\": it is not allowed to modify a constant ",(yyvsp[-1].string));
		}
#line 2498 "interpreter.tab.c"
    break;

  case 68: /* readstring: READ_STRING LPAREN VARIABLE RPAREN  */
#line 700 "interpreter.y"
                {
			// Create a new read string node
			 (yyval.st) = new lp::ReadStringStmt((yyvsp[-1].string));
		}
#line 2507 "interpreter.tab.c"
    break;

  case 69: /* readstring: READ_STRING LPAREN CONSTANT RPAREN  */
#line 707 "interpreter.y"
                {   
 			execerror("Semantic error in \"read string statement\": it is not allowed to modify a constant ",(yyvsp[-1].string));
		}
#line 2515 "interpreter.tab.c"
    break;

  case 70: /* alternative: cond ALT exp COLON exp  */
#line 710 "interpreter.y"
                                   {
		    // Create a new alternative node
			(yyval.expNode) = new lp::AlternativeNode((yyvsp[-4].expNode), (yyvsp[-2].expNode), (yyvsp[0].expNode));
	 }
#line 2524 "interpreter.tab.c"
    break;

  case 71: /* exp: NUMBER  */
#line 716 "interpreter.y"
                { 
			// Create a new number node
			(yyval.expNode) = new lp::NumberNode((yyvsp[0].number));
		}
#line 2533 "interpreter.tab.c"
    break;

  case 72: /* exp: STRING  */
#line 721 "interpreter.y"
                {
			// Create a new string node
			(yyval.expNode) = new lp::StringNode((yyvsp[0].cadena));
		}
#line 2542 "interpreter.tab.c"
    break;

  case 73: /* exp: exp CONCAT exp  */
#line 726 "interpreter.y"
                {
			// Create a new concatenation node
			(yyval.expNode) = new lp::ConcatNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2551 "interpreter.tab.c"
    break;

  case 74: /* exp: exp PLUS exp  */
#line 732 "interpreter.y"
                { 
			// Create a new plus node
			 (yyval.expNode) = new lp::PlusNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		 }
#line 2560 "interpreter.tab.c"
    break;

  case 75: /* exp: exp MINUS exp  */
#line 738 "interpreter.y"
        {
			// Create a new minus node
			(yyval.expNode) = new lp::MinusNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2569 "interpreter.tab.c"
    break;

  case 76: /* exp: exp MULTIPLICATION exp  */
#line 744 "interpreter.y"
                { 
			// Create a new multiplication node
			(yyval.expNode) = new lp::MultiplicationNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2578 "interpreter.tab.c"
    break;

  case 77: /* exp: exp DIVISION exp  */
#line 750 "interpreter.y"
                {
		  // Create a new division node	
		  (yyval.expNode) = new lp::DivisionNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
	   }
#line 2587 "interpreter.tab.c"
    break;

  case 78: /* exp: exp INT_DIVISION exp  */
#line 755 "interpreter.y"
                {
		  // Create a new integer division node	
		  (yyval.expNode) = new lp::IntDivisionNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
	   }
#line 2596 "interpreter.tab.c"
    break;

  case 79: /* exp: LPAREN exp RPAREN  */
#line 761 "interpreter.y"
        { 
		    // just copy up the expression node 
			(yyval.expNode) = (yyvsp[-1].expNode);
		 }
#line 2605 "interpreter.tab.c"
    break;

  case 80: /* exp: PLUS exp  */
#line 766 "interpreter.y"
                { 
		  // Create a new unary plus node	
  		  (yyval.expNode) = new lp::UnaryPlusNode((yyvsp[0].expNode));
		}
#line 2614 "interpreter.tab.c"
    break;

  case 81: /* exp: MINUS exp  */
#line 772 "interpreter.y"
                { 
		  // Create a new unary minus node	
  		  (yyval.expNode) = new lp::UnaryMinusNode((yyvsp[0].expNode));
		}
#line 2623 "interpreter.tab.c"
    break;

  case 82: /* exp: preinc  */
#line 777 "interpreter.y"
                {
			(yyval.expNode) = (yyvsp[0].expNode);
		}
#line 2631 "interpreter.tab.c"
    break;

  case 83: /* exp: postinc  */
#line 781 "interpreter.y"
                {
			(yyval.expNode) = (yyvsp[0].expNode);
		}
#line 2639 "interpreter.tab.c"
    break;

  case 84: /* exp: predec  */
#line 785 "interpreter.y"
                {
			(yyval.expNode) = (yyvsp[0].expNode);
		}
#line 2647 "interpreter.tab.c"
    break;

  case 85: /* exp: postdec  */
#line 789 "interpreter.y"
                {
			(yyval.expNode) = (yyvsp[0].expNode);
		}
#line 2655 "interpreter.tab.c"
    break;

  case 86: /* exp: exp MODULO exp  */
#line 793 "interpreter.y"
                {
		  // Create a new modulo node	

		  (yyval.expNode) = new lp::ModuloNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
       }
#line 2665 "interpreter.tab.c"
    break;

  case 87: /* exp: exp POWER exp  */
#line 800 "interpreter.y"
        { 
		  // Create a new power node	
  		  (yyval.expNode) = new lp::PowerNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2674 "interpreter.tab.c"
    break;

  case 88: /* exp: VARIABLE  */
#line 806 "interpreter.y"
                {
		  // Create a new variable node	
		  (yyval.expNode) = new lp::VariableNode((yyvsp[0].string));
		}
#line 2683 "interpreter.tab.c"
    break;

  case 89: /* exp: CONSTANT  */
#line 812 "interpreter.y"
                {
		  // Create a new constant node	
		  (yyval.expNode) = new lp::ConstantNode((yyvsp[0].string));

		}
#line 2693 "interpreter.tab.c"
    break;

  case 90: /* exp: BUILTIN LPAREN listOfExp RPAREN  */
#line 819 "interpreter.y"
                {
			// Get the identifier in the table of symbols as Builtin
			lp::Builtin *f= (lp::Builtin *) table.getSymbol((yyvsp[-3].string));

			// Check the number of parameters 
			if (f->getNParameters() ==  (int) (yyvsp[-1].parameters)->size())
			{
				switch(f->getNParameters())
				{
					case 0:
						{
							// Create a new Builtin Function with 0 parameters node	
							(yyval.expNode) = new lp::BuiltinFunctionNode_0((yyvsp[-3].string));
						}
						break;

					case 1:
						{
							// Get the expression from the list of expressions
							lp::ExpNode *e = (yyvsp[-1].parameters)->front();

							// Create a new Builtin Function with 1 parameter node	
							(yyval.expNode) = new lp::BuiltinFunctionNode_1((yyvsp[-3].string),e);
						}
						break;

					case 2:
						{
							// Get the expressions from the list of expressions
							lp::ExpNode *e1 = (yyvsp[-1].parameters)->front();
							(yyvsp[-1].parameters)->pop_front();
							lp::ExpNode *e2 = (yyvsp[-1].parameters)->front();

							// Create a new Builtin Function with 2 parameters node	
							(yyval.expNode) = new lp::BuiltinFunctionNode_2((yyvsp[-3].string),e1,e2);
						}
						break;

					default:
				  			 execerror("Syntax error: too many parameters for function ", (yyvsp[-3].string));
				} 
			}
			else
	  			 execerror("Syntax error: incompatible number of parameters for function", (yyvsp[-3].string));
		}
#line 2743 "interpreter.tab.c"
    break;

  case 91: /* exp: exp GREATER_THAN exp  */
#line 866 "interpreter.y"
                {
		  // Create a new "greater than" node	
 			(yyval.expNode) = new lp::GreaterThanNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2752 "interpreter.tab.c"
    break;

  case 92: /* exp: exp GREATER_OR_EQUAL exp  */
#line 872 "interpreter.y"
                {
		  // Create a new "greater or equal" node	
 			(yyval.expNode) = new lp::GreaterOrEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2761 "interpreter.tab.c"
    break;

  case 93: /* exp: exp LESS_THAN exp  */
#line 878 "interpreter.y"
                {
		  // Create a new "less than" node	
 			(yyval.expNode) = new lp::LessThanNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2770 "interpreter.tab.c"
    break;

  case 94: /* exp: exp LESS_OR_EQUAL exp  */
#line 884 "interpreter.y"
                {
		  // Create a new "less or equal" node	
 			(yyval.expNode) = new lp::LessOrEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2779 "interpreter.tab.c"
    break;

  case 95: /* exp: exp EQUAL exp  */
#line 890 "interpreter.y"
                {
		  // Create a new "equal" node	
 			(yyval.expNode) = new lp::EqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2788 "interpreter.tab.c"
    break;

  case 96: /* exp: exp NOT_EQUAL exp  */
#line 896 "interpreter.y"
                {
		  // Create a new "not equal" node	
 			(yyval.expNode) = new lp::NotEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2797 "interpreter.tab.c"
    break;

  case 97: /* exp: exp AND exp  */
#line 902 "interpreter.y"
                {
		  // Create a new "logic and" node	
 			(yyval.expNode) = new lp::AndNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2806 "interpreter.tab.c"
    break;

  case 98: /* exp: exp OR exp  */
#line 908 "interpreter.y"
                {
		  // Create a new "logic or" node	
 			(yyval.expNode) = new lp::OrNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2815 "interpreter.tab.c"
    break;

  case 99: /* exp: NOT exp  */
#line 914 "interpreter.y"
                {
		  // Create a new "logic negation" node	
 			(yyval.expNode) = new lp::NotNode((yyvsp[0].expNode));
		}
#line 2824 "interpreter.tab.c"
    break;

  case 100: /* preinc: INCREMENT VARIABLE  */
#line 920 "interpreter.y"
                {
			(yyval.expNode) = new lp::PreIncrementNode((yyvsp[0].string));
		}
#line 2832 "interpreter.tab.c"
    break;

  case 101: /* postinc: VARIABLE INCREMENT  */
#line 925 "interpreter.y"
                {
			(yyval.expNode) = new lp::PostIncrementNode((yyvsp[-1].string));
		}
#line 2840 "interpreter.tab.c"
    break;

  case 102: /* predec: DECREMENT VARIABLE  */
#line 930 "interpreter.y"
                {
			(yyval.expNode) = new lp::PreDecrementNode((yyvsp[0].string));
		}
#line 2848 "interpreter.tab.c"
    break;

  case 103: /* postdec: VARIABLE DECREMENT  */
#line 935 "interpreter.y"
                {
			(yyval.expNode) = new lp::PostDecrementNode((yyvsp[-1].string));
		}
#line 2856 "interpreter.tab.c"
    break;

  case 104: /* listOfExp: %empty  */
#line 942 "interpreter.y"
                        {
			    // Create a new list STL
				(yyval.parameters) = new std::list<lp::ExpNode *>(); 
			}
#line 2865 "interpreter.tab.c"
    break;

  case 105: /* listOfExp: exp restOfListOfExp  */
#line 948 "interpreter.y"
                        {
				(yyval.parameters) = (yyvsp[0].parameters);

				// Insert the expression in the list of expressions
				(yyval.parameters)->push_front((yyvsp[-1].expNode));
			}
#line 2876 "interpreter.tab.c"
    break;

  case 106: /* restOfListOfExp: %empty  */
#line 958 "interpreter.y"
                        {
			    // Create a new list STL
				(yyval.parameters) = new std::list<lp::ExpNode *>(); 
			}
#line 2885 "interpreter.tab.c"
    break;

  case 107: /* restOfListOfExp: COMMA exp restOfListOfExp  */
#line 964 "interpreter.y"
                        {
				// Get the list of expressions
				(yyval.parameters) = (yyvsp[0].parameters);

				// Insert the expression in the list of expressions
				(yyval.parameters)->push_front((yyvsp[-1].expNode));
			}
#line 2897 "interpreter.tab.c"
    break;


#line 2901 "interpreter.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 975 "interpreter.y"




