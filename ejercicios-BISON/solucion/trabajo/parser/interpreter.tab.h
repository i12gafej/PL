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
    COMMENT = 260,                 /* COMMENT  */
    PRINT = 261,                   /* PRINT  */
    READ = 262,                    /* READ  */
    READ_STRING = 263,             /* READ_STRING  */
    IF = 264,                      /* IF  */
    ELSE = 265,                    /* ELSE  */
    WHILE = 266,                   /* WHILE  */
    THEN = 267,                    /* THEN  */
    END_IF = 268,                  /* END_IF  */
    END_WHILE = 269,               /* END_WHILE  */
    REPEAT = 270,                  /* REPEAT  */
    FOR = 271,                     /* FOR  */
    FROM = 272,                    /* FROM  */
    UNTIL = 273,                   /* UNTIL  */
    END_FOR = 274,                 /* END_FOR  */
    STEP = 275,                    /* STEP  */
    CASES = 276,                   /* CASES  */
    VALUE = 277,                   /* VALUE  */
    DEFAULT = 278,                 /* DEFAULT  */
    END_CASES = 279,               /* END_CASES  */
    DO = 280,                      /* DO  */
    CLEAR = 281,                   /* CLEAR  */
    PLACE = 282,                   /* PLACE  */
    LETFCURLYBRACKET = 283,        /* LETFCURLYBRACKET  */
    RIGHTCURLYBRACKET = 284,       /* RIGHTCURLYBRACKET  */
    ASSIGNMENT = 285,              /* ASSIGNMENT  */
    COMMA = 286,                   /* COMMA  */
    STRING = 287,                  /* STRING  */
    NUMBER = 288,                  /* NUMBER  */
    BOOL = 289,                    /* BOOL  */
    VARIABLE = 290,                /* VARIABLE  */
    UNDEFINED = 291,               /* UNDEFINED  */
    CONSTANT = 292,                /* CONSTANT  */
    BUILTIN = 293,                 /* BUILTIN  */
    OR = 294,                      /* OR  */
    AND = 295,                     /* AND  */
    GREATER_OR_EQUAL = 296,        /* GREATER_OR_EQUAL  */
    LESS_OR_EQUAL = 297,           /* LESS_OR_EQUAL  */
    GREATER_THAN = 298,            /* GREATER_THAN  */
    LESS_THAN = 299,               /* LESS_THAN  */
    EQUAL = 300,                   /* EQUAL  */
    NOT_EQUAL = 301,               /* NOT_EQUAL  */
    NOT = 302,                     /* NOT  */
    CONCAT = 303,                  /* CONCAT  */
    PLUS = 304,                    /* PLUS  */
    MINUS = 305,                   /* MINUS  */
    MULTIPLICATION = 306,          /* MULTIPLICATION  */
    DIVISION = 307,                /* DIVISION  */
    MODULO = 308,                  /* MODULO  */
    INT_DIVISION = 309,            /* INT_DIVISION  */
    LPAREN = 310,                  /* LPAREN  */
    RPAREN = 311,                  /* RPAREN  */
    UNARY = 312,                   /* UNARY  */
    POWER = 313                    /* POWER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 147 "interpreter.y"

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
  

#line 137 "interpreter.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INTERPRETER_TAB_H_INCLUDED  */
