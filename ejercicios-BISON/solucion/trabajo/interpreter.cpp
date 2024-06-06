/*! 
  \file interpreter.cpp
  \brief Main program
*/

/*!
 \mainpage Flex and Bison: example 17
 \author   
 \date     2018 - 4 - 26
 \version  1.0
 \note Novelties
	+ AST: intermidiate code
	+ New statements: if, while, block
*/



// New in example 2
#include <stdio.h>
#include <string>
//

/////////////////////////////
/* 
  NEW in example 16 
  AST class
  IMPORTANT: must be written before interpreter.tab.h
*/
#include "ast/ast.hpp"
////////////////////////////////////////

#include "./parser/interpreter.tab.h"

int lineNumber = 1; //!< Line counter

/* NEW in example 15 */
bool interactiveMode; //!< Control the interactive mode of execution of the interpreter

/* NEW in example 17 */
int control = 0; //!< To control the interactive mode in "if" and "while" sentences 


// New in example 2
extern FILE * yyin; //!< Standard input device for yylex() 
std::string progname; //!<  Program name
//


//////////////////////////////////////////////
// NEW in example 6 

// Use for recovery of runtime errors 
#include <setjmp.h>
#include <signal.h>

// Error recovery functions 
#include "error/error.hpp"


lp::AST *root; //!< Root of the abstract syntax tree AST
///////////////////////////////////////////// 

//////////////////////////////////////////////
// NEW in example 10 

#include "table/init.hpp"


/*
 jhmp_buf
    This is an array type capable of storing the information of a calling environment to be restored later.
   This information is filled by calling macro setjmp and can be restored by calling function longjmp.
*/
extern jmp_buf begin; //!<  It enables recovery of runtime errors 

//////////////////////////////////////////////
// NEW in example 7 

#include "table/table.hpp"

lp::Table table; //!< Table of Symbols



// cout.precision
#include <iostream>
//////////////////////////////////////////////////

//! \name Main program

/*! 
	\brief  Main function
	\param  argc: number of command line parameters
	\param  argv: values of command line parameters
	\return int
	\note   C++ requires that main returns an int value
	\sa     yyparse, yylex
*/
int main(int argc, char *argv[])
{
	/* Option -t needed to debug */
    /* 1, on; 0, off */
	yydebug = 0; 
 
 /* 
  Si no existe el archivo
    modo interactivo
  si existe
    comprueba la extensión
      si es .e
        se establece como dispositivo de entrada para yylex();
        modo no interactivo
      si no
        el dispositivo de entrada es el teclado (stdin)
 */
 if (argc == 2) 
 {
     yyin = fopen(argv[1],"r");
     if(yyin == NULL)
     {
        std::cout << "Archivo " << argv[1] << " no existe. \nIniciando en modo interactivo." << std::endl;
        interactiveMode = true;
     } 
     else{
        std::string arg = argv[1];
        if(arg.find(".e") != std::string::npos){
          interactiveMode = false;
        }
        else{
          yyin = stdin;
          std::cout << "Archivo " << argv[1] << " no es de extensión .e. \nIniciando en modo interactivo." << std::endl;
          interactiveMode = true;
        }
     }
 }
else
 {
	interactiveMode = true;
 }

 // Copy the name of the interpreter 
	progname = argv[0];

 /* Number of decimal places */ 
 std::cout.precision(7);

 /* 
   Table of symbols initialization 
   Must be written before the recovery sentence: setjmp
 */
   init(table);

/* Sets a viable state to continue after a runtime error */
 setjmp(begin);

 /* The name of the function to handle floating-point errors is set */
 signal(SIGFPE,fpecatch);

 // Parser function
  yyparse();

 if (interactiveMode == false)
 {
  if(root != NULL){/* NEW in example 15 */
       //root->printAST();  
       root->evaluate(); 
  }
 }

 /* End of program */
 return 0;
}



