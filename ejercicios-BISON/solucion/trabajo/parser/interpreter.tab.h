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

#ifndef YY_YY_INTERPRETER_TAB_H_INCLUDED
# define YY_YY_INTERPRETER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    SEMICOLON = 258,               /* SEMICOLON  */
    COLON = 259,                   /* COLON  */
    ALT = 260,                     /* ALT  */
    COMMENT = 261,                 /* COMMENT  */
    PRINT = 262,                   /* PRINT  */
    READ = 263,                    /* READ  */
    READ_STRING = 264,             /* READ_STRING  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    WHILE = 267,                   /* WHILE  */
    THEN = 268,                    /* THEN  */
    END_IF = 269,                  /* END_IF  */
    END_WHILE = 270,               /* END_WHILE  */
    REPEAT = 271,                  /* REPEAT  */
    FOR = 272,                     /* FOR  */
    FROM = 273,                    /* FROM  */
    UNTIL = 274,                   /* UNTIL  */
    END_FOR = 275,                 /* END_FOR  */
    STEP = 276,                    /* STEP  */
    CASES = 277,                   /* CASES  */
    VALUE = 278,                   /* VALUE  */
    DEFAULT = 279,                 /* DEFAULT  */
    END_CASES = 280,               /* END_CASES  */
    DO = 281,                      /* DO  */
    CLEAR = 282,                   /* CLEAR  */
    PLACE = 283,                   /* PLACE  */
    LETFCURLYBRACKET = 284,        /* LETFCURLYBRACKET  */
    RIGHTCURLYBRACKET = 285,       /* RIGHTCURLYBRACKET  */
    ASSIGNMENT = 286,              /* ASSIGNMENT  */
    PLUS_ASSIGNMENT = 287,         /* PLUS_ASSIGNMENT  */
    MINUS_ASSIGNMENT = 288,        /* MINUS_ASSIGNMENT  */
    MULTIPLICATION_ASSIGNMENT = 289, /* MULTIPLICATION_ASSIGNMENT  */
    DIVISION_ASSIGNMENT = 290,     /* DIVISION_ASSIGNMENT  */
    INT_DIVISION_ASSIGNMENT = 291, /* INT_DIVISION_ASSIGNMENT  */
    MODULO_ASSIGNMENT = 292,       /* MODULO_ASSIGNMENT  */
    POWER_ASSIGNMENT = 293,        /* POWER_ASSIGNMENT  */
    COMMA = 294,                   /* COMMA  */
    STRING = 295,                  /* STRING  */
    NUMBER = 296,                  /* NUMBER  */
    BOOL = 297,                    /* BOOL  */
    VARIABLE = 298,                /* VARIABLE  */
    UNDEFINED = 299,               /* UNDEFINED  */
    CONSTANT = 300,                /* CONSTANT  */
    BUILTIN = 301,                 /* BUILTIN  */
    OR = 302,                      /* OR  */
    AND = 303,                     /* AND  */
    GREATER_OR_EQUAL = 304,        /* GREATER_OR_EQUAL  */
    LESS_OR_EQUAL = 305,           /* LESS_OR_EQUAL  */
    GREATER_THAN = 306,            /* GREATER_THAN  */
    LESS_THAN = 307,               /* LESS_THAN  */
    EQUAL = 308,                   /* EQUAL  */
    NOT_EQUAL = 309,               /* NOT_EQUAL  */
    NOT = 310,                     /* NOT  */
    CONCAT = 311,                  /* CONCAT  */
    PLUS = 312,                    /* PLUS  */
    MINUS = 313,                   /* MINUS  */
    MULTIPLICATION = 314,          /* MULTIPLICATION  */
    DIVISION = 315,                /* DIVISION  */
    MODULO = 316,                  /* MODULO  */
    INT_DIVISION = 317,            /* INT_DIVISION  */
    LPAREN = 318,                  /* LPAREN  */
    RPAREN = 319,                  /* RPAREN  */
    UNARY = 320,                   /* UNARY  */
    INCREMENT = 321,               /* INCREMENT  */
    DECREMENT = 322,               /* DECREMENT  */
    POWER = 323                    /* POWER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 148 "interpreter.y"

  double number;
  char * string; 				 /* NEW in example 7 */
  bool logic;						 /* NEW in example 15 */
  char * cadena; 				 /* NUEVO del trabajo final */
  char * comentario;             /* NUEVO del trabajo final */
  lp::ExpNode *expNode;  			 /* NEW in example 16 */
  std::list<lp::ExpNode *>  *parameters;    // New in example 16; NOTE: #include<list> must be in interpreter.l, init.cpp, interpreter.cpp
  std::list<lp::Statement *> *stmts; /* NEW in example 16 */
  lp::Statement *st;				 /* NEW in example 16 */
  lp::AST *prog;					 /* NEW in example 16 */
  std::list<lp::ValueStmt *> *valuestmts; /* NUEVO DEL ULTIMO TRABAJO */
  

#line 147 "interpreter.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INTERPRETER_TAB_H_INCLUDED  */
