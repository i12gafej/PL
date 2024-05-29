/*!	
	\file   init.hpp
	\brief   Prototype of the function for the initialization of table of symbols
	\author  
	\date    2017-12-5
	\version 1.0
*/

#ifndef _INIT_HPP_
#define _INIT_HPP_

// sin, cos, atan, fabs, ...
#include <math.h>

#include "table.hpp"

// IMPORTANT: This file must be before y.tab.h
#include "../ast/ast.hpp"
///////////////////////////////////////

//  interpreter.tab.h contains the number values of the tokens produced by the parser
#include "../parser/interpreter.tab.h"

///////////////////////////////////////
// NEW in example 13
#include "mathFunction.hpp"
#include "builtinParameter1.hpp"
///////////////////////////////////////

///////////////////////////////////////
// NEW in example 14
#include "builtinParameter0.hpp"
#include "builtinParameter2.hpp"
///////////////////////////////////////

/*!
  \ brief Predefined numeric constants
*/
static struct {
          std::string name ;
	      double value;
	      } numericConstant[] = {
	                    {"pi",    3.14159265358979323846}, /* MODIFICADO en el trabajo final */
	                    {"e",     2.71828182845904523536}, /* MODIFICADO en el trabajo final */
	                    {"gamma", 0.57721566490153286060}, /* MODIFICADO en el trabajo final */
	                    {"deg",  57.29577951308232087680}, /* MODIFICADO en el trabajo final */
	                    {"phi",   1.61803398874989484820}, /* MODIFICADO en el trabajo final */
	                    {"",      0}
	                   };

/*!
  \ brief Predefined logical constants
*/
// NEW in example 16
static struct {
          std::string name ;
	      bool value;
	      } logicalConstant[] = { 
	                    {"verdadero", true}, /* MODIFICADO en el trabajo final */
	                    {"falso", false},    /* MODIFICADO en el trabajo final */
	                    {"",      0}
	                   };

/*!
  \ brief Predefined string constants
*/
 /* AÑADIDO en el trabajo final */
static struct{
			std::string name;
			std::string value;
			} StringConstant[] = {
					{"holamundo", "Hola Mundo"},
					{"adiosmundo", "Adios Mundo"},
					{"", 	""}
					};

// NEW in example 12 
/*!
  \ brief Predefined keywords
*/
static struct {
          std::string name ;
	      int token;
	      } keyword[] = { 
	                    {"escribir", PRINT},			/* MODIFICADO en el trabajo final */
	                    {"leer",  READ},				/* MODIFICADO en el trabajo final */
	                    {"leer_cadena", READ_STRING}, 	/* NUEVO en el trabajo final */
						{"si",	  IF},   	 			/* MODIFICADO en el trabajo final */
						{"entonces", THEN},				/* NUEVO en el trabajo final */
						{"si_no",  ELSE}, 				/* MODIFICADO en el trabajo final */
						{"fin_si", END_IF},  			/* NUEVO en el trabajo final */
						{"mientras", WHILE},			/* MODIFICADO en el trabajo final */
						{"hacer", DO},					/* NUEVO en el trabajo final */
						{"fin_mientras", END_WHILE},	/* NUEVO en el trabajo final */
						{"repetir", REPEAT},			/* NUEVO en el trabajo final */
						{"para", FOR},  				/* NUEVO en el trabajo final */
						{"desde", FROM},				/* NUEVO en el trabajo final */
						{"hasta", UNTIL},				/* NUEVO en el trabajo final */
						{"fin_para", END_FOR},			/* NUEVO en el trabajo final */
						{"paso", STEP},					/* NUEVO en el trabajo final */
						{"casos", CASES},				/* NUEVO en el trabajo final */
						{"valor",VALUE},				/* NUEVO en el trabajo final */
						{"defecto",DEFAULT},			/* NUEVO en el trabajo final */
						{"fin_casos", END_CASES},		/* NUEVO en el trabajo final */
						{"borrar_pantalla", CLEAR},		/* NUEVO en el trabajo final */
						{"lugar", PLACE},				/* NUEVO en el trabajo final */		
	                    {"",      0}
	                   };



// NEW in example 13

static struct {    /* Predefined functions names */ 
                std::string name ;
				lp::TypePointerDoubleFunction_1 function;
              } function_1 [] = {
	                   {"sin",     sin},
		               {"cos",     cos},
		               {"atan",    atan},
		               {"log",     Log},
		               {"log10",   Log10},
		               {"exp",     Exp},
		               {"sqrt",    Sqrt},
		               {"integer", integer},
		               {"abs",     fabs},   
		               {"",       0}
		              };

// NEW in example 14
static struct {   
                std::string name ;
				lp::TypePointerDoubleFunction_0 function;
              } function_0 [] = {
						{"random", Random},
		                {"",       0}
		              };


// NEW in example 14

static struct {    /* Nombres predefinidos de funciones con 2 argumentos */ 
                std::string name ;
				lp::TypePointerDoubleFunction_2 function;
              } function_2 [] = {
	                   {"atan2",   Atan2},
		               {"",       0}
		              };







/*!		
	\brief   Initialize the table of symbols
	\return  void 
*/

void init(lp::Table &t);

// End of _INIT_HPP_
#endif
