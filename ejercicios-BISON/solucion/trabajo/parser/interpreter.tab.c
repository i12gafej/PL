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
  YYSYMBOL_COMMENT = 5,                    /* COMMENT  */
  YYSYMBOL_PRINT = 6,                      /* PRINT  */
  YYSYMBOL_READ = 7,                       /* READ  */
  YYSYMBOL_READ_STRING = 8,                /* READ_STRING  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_THEN = 12,                      /* THEN  */
  YYSYMBOL_END_IF = 13,                    /* END_IF  */
  YYSYMBOL_END_WHILE = 14,                 /* END_WHILE  */
  YYSYMBOL_REPEAT = 15,                    /* REPEAT  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_FROM = 17,                      /* FROM  */
  YYSYMBOL_UNTIL = 18,                     /* UNTIL  */
  YYSYMBOL_END_FOR = 19,                   /* END_FOR  */
  YYSYMBOL_STEP = 20,                      /* STEP  */
  YYSYMBOL_CASES = 21,                     /* CASES  */
  YYSYMBOL_VALUE = 22,                     /* VALUE  */
  YYSYMBOL_DEFAULT = 23,                   /* DEFAULT  */
  YYSYMBOL_END_CASES = 24,                 /* END_CASES  */
  YYSYMBOL_DO = 25,                        /* DO  */
  YYSYMBOL_CLEAR = 26,                     /* CLEAR  */
  YYSYMBOL_PLACE = 27,                     /* PLACE  */
  YYSYMBOL_LETFCURLYBRACKET = 28,          /* LETFCURLYBRACKET  */
  YYSYMBOL_RIGHTCURLYBRACKET = 29,         /* RIGHTCURLYBRACKET  */
  YYSYMBOL_ASSIGNMENT = 30,                /* ASSIGNMENT  */
  YYSYMBOL_COMMA = 31,                     /* COMMA  */
  YYSYMBOL_STRING = 32,                    /* STRING  */
  YYSYMBOL_NUMBER = 33,                    /* NUMBER  */
  YYSYMBOL_BOOL = 34,                      /* BOOL  */
  YYSYMBOL_VARIABLE = 35,                  /* VARIABLE  */
  YYSYMBOL_UNDEFINED = 36,                 /* UNDEFINED  */
  YYSYMBOL_CONSTANT = 37,                  /* CONSTANT  */
  YYSYMBOL_BUILTIN = 38,                   /* BUILTIN  */
  YYSYMBOL_OR = 39,                        /* OR  */
  YYSYMBOL_AND = 40,                       /* AND  */
  YYSYMBOL_GREATER_OR_EQUAL = 41,          /* GREATER_OR_EQUAL  */
  YYSYMBOL_LESS_OR_EQUAL = 42,             /* LESS_OR_EQUAL  */
  YYSYMBOL_GREATER_THAN = 43,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN = 44,                 /* LESS_THAN  */
  YYSYMBOL_EQUAL = 45,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 46,                 /* NOT_EQUAL  */
  YYSYMBOL_NOT = 47,                       /* NOT  */
  YYSYMBOL_CONCAT = 48,                    /* CONCAT  */
  YYSYMBOL_PLUS = 49,                      /* PLUS  */
  YYSYMBOL_MINUS = 50,                     /* MINUS  */
  YYSYMBOL_MULTIPLICATION = 51,            /* MULTIPLICATION  */
  YYSYMBOL_DIVISION = 52,                  /* DIVISION  */
  YYSYMBOL_MODULO = 53,                    /* MODULO  */
  YYSYMBOL_INT_DIVISION = 54,              /* INT_DIVISION  */
  YYSYMBOL_LPAREN = 55,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 56,                    /* RPAREN  */
  YYSYMBOL_UNARY = 57,                     /* UNARY  */
  YYSYMBOL_POWER = 58,                     /* POWER  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_program = 60,                   /* program  */
  YYSYMBOL_stmtlist = 61,                  /* stmtlist  */
  YYSYMBOL_stmt = 62,                      /* stmt  */
  YYSYMBOL_block = 63,                     /* block  */
  YYSYMBOL_controlSymbol = 64,             /* controlSymbol  */
  YYSYMBOL_if = 65,                        /* if  */
  YYSYMBOL_dowhile = 66,                   /* dowhile  */
  YYSYMBOL_while = 67,                     /* while  */
  YYSYMBOL_repeat = 68,                    /* repeat  */
  YYSYMBOL_for = 69,                       /* for  */
  YYSYMBOL_cases = 70,                     /* cases  */
  YYSYMBOL_value_list = 71,                /* value_list  */
  YYSYMBOL_default = 72,                   /* default  */
  YYSYMBOL_clear = 73,                     /* clear  */
  YYSYMBOL_place = 74,                     /* place  */
  YYSYMBOL_cond = 75,                      /* cond  */
  YYSYMBOL_asgn = 76,                      /* asgn  */
  YYSYMBOL_print = 77,                     /* print  */
  YYSYMBOL_read = 78,                      /* read  */
  YYSYMBOL_readstring = 79,                /* readstring  */
  YYSYMBOL_exp = 80,                       /* exp  */
  YYSYMBOL_listOfExp = 81,                 /* listOfExp  */
  YYSYMBOL_restOfListOfExp = 82            /* restOfListOfExp  */
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
#define YYLAST   874

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   313


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
      55,    56,    57,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   257,   257,   271,   276,   299,   310,   316,   321,   326,
     331,   336,   342,   348,   354,   360,   365,   370,   376,   381,
     387,   393,   401,   409,   419,   428,   439,   449,   457,   466,
     475,   483,   490,   496,   502,   506,   513,   522,   529,   535,
     542,   547,   553,   561,   568,   574,   581,   587,   592,   597,
     603,   609,   615,   621,   626,   632,   638,   644,   650,   657,
     663,   669,   676,   723,   729,   735,   741,   747,   753,   759,
     765,   771,   781,   786,   797,   802
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
  "COMMENT", "PRINT", "READ", "READ_STRING", "IF", "ELSE", "WHILE", "THEN",
  "END_IF", "END_WHILE", "REPEAT", "FOR", "FROM", "UNTIL", "END_FOR",
  "STEP", "CASES", "VALUE", "DEFAULT", "END_CASES", "DO", "CLEAR", "PLACE",
  "LETFCURLYBRACKET", "RIGHTCURLYBRACKET", "ASSIGNMENT", "COMMA", "STRING",
  "NUMBER", "BOOL", "VARIABLE", "UNDEFINED", "CONSTANT", "BUILTIN", "OR",
  "AND", "GREATER_OR_EQUAL", "LESS_OR_EQUAL", "GREATER_THAN", "LESS_THAN",
  "EQUAL", "NOT_EQUAL", "NOT", "CONCAT", "PLUS", "MINUS", "MULTIPLICATION",
  "DIVISION", "MODULO", "INT_DIVISION", "LPAREN", "RPAREN", "UNARY",
  "POWER", "$accept", "program", "stmtlist", "stmt", "block",
  "controlSymbol", "if", "dowhile", "while", "repeat", "for", "cases",
  "value_list", "default", "clear", "place", "cond", "asgn", "print",
  "read", "readstring", "exp", "listOfExp", "restOfListOfExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-34)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -45,     7,   230,   -45,   -45,   -45,   -45,    57,   -22,   -20,
     -45,   -45,   -45,   -45,   -19,   -45,    50,    -1,   -45,    25,
      26,   -45,   -45,   -45,    55,   -45,   -45,   -45,   -45,   -45,
     -45,    64,    72,    73,    74,   -45,   -45,   -45,   -45,    29,
      57,    57,    57,    57,   761,   -29,   -16,    32,    32,   -45,
      48,    57,   -45,   -45,    57,   362,   664,   664,   -45,   -45,
     -45,   -45,   -45,    57,   152,    30,    30,   681,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    35,    37,    40,    41,    57,    86,
      76,   395,    88,   701,   593,   616,   -45,    25,    26,   -45,
     761,   -45,   761,   640,    52,   -45,   780,   798,   816,   816,
     816,   816,   816,   816,   -36,    28,    28,    30,    30,    30,
      30,    30,   -45,   -45,   -45,   -45,   721,   -45,   -45,    32,
      57,    91,   -45,    57,    57,   -45,   -45,   -45,   329,   428,
     -45,   139,    57,     5,    32,   741,   640,   -45,   -45,   -45,
      57,    20,    57,   110,    92,    76,   112,   -45,   461,   174,
     -45,   119,   -45,   -45,   -45,   -45,    57,   -45,   263,   -45,
     494,   592,   527,   296,   -45,   -45,   560,   -45
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     5,     7,     6,     0,     0,     0,
      22,    22,    22,    22,     0,    22,     0,     0,     3,     0,
       0,     4,    18,    12,     0,    14,    15,    16,    17,    19,
      20,     0,     0,     0,     0,    48,    47,    60,    61,     0,
       0,     0,     0,     0,    42,     0,     0,     0,     0,     3,
       0,     0,     3,    35,     0,     0,     0,     0,    13,     8,
       9,    10,    11,    72,    71,    56,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,    60,    61,    39,
      38,    41,    40,    74,     0,    55,    70,    69,    64,    66,
      63,    65,    67,    68,    49,    50,    51,    52,    53,    58,
      54,    59,    43,    44,    45,    46,     0,     3,     3,     0,
       0,     0,    22,     0,     0,    73,    62,    37,     0,     0,
      27,     0,     0,    34,     0,     0,    74,     3,    23,    26,
       0,     0,     0,     0,     0,    25,     0,    75,     0,     0,
       3,     0,     3,    30,    36,    24,     0,     3,     0,     3,
       0,     0,     0,     0,     3,    28,     0,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -45,   -18,   -45,   -45,   -10,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,   -45,   -44,   -27,   -45,   -45,
     -45,   -31,   -45,   -28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    21,    22,    47,    23,    24,    25,    26,
      27,    28,   143,   154,    29,    30,    89,    31,    32,    33,
      34,    44,   104,   135
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    48,    49,    50,    90,    52,    84,     3,    85,    64,
      65,    66,    67,    77,    78,    79,    80,    81,    82,    86,
      93,    87,    83,    95,   160,   100,   102,   152,   153,    99,
     101,    91,   103,    45,    94,    46,    51,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    53,    54,    56,    57,   126,    58,    68,
      69,    70,    71,    72,    73,    74,    75,    59,    76,    77,
      78,    79,    80,    81,    82,    60,    61,    62,    83,    79,
      80,    81,    82,    92,    63,   140,    83,    88,    83,    35,
      36,   122,    37,   123,    38,    39,   124,   125,   127,   141,
     155,   128,   145,   146,    40,   130,    41,    42,   136,   138,
     139,   151,    43,   142,   162,   164,   163,     0,   157,   159,
       0,   161,   144,   169,     0,     0,     0,     0,     0,   158,
       0,     0,     0,     0,     0,   171,     0,     0,     0,     0,
       0,     0,   168,     0,   170,     0,     0,     0,     0,   172,
       0,   173,     0,     0,     0,     0,   176,   150,    68,    69,
      70,    71,    72,    73,    74,    75,     0,    76,    77,    78,
      79,    80,    81,    82,     0,     0,     0,    83,    68,    69,
      70,    71,    72,    73,    74,    75,     0,    76,    77,    78,
      79,    80,    81,    82,   166,     0,     0,    83,     0,   167,
      76,    77,    78,    79,    80,    81,    82,     0,     0,     0,
      83,     0,     0,    68,    69,    70,    71,    72,    73,    74,
      75,     0,    76,    77,    78,    79,    80,    81,    82,     0,
      -2,     4,    83,     5,     0,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,    12,    13,     0,     0,     0,
       0,    14,     0,     0,     0,    15,    16,    17,    18,     0,
       0,     0,     0,     0,     4,    19,     5,    20,     6,     7,
       8,     9,    10,     0,    11,     0,     0,     0,    12,    13,
       0,     0,     0,     0,    14,   -31,   -31,   -31,    15,    16,
      17,    18,     0,     0,     0,     0,     0,     4,    19,     5,
      20,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,    12,    13,     0,     0,     0,     0,    14,   -32,   -32,
     -32,    15,    16,    17,    18,     0,     0,     0,     0,     0,
       4,    19,     5,    20,     6,     7,     8,     9,    10,   147,
      11,     0,   148,     0,    12,    13,     0,     0,     0,     0,
      14,     0,     0,     0,    15,    16,    17,    18,     0,     0,
       0,     0,     0,     4,    19,     5,    20,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,    12,    13,     0,
       0,     0,     0,    14,     0,     0,     0,    15,    16,    17,
      18,    96,     0,     0,     0,     0,     4,    19,     5,    20,
       6,     7,     8,     9,    10,     0,    11,     0,     0,     0,
      12,    13,     0,   129,     0,     0,    14,     0,     0,     0,
      15,    16,    17,    18,     0,     0,     0,     0,     0,     4,
      19,     5,    20,     6,     7,     8,     9,    10,     0,    11,
       0,     0,   149,    12,    13,     0,     0,     0,     0,    14,
       0,     0,     0,    15,    16,    17,    18,     0,     0,     0,
       0,     0,     4,    19,     5,    20,     6,     7,     8,     9,
      10,     0,    11,     0,   165,     0,    12,    13,     0,     0,
       0,     0,    14,     0,     0,     0,    15,    16,    17,    18,
       0,     0,     0,     0,     0,     4,    19,     5,    20,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,    12,
      13,     0,     0,     0,     0,    14,     0,     0,   -33,    15,
      16,    17,    18,     0,     0,     0,     0,     0,     4,    19,
       5,    20,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,    12,    13,     0,     0,   175,     0,    14,     0,
       0,     0,    15,    16,    17,    18,     0,     0,     0,     0,
       0,     4,    19,     5,    20,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,    12,    13,     0,     0,   177,
       0,    14,     0,     0,     0,    15,    16,    17,    18,     0,
       0,     0,     0,     0,     4,    19,     5,    20,     6,     7,
       8,     9,    10,     0,   132,     0,     0,     0,    12,    13,
       0,     0,     0,     0,    14,     0,     0,   174,    15,    16,
      17,    18,     0,     0,     0,     0,     0,     0,    19,     0,
      20,    68,    69,    70,    71,    72,    73,    74,    75,     0,
      76,    77,    78,    79,    80,    81,    82,   133,     0,     0,
      83,     0,     0,     0,     0,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,    77,    78,    79,    80,    81,
      82,   134,     0,     0,    83,     0,     0,     0,     0,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,    77,
      78,    79,    80,    81,    82,     0,    35,    36,    83,    97,
       0,    98,    39,     0,     0,     0,     0,     0,     0,     0,
       0,    40,     0,    41,    42,     0,     0,     0,     0,    43,
      68,    69,    70,    71,    72,    73,    74,    75,     0,    76,
      77,    78,    79,    80,    81,    82,     0,   105,     0,    83,
      68,    69,    70,    71,    72,    73,    74,    75,     0,    76,
      77,    78,    79,    80,    81,    82,     0,   131,     0,    83,
      68,    69,    70,    71,    72,    73,    74,    75,     0,    76,
      77,    78,    79,    80,    81,    82,     0,   137,     0,    83,
      68,    69,    70,    71,    72,    73,    74,    75,     0,    76,
      77,    78,    79,    80,    81,    82,     0,   156,     0,    83,
      68,    69,    70,    71,    72,    73,    74,    75,     0,    76,
      77,    78,    79,    80,    81,    82,     0,     0,     0,    83,
      69,    70,    71,    72,    73,    74,    75,     0,    76,    77,
      78,    79,    80,    81,    82,     0,     0,     0,    83,    70,
      71,    72,    73,    74,    75,     0,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,    83,   -34,   -34,   -34,
     -34,   -34,   -34,     0,    76,    77,    78,    79,    80,    81,
      82,     0,     0,     0,    83
};

static const yytype_int16 yycheck[] =
{
      18,    11,    12,    13,    48,    15,    35,     0,    37,    40,
      41,    42,    43,    49,    50,    51,    52,    53,    54,    35,
      51,    37,    58,    54,     4,    56,    57,    22,    23,    56,
      57,    49,    63,    55,    52,    55,    55,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,     3,    55,    30,    30,    88,     3,    39,
      40,    41,    42,    43,    44,    45,    46,     3,    48,    49,
      50,    51,    52,    53,    54,     3,     3,     3,    58,    51,
      52,    53,    54,    35,    55,   129,    58,    55,    58,    32,
      33,    56,    35,    56,    37,    38,    56,    56,    12,   130,
     144,    25,   133,   134,    47,    17,    49,    50,    56,   127,
     128,   142,    55,    22,     4,     3,    24,    -1,   146,   150,
      -1,   152,   132,     4,    -1,    -1,    -1,    -1,    -1,   147,
      -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,
      -1,    -1,   160,    -1,   162,    -1,    -1,    -1,    -1,   167,
      -1,   169,    -1,    -1,    -1,    -1,   174,    18,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    58,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    20,    -1,    -1,    58,    -1,    25,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      58,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
       0,     1,    58,     3,    -1,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,     1,    35,     3,    37,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    -1,     1,    35,     3,
      37,     5,     6,     7,     8,     9,    -1,    11,    -1,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
       1,    35,     3,    37,     5,     6,     7,     8,     9,    10,
      11,    -1,    13,    -1,    15,    16,    -1,    -1,    -1,    -1,
      21,    -1,    -1,    -1,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,     1,    35,     3,    37,     5,     6,     7,
       8,     9,    -1,    11,    -1,    -1,    -1,    15,    16,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,     1,    35,     3,    37,
       5,     6,     7,     8,     9,    -1,    11,    -1,    -1,    -1,
      15,    16,    -1,    18,    -1,    -1,    21,    -1,    -1,    -1,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,     1,
      35,     3,    37,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,     1,    35,     3,    37,     5,     6,     7,     8,
       9,    -1,    11,    -1,    13,    -1,    15,    16,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,     1,    35,     3,    37,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,    -1,    15,
      16,    -1,    -1,    -1,    -1,    21,    -1,    -1,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,     1,    35,
       3,    37,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    -1,    15,    16,    -1,    -1,    19,    -1,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,     1,    35,     3,    37,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    -1,    15,    16,    -1,    -1,    19,
      -1,    21,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,     1,    35,     3,    37,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    25,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      37,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    31,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    31,    -1,    -1,    58,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    32,    33,    58,    35,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    49,    50,    -1,    -1,    -1,    -1,    55,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    -1,    58,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    -1,    58,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    -1,    58,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    -1,    58,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    58,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    58,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    58,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    60,    61,     0,     1,     3,     5,     6,     7,     8,
       9,    11,    15,    16,    21,    25,    26,    27,    28,    35,
      37,    62,    63,    65,    66,    67,    68,    69,    70,    73,
      74,    76,    77,    78,    79,    32,    33,    35,    37,    38,
      47,    49,    50,    55,    80,    55,    55,    64,    64,    64,
      64,    55,    64,     3,    55,    61,    30,    30,     3,     3,
       3,     3,     3,    55,    80,    80,    80,    80,    39,    40,
      41,    42,    43,    44,    45,    46,    48,    49,    50,    51,
      52,    53,    54,    58,    35,    37,    35,    37,    55,    75,
      75,    61,    35,    80,    61,    80,    29,    35,    37,    76,
      80,    76,    80,    80,    81,    56,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    56,    56,    56,    56,    80,    12,    25,    18,
      17,    56,    11,    31,    31,    82,    56,    56,    61,    61,
      75,    80,    22,    71,    64,    80,    80,    10,    13,    14,
      18,    80,    22,    23,    72,    75,    56,    82,    61,    80,
       4,    80,     4,    24,     3,    13,    20,    25,    61,     4,
      61,    80,    61,    61,    25,    19,    61,    19
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    63,    64,    65,    65,    66,    67,    68,    69,    69,
      70,    71,    71,    72,    72,    73,    74,    75,    76,    76,
      76,    76,    77,    78,    78,    79,    79,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    81,    82,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     1,     1,     2,     2,
       2,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     6,     8,     6,     6,     5,    10,    12,
       7,     4,     5,     3,     0,     2,     7,     3,     3,     3,
       3,     3,     2,     4,     4,     4,     4,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     3,
       1,     1,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     0,     2,     0,     3
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
#line 258 "interpreter.y"
                  { 
		    // Create a new AST
			(yyval.prog) = new lp::AST((yyvsp[0].stmts)); 

			// Assign the AST to the root
			root = (yyval.prog); 

			// End of parsing
			//	return 1;
		  }
#line 1799 "interpreter.tab.c"
    break;

  case 3: /* stmtlist: %empty  */
#line 271 "interpreter.y"
                  { 
			// create a empty list of statements
			(yyval.stmts) = new std::list<lp::Statement *>(); 
		  }
#line 1808 "interpreter.tab.c"
    break;

  case 4: /* stmtlist: stmtlist stmt  */
#line 277 "interpreter.y"
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
#line 1834 "interpreter.tab.c"
    break;

  case 5: /* stmtlist: stmtlist error  */
#line 300 "interpreter.y"
      { 
			 // just copy up the stmtlist when an error occurs
			 (yyval.stmts) = (yyvsp[-1].stmts);

			 // The previous look-ahead token ought to be discarded with `yyclearin;'
			 yyclearin; 
       }
#line 1846 "interpreter.tab.c"
    break;

  case 6: /* stmt: COMMENT  */
#line 311 "interpreter.y"
        {
		(yyval.st) = new lp::CommentStmt((yyvsp[0].comentario));
		
	
	}
#line 1856 "interpreter.tab.c"
    break;

  case 7: /* stmt: SEMICOLON  */
#line 317 "interpreter.y"
          {
		// Create a new empty statement node
		(yyval.st) = new lp::EmptyStmt(); 
	  }
#line 1865 "interpreter.tab.c"
    break;

  case 8: /* stmt: asgn SEMICOLON  */
#line 322 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1874 "interpreter.tab.c"
    break;

  case 9: /* stmt: print SEMICOLON  */
#line 327 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1883 "interpreter.tab.c"
    break;

  case 10: /* stmt: read SEMICOLON  */
#line 332 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1892 "interpreter.tab.c"
    break;

  case 11: /* stmt: readstring SEMICOLON  */
#line 337 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1901 "interpreter.tab.c"
    break;

  case 12: /* stmt: if  */
#line 343 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1910 "interpreter.tab.c"
    break;

  case 13: /* stmt: dowhile SEMICOLON  */
#line 349 "interpreter.y"
        {
		// Default action
		// $$ = $1;
	 }
#line 1919 "interpreter.tab.c"
    break;

  case 14: /* stmt: while  */
#line 355 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1928 "interpreter.tab.c"
    break;

  case 15: /* stmt: repeat  */
#line 361 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1937 "interpreter.tab.c"
    break;

  case 16: /* stmt: for  */
#line 366 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1946 "interpreter.tab.c"
    break;

  case 17: /* stmt: cases  */
#line 371 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1955 "interpreter.tab.c"
    break;

  case 18: /* stmt: block  */
#line 377 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1964 "interpreter.tab.c"
    break;

  case 19: /* stmt: clear  */
#line 382 "interpreter.y"
        {
		// Default action
		// $$ = $1;
	
	}
#line 1974 "interpreter.tab.c"
    break;

  case 20: /* stmt: place  */
#line 388 "interpreter.y"
        {
		// Default action
		// $$ = $1;
	}
#line 1983 "interpreter.tab.c"
    break;

  case 21: /* block: LETFCURLYBRACKET stmtlist RIGHTCURLYBRACKET  */
#line 394 "interpreter.y"
                {
			// Create a new block of statements node
			(yyval.st) = new lp::BlockStmt((yyvsp[-1].stmts)); 
		}
#line 1992 "interpreter.tab.c"
    break;

  case 22: /* controlSymbol: %empty  */
#line 401 "interpreter.y"
                {
			// To control the interactive mode in "if" and "while" sentences
			control++;
		}
#line 2001 "interpreter.tab.c"
    break;

  case 23: /* if: IF controlSymbol cond THEN stmtlist END_IF  */
#line 410 "interpreter.y"
    {
		// Create a new if statement node
		(yyval.st) = new lp::IfStmt((yyvsp[-3].expNode), (yyvsp[-1].stmts));

		// To control the interactive mode
		control--;
	}
#line 2013 "interpreter.tab.c"
    break;

  case 24: /* if: IF controlSymbol cond THEN stmtlist ELSE stmtlist END_IF  */
#line 420 "interpreter.y"
         {
		// Create a new if statement node
		(yyval.st) = new lp::IfStmt((yyvsp[-5].expNode), (yyvsp[-3].stmts), (yyvsp[-1].stmts));

		// To control the interactive mode
		control--;
	 }
#line 2025 "interpreter.tab.c"
    break;

  case 25: /* dowhile: DO controlSymbol stmtlist WHILE controlSymbol cond  */
#line 429 "interpreter.y"
                {
			// Create a new do-while statement node
			(yyval.st) = new lp::DoWhileStmt((yyvsp[0].expNode), (yyvsp[-3].stmts));

			control--;
			control--;
		}
#line 2037 "interpreter.tab.c"
    break;

  case 26: /* while: WHILE controlSymbol cond DO stmtlist END_WHILE  */
#line 440 "interpreter.y"
                {
			// Create a new while statement node
			(yyval.st) = new lp::WhileStmt((yyvsp[-3].expNode), (yyvsp[-1].stmts));

			// To control the interactive mode
			control--;
    }
#line 2049 "interpreter.tab.c"
    break;

  case 27: /* repeat: REPEAT controlSymbol stmtlist UNTIL cond  */
#line 450 "interpreter.y"
                {
			// Create a new repeat statement node
			(yyval.st) = new lp::RepeatStmt((yyvsp[0].expNode), (yyvsp[-2].stmts));

			control--;
		}
#line 2060 "interpreter.tab.c"
    break;

  case 28: /* for: FOR controlSymbol VARIABLE FROM exp UNTIL exp DO stmtlist END_FOR  */
#line 458 "interpreter.y"
                {
			// Comprobamos en el caso de que la variable ya exista en la tabla de símbolos y la inicializamos al valor INICIAL

			(yyval.st) = new lp::ForStmt((yyvsp[-7].string), (yyvsp[-5].expNode), (yyvsp[-3].expNode), (yyvsp[-1].stmts));

		control --;
		}
#line 2072 "interpreter.tab.c"
    break;

  case 29: /* for: FOR controlSymbol VARIABLE FROM exp UNTIL exp STEP exp DO stmtlist END_FOR  */
#line 467 "interpreter.y"
                {
			// Comprobamos en el caso de que la variable ya exista en la tabla de símbolos y la inicializamos al valor INICIAL
			(yyval.st) = new lp::ForStmt((yyvsp[-9].string), (yyvsp[-7].expNode), (yyvsp[-5].expNode), (yyvsp[-1].stmts), (yyvsp[-3].expNode));

		control --;
		}
#line 2083 "interpreter.tab.c"
    break;

  case 30: /* cases: CASES LPAREN exp RPAREN value_list default END_CASES  */
#line 476 "interpreter.y"
                {
			// Create a new cases statement node
			(yyval.st) = new lp::CasesStmt((yyvsp[-4].expNode), (std::list<lp::ValueStmt *> *) (yyvsp[-2].valuestmts), (lp::DefaultStmt *) (yyvsp[-1].st));
			
		}
#line 2093 "interpreter.tab.c"
    break;

  case 31: /* value_list: VALUE exp COLON stmtlist  */
#line 484 "interpreter.y"
                {
			std::list<lp::ValueStmt *> * stmts = new std::list<lp::ValueStmt *>();
			stmts->push_back(new lp::ValueStmt((yyvsp[-2].expNode), (yyvsp[0].stmts)));
			(yyval.valuestmts) = stmts;
		}
#line 2103 "interpreter.tab.c"
    break;

  case 32: /* value_list: value_list VALUE exp COLON stmtlist  */
#line 491 "interpreter.y"
                {
			(yyval.valuestmts) = (yyvsp[-4].valuestmts);
			(yyval.valuestmts)->push_back(new lp::ValueStmt((yyvsp[-2].expNode), (yyvsp[0].stmts)));
		}
#line 2112 "interpreter.tab.c"
    break;

  case 33: /* default: DEFAULT COLON stmtlist  */
#line 497 "interpreter.y"
                {
			// Create a new default node
			(yyval.st) = new lp::DefaultStmt((yyvsp[0].stmts));
		}
#line 2121 "interpreter.tab.c"
    break;

  case 34: /* default: %empty  */
#line 502 "interpreter.y"
                {
			(yyval.st) = new lp::DefaultStmt(new std::list<lp::Statement *>());
		}
#line 2129 "interpreter.tab.c"
    break;

  case 35: /* clear: CLEAR SEMICOLON  */
#line 507 "interpreter.y"
                {
			// Create a new clear node
			(yyval.st) = new lp::ClearScreenStmt();
		}
#line 2138 "interpreter.tab.c"
    break;

  case 36: /* place: PLACE LPAREN exp COMMA exp RPAREN SEMICOLON  */
#line 514 "interpreter.y"
                {
			// Create a new place node
			(yyval.st) = new lp::PlaceStmt((yyvsp[-4].expNode), (yyvsp[-2].expNode));
		}
#line 2147 "interpreter.tab.c"
    break;

  case 37: /* cond: LPAREN exp RPAREN  */
#line 523 "interpreter.y"
                { 
			(yyval.expNode) = (yyvsp[-1].expNode);
		}
#line 2155 "interpreter.tab.c"
    break;

  case 38: /* asgn: VARIABLE ASSIGNMENT exp  */
#line 530 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (yyvsp[0].expNode));
		}
#line 2164 "interpreter.tab.c"
    break;

  case 39: /* asgn: VARIABLE ASSIGNMENT asgn  */
#line 536 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (lp::AssignmentStmt *) (yyvsp[0].st));
		}
#line 2173 "interpreter.tab.c"
    break;

  case 40: /* asgn: CONSTANT ASSIGNMENT exp  */
#line 543 "interpreter.y"
                {   
 			execerror("Semantic error in assignment: it is not allowed to modify a constant ", (yyvsp[-2].string));
		}
#line 2181 "interpreter.tab.c"
    break;

  case 41: /* asgn: CONSTANT ASSIGNMENT asgn  */
#line 548 "interpreter.y"
                {   
 			execerror("Semantic error in multiple assignment: it is not allowed to modify a constant ",(yyvsp[-2].string));
		}
#line 2189 "interpreter.tab.c"
    break;

  case 42: /* print: PRINT exp  */
#line 554 "interpreter.y"
                {
			// Create a new print node
			 (yyval.st) = new lp::PrintStmt((yyvsp[0].expNode));

		}
#line 2199 "interpreter.tab.c"
    break;

  case 43: /* read: READ LPAREN VARIABLE RPAREN  */
#line 562 "interpreter.y"
                {
			// Create a new read node
			 (yyval.st) = new lp::ReadStmt((yyvsp[-1].string));
		}
#line 2208 "interpreter.tab.c"
    break;

  case 44: /* read: READ LPAREN CONSTANT RPAREN  */
#line 569 "interpreter.y"
                {   
 			execerror("Semantic error in \"read statement\": it is not allowed to modify a constant ",(yyvsp[-1].string));
		}
#line 2216 "interpreter.tab.c"
    break;

  case 45: /* readstring: READ_STRING LPAREN VARIABLE RPAREN  */
#line 575 "interpreter.y"
                {
			// Create a new read string node
			 (yyval.st) = new lp::ReadStringStmt((yyvsp[-1].string));
		}
#line 2225 "interpreter.tab.c"
    break;

  case 46: /* readstring: READ_STRING LPAREN CONSTANT RPAREN  */
#line 582 "interpreter.y"
                {   
 			execerror("Semantic error in \"read string statement\": it is not allowed to modify a constant ",(yyvsp[-1].string));
		}
#line 2233 "interpreter.tab.c"
    break;

  case 47: /* exp: NUMBER  */
#line 588 "interpreter.y"
                { 
			// Create a new number node
			(yyval.expNode) = new lp::NumberNode((yyvsp[0].number));
		}
#line 2242 "interpreter.tab.c"
    break;

  case 48: /* exp: STRING  */
#line 593 "interpreter.y"
                {
			// Create a new string node
			(yyval.expNode) = new lp::StringNode((yyvsp[0].cadena));
		}
#line 2251 "interpreter.tab.c"
    break;

  case 49: /* exp: exp CONCAT exp  */
#line 598 "interpreter.y"
                {
			// Create a new concatenation node
			(yyval.expNode) = new lp::ConcatNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2260 "interpreter.tab.c"
    break;

  case 50: /* exp: exp PLUS exp  */
#line 604 "interpreter.y"
                { 
			// Create a new plus node
			 (yyval.expNode) = new lp::PlusNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		 }
#line 2269 "interpreter.tab.c"
    break;

  case 51: /* exp: exp MINUS exp  */
#line 610 "interpreter.y"
        {
			// Create a new minus node
			(yyval.expNode) = new lp::MinusNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2278 "interpreter.tab.c"
    break;

  case 52: /* exp: exp MULTIPLICATION exp  */
#line 616 "interpreter.y"
                { 
			// Create a new multiplication node
			(yyval.expNode) = new lp::MultiplicationNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2287 "interpreter.tab.c"
    break;

  case 53: /* exp: exp DIVISION exp  */
#line 622 "interpreter.y"
                {
		  // Create a new division node	
		  (yyval.expNode) = new lp::DivisionNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
	   }
#line 2296 "interpreter.tab.c"
    break;

  case 54: /* exp: exp INT_DIVISION exp  */
#line 627 "interpreter.y"
                {
		  // Create a new integer division node	
		  (yyval.expNode) = new lp::IntDivisionNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
	   }
#line 2305 "interpreter.tab.c"
    break;

  case 55: /* exp: LPAREN exp RPAREN  */
#line 633 "interpreter.y"
        { 
		    // just copy up the expression node 
			(yyval.expNode) = (yyvsp[-1].expNode);
		 }
#line 2314 "interpreter.tab.c"
    break;

  case 56: /* exp: PLUS exp  */
#line 639 "interpreter.y"
                { 
		  // Create a new unary plus node	
  		  (yyval.expNode) = new lp::UnaryPlusNode((yyvsp[0].expNode));
		}
#line 2323 "interpreter.tab.c"
    break;

  case 57: /* exp: MINUS exp  */
#line 645 "interpreter.y"
                { 
		  // Create a new unary minus node	
  		  (yyval.expNode) = new lp::UnaryMinusNode((yyvsp[0].expNode));
		}
#line 2332 "interpreter.tab.c"
    break;

  case 58: /* exp: exp MODULO exp  */
#line 651 "interpreter.y"
                {
		  // Create a new modulo node	

		  (yyval.expNode) = new lp::ModuloNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
       }
#line 2342 "interpreter.tab.c"
    break;

  case 59: /* exp: exp POWER exp  */
#line 658 "interpreter.y"
        { 
		  // Create a new power node	
  		  (yyval.expNode) = new lp::PowerNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2351 "interpreter.tab.c"
    break;

  case 60: /* exp: VARIABLE  */
#line 664 "interpreter.y"
                {
		  // Create a new variable node	
		  (yyval.expNode) = new lp::VariableNode((yyvsp[0].string));
		}
#line 2360 "interpreter.tab.c"
    break;

  case 61: /* exp: CONSTANT  */
#line 670 "interpreter.y"
                {
		  // Create a new constant node	
		  (yyval.expNode) = new lp::ConstantNode((yyvsp[0].string));

		}
#line 2370 "interpreter.tab.c"
    break;

  case 62: /* exp: BUILTIN LPAREN listOfExp RPAREN  */
#line 677 "interpreter.y"
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
#line 2420 "interpreter.tab.c"
    break;

  case 63: /* exp: exp GREATER_THAN exp  */
#line 724 "interpreter.y"
                {
		  // Create a new "greater than" node	
 			(yyval.expNode) = new lp::GreaterThanNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2429 "interpreter.tab.c"
    break;

  case 64: /* exp: exp GREATER_OR_EQUAL exp  */
#line 730 "interpreter.y"
                {
		  // Create a new "greater or equal" node	
 			(yyval.expNode) = new lp::GreaterOrEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2438 "interpreter.tab.c"
    break;

  case 65: /* exp: exp LESS_THAN exp  */
#line 736 "interpreter.y"
                {
		  // Create a new "less than" node	
 			(yyval.expNode) = new lp::LessThanNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2447 "interpreter.tab.c"
    break;

  case 66: /* exp: exp LESS_OR_EQUAL exp  */
#line 742 "interpreter.y"
                {
		  // Create a new "less or equal" node	
 			(yyval.expNode) = new lp::LessOrEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2456 "interpreter.tab.c"
    break;

  case 67: /* exp: exp EQUAL exp  */
#line 748 "interpreter.y"
                {
		  // Create a new "equal" node	
 			(yyval.expNode) = new lp::EqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2465 "interpreter.tab.c"
    break;

  case 68: /* exp: exp NOT_EQUAL exp  */
#line 754 "interpreter.y"
                {
		  // Create a new "not equal" node	
 			(yyval.expNode) = new lp::NotEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2474 "interpreter.tab.c"
    break;

  case 69: /* exp: exp AND exp  */
#line 760 "interpreter.y"
                {
		  // Create a new "logic and" node	
 			(yyval.expNode) = new lp::AndNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2483 "interpreter.tab.c"
    break;

  case 70: /* exp: exp OR exp  */
#line 766 "interpreter.y"
                {
		  // Create a new "logic or" node	
 			(yyval.expNode) = new lp::OrNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2492 "interpreter.tab.c"
    break;

  case 71: /* exp: NOT exp  */
#line 772 "interpreter.y"
                {
		  // Create a new "logic negation" node	
 			(yyval.expNode) = new lp::NotNode((yyvsp[0].expNode));
		}
#line 2501 "interpreter.tab.c"
    break;

  case 72: /* listOfExp: %empty  */
#line 781 "interpreter.y"
                        {
			    // Create a new list STL
				(yyval.parameters) = new std::list<lp::ExpNode *>(); 
			}
#line 2510 "interpreter.tab.c"
    break;

  case 73: /* listOfExp: exp restOfListOfExp  */
#line 787 "interpreter.y"
                        {
				(yyval.parameters) = (yyvsp[0].parameters);

				// Insert the expression in the list of expressions
				(yyval.parameters)->push_front((yyvsp[-1].expNode));
			}
#line 2521 "interpreter.tab.c"
    break;

  case 74: /* restOfListOfExp: %empty  */
#line 797 "interpreter.y"
                        {
			    // Create a new list STL
				(yyval.parameters) = new std::list<lp::ExpNode *>(); 
			}
#line 2530 "interpreter.tab.c"
    break;

  case 75: /* restOfListOfExp: COMMA exp restOfListOfExp  */
#line 803 "interpreter.y"
                        {
				// Get the list of expressions
				(yyval.parameters) = (yyvsp[0].parameters);

				// Insert the expression in the list of expressions
				(yyval.parameters)->push_front((yyvsp[-1].expNode));
			}
#line 2542 "interpreter.tab.c"
    break;


#line 2546 "interpreter.tab.c"

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

#line 814 "interpreter.y"




