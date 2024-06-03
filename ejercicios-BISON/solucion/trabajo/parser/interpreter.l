/*! 
  \file interpreter.l
  \brief Lexical or scanner file
*/
%{
#include <iostream>

/*********************/
/* NEW in example 4 */
/* atof */
#include <stdlib.h>
/*********************/

/* Macros for the screen */
#include "../includes/macros.hpp"

/*********************/
/* 
  NEW in example 16 
  AST class
  IMPORTANT: must be written before interpreter.tab.h
*/
#include "../ast/ast.hpp"
/*********************/

/*  interpreter.tab.h contains the numeric values of the tokens produced by the parser */
#include "interpreter.tab.h"

/********************/
/* NEW in example 3 */
#include "../error/error.hpp"
/********************/


/*********************************************/
/* NEW in example 7 */
/* Table of symbols */
#include "../table/table.hpp"

#include "../table/numericVariable.hpp"

extern lp::Table table; //!< External Table of Symbols
/*********************************************/

extern int lineNumber; //!< External line counter

/* uso de strdup */
#include <string.h>
char* imprimir_cadena_sin_comillas(char *yytext, int yyleng){
    int i;
    char* cadena = (char*)malloc(yyleng-1);
    for(i=1; i<yyleng-1; i++){
        cadena[i-1] = yytext[i];
    }
    cadena[yyleng-2] = '\0';
    return cadena;
}
char * imprimir_comentario_sin_exclamaciones(char *yytext, int yyleng){
	int i;
	char* cadena = (char*)malloc(yyleng-2);
	for(i=2; i<yyleng-1; i++){
		cadena[i-2] = yytext[i];
	}
	cadena[yyleng-3] = '\0';
	return cadena;
}
char * imprimir_comentario_sin_signos(char *yytext, int yyleng){
	int i;
	char* cadena = (char*)malloc(yyleng-4);
	for(i=2; i<yyleng-2; i++){
		cadena[i-2] = yytext[i];
	}
	cadena[yyleng-4] = '\0';
	return cadena;
}
void toLowerCase(char *str) {
    if (str == NULL) return;

    while (*str) {
        *str = tolower((unsigned char) *str);
        str++;
    }
}

%}


/*! \name REGULAR DEFINITIONS  */

DIGIT  [0-9] 

LETTER [a-zA-Z]


NUMBER -?[0-9]+(\.[0-9]+)?([eE][-+]?[0-9]+)?

/*MODIFICADO en el trabajo final*/
IDENTIFIER  {LETTER}((_({LETTER}|{DIGIT}))|({LETTER}|{DIGIT}))* 

/* NUEVO en el trabajo final */
SHORTCOMMENT !!.*\n
LONGCOMMENT  <<([^>]|>[^>])*>> 
STRING '([^'\\]|\\.)*'

/* NEW in example 3 */
/* STATE  */
%x ERROR

/*! \name REGULAR EXPRESSIONS  */
%%

[ \t] 	{ ; }    /* skip white space and tabular */

\n      { 
			/* Line counter */
           	lineNumber++; 
	
			/* MODIFIED in example 3 */
			/* COMMENTED in example 5 */
        	/* return NEWLINE; */
        }


";"		{
			/* NEW in example 5 */
			return SEMICOLON;
		}


","		{
			/* NEW in example 14 */
			return COMMA;
		}

{NUMBER}  {
					  /* MODIFIED in example 4 */
					  /* Conversion of type and sending of the numerical value to the parser */
					   yylval.number = atof(yytext); 

                       return NUMBER; 
                      }


{IDENTIFIER}   		 {
						 /* NEW in example 7 */
						 toLowerCase(yytext); /* Nuevo del Trabajo Final */
						 std::string identifier(yytext);

						/* 
                          strdup() function returns a pointer to a new string 
                          which  is a duplicate of the string yytext
                        */
						  yylval.string =  strdup(yytext);

						/* If the identifier is not in the table of symbols then it is inserted */	
						 if (table.lookupSymbol(identifier) == false)
							{
								/* 
								 The identifier is inserted into the symbol table 
								 as undefined Variable with value 0.0
								*/
								lp::NumericVariable *n = new lp::NumericVariable(identifier,VARIABLE,UNDEFINED,0.0);

								/* A pointer to the new NumericVariable is inserted into the table of symbols */
								table.installSymbol(n);

								return VARIABLE;
							}

						/* MODIFIED in example 11 */
						/* 
							If the identifier is in the table of symbols then its token is returned 
								The identifier can be a variable or a numeric constant
						*/
						else 
							{
								lp::Symbol	*s = table.getSymbol(identifier);

/*
								std::cout << "lex: "<< s->getName() 
										  << "token " << s->getToken()
  										  << std::endl; 
*/

								/*  If the identifier is in the table then its token is returned  */
								return s->getToken();
							}
                     }
{STRING}	{ yylval.cadena = imprimir_cadena_sin_comillas(yytext, yyleng); 
				return STRING; }

"-"		{ return MINUS;  } 			
"+"		{ return PLUS;   } 
"++" 	{ return INCREMENT; }		/* NUEVO en el trabajo final */
"--"    { return DECREMENT; }		/* NUEVO en el trabajo final */
"+:="	{ return PLUS_ASSIGNMENT; }	/* NUEVO en el trabajo final */
"-:="	{ return MINUS_ASSIGNMENT; }	/* NUEVO en el trabajo final */
"*:="	{ return MULTIPLICATION_ASSIGNMENT; }	/* NUEVO en el trabajo final */
"/:="	{ return DIVISION_ASSIGNMENT; }	/* NUEVO en el trabajo final */
"//:="	{ return INT_DIVISION_ASSIGNMENT; }	/* NUEVO en el trabajo final */
"%:="	{ return MODULO_ASSIGNMENT; }	/* NUEVO en el trabajo final */
"**:="	{ return POWER_ASSIGNMENT; }	/* NUEVO en el trabajo final */

"*"	    { return MULTIPLICATION; } 	
"/"     { return DIVISION; } 		
"//"	{ return INT_DIVISION; }		/* NUEVO en el trabajo final */

"("     { return LPAREN; } 			
")"	    { return RPAREN; } 			



"%"     { return MODULO; }			

"**"	    { return POWER; }			/* MODIFICADO en el trabajo final */

":=" 	{ return ASSIGNMENT; }		


"="	{ return EQUAL; }			

"<>"	{ return NOT_EQUAL; }		/* MODIFICADO en el trabajo final */

">="	{ return GREATER_OR_EQUAL; }

"<="	{ return LESS_OR_EQUAL; }	

">"		{ return GREATER_THAN; }	

"<"		{ return LESS_THAN; }		

"#no"		{ return NOT; }				/* MODIFICADO en el trabajo final */

"#o"	{ return OR; }				/* MODIFICADO en el trabajo final */

"#y"	{ return AND; }				/* MODIFICADO en el trabajo final */

"{"		{ return LETFCURLYBRACKET; } 	

"}"		{ return RIGHTCURLYBRACKET; }

"?" 	{ return ALT; }			/* NUEVO en el trabajo final */

":"		{ return COLON; }			/* NUEVO en el trabajo final */


{SHORTCOMMENT}|{LONGCOMMENT} {int n = yyleng;
								char * cadena = NULL;
								if(yytext[0] == '!'){
									// cadena = (char *)malloc(n-2);
									// for(i=2; i<n-1; i++){
									// 	cadena[i-2] = yytext[i];
									// }
									// cadena[n-3] = '\0';
									cadena = imprimir_comentario_sin_exclamaciones(yytext, n);
								}
								else{
									// cadena = (char *)malloc(n-4);
									// for(i=2; i<n-2; i++){
									// 	cadena[i-2] = yytext[i];
									// }
									// cadena[n-4] = '\0';
									cadena = imprimir_comentario_sin_signos(yytext, n);
								}
								yylval.comentario = cadena;
								return COMMENT; 
								}/* NUEVO en el trabajo final */

"||" 	{ return CONCAT; } /* NUEVO en el trabajo final */

		/* NUEVO en el trabajo final */




<<EOF>> { /* The interpreter finishes when finds the end of file character */
		/*  PLACE(24,10);
	  	  std::cout <<  BICYAN;
	   	  std::cout <<  ">>>>>>> End of program <<<<<<<";
	 	  std::cout << std::endl;
	   	  std::cout << RESET;
		  PLACE(25,1);
		*/
	  	  return 0;
	}


.								{ 	
									/* Any other character */
									/* MODIFIIED in example 3 */
									/* Change to error state */
									BEGIN(ERROR); 

									/* 
										The current value of yytext 
										will be concatenated with the next character
									*/
									yymore();  
								}

<ERROR>[^0-9+\-*/()\^% \t\n\;a-zA-Z=<>!&_]	{ /* MODIFICADO en el trabajo final */
								  /* NEW in example 3 */
								  /* 
									The current value of yytext 
									will be concatenated with the next character
								  */
									yymore(); 
								}

<ERROR>(.|\n)                { 
								/* NEW in example 3 */
								/* Rewind one position */
								yyless(yyleng-1); 

								/* Display the error message */
								warning("Lexical error", yytext);

								/* Restore the initial state */
   								BEGIN(INITIAL);
							}
%%

