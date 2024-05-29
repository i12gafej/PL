/*! 
  \file interpreter.y
  \brief Grammar file
*/


%{
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

%}

/* In case of a syntactic error, more information is shown */
/* DEPRECATED */
/* %error-verbose */

/* ALTERNATIVA a %error-verbose */
%define parse.error verbose


/* Initial grammar symbol */
%start program

/*******************************************/
/* Data type YYSTYPE  */
/* NEW in example 4 */
%union {
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
  
}

/* Type of the non-terminal symbols */
// New in example 17: cond
%type <expNode> exp cond 


/* New in example 14 */
%type <parameters> listOfExp  restOfListOfExp

%type <valuestmts> value_list
%type <stmts> stmtlist

// New in example 17: if, while, block
%type <st> stmt asgn print read readstring if while block repeat for cases default clear place dowhile

%type <prog> program

/* Defined tokens */

/* Minimum precedence */

/*******************************************/
/* NEW in example 5 */
%token SEMICOLON COLON
/*******************************************/

/*Nuevo del trabajo final*/
%token <comentario> COMMENT
/* Nuevo en el trabajo final: THEN END_IF */
%token PRINT READ READ_STRING IF ELSE WHILE THEN END_IF END_WHILE REPEAT FOR FROM UNTIL END_FOR STEP CASES VALUE DEFAULT END_CASES DO CLEAR PLACE

/* NEW in example 17 */
%token LETFCURLYBRACKET RIGHTCURLYBRACKET

/* NEW in example 7 */
%right ASSIGNMENT

/* NEW in example 14 */
%token COMMA

/*Nuevo del trabajo final*/
%token <cadena> STRING

/*******************************************/
/* MODIFIED in example 4 */
%token <number> NUMBER
/*******************************************/

/*******************************************/
/* NEW in example 15 */
%token <logic> BOOL
/*******************************************/

/* MODIFIED in examples 11, 13 */
%token <string> VARIABLE UNDEFINED CONSTANT BUILTIN




/* Left associativity */

/*******************************************************/
/* NEW in example 15 */
%left OR

%left AND

%nonassoc GREATER_OR_EQUAL LESS_OR_EQUAL GREATER_THAN LESS_THAN  EQUAL NOT_EQUAL

%left NOT

/*Nuevo trabajo final*/
%left CONCAT
/*******************************************************/

/* MODIFIED in example 3 */
%left PLUS MINUS 

%token INCREMENT DECREMENT


/* MODIFIED in example 5 */
%left MULTIPLICATION DIVISION MODULO INT_DIVISION 

%left LPAREN RPAREN

%nonassoc  UNARY

// Maximum precedence 
/* MODIFIED in example 5 */
%right POWER


%%
 //! \name Grammar rules

/* MODIFIED  Grammar in example 16 */

program : stmtlist
		  { 
		    // Create a new AST
			$$ = new lp::AST($1); 

			// Assign the AST to the root
			root = $$; 

			// End of parsing
			//	return 1;
		  }
;

stmtlist:  /* empty: epsilon rule */
		  { 
			// create a empty list of statements
			$$ = new std::list<lp::Statement *>(); 
		  }  

        | stmtlist stmt 
		  { 
			// copy up the list and add the stmt to it
			$$ = $1;
			$$->push_back($2);

			// Control the interative mode of execution of the interpreter
			if (interactiveMode == true && control == 0)
 			{
				for(std::list<lp::Statement *>::iterator it = $$->begin(); 
						it != $$->end(); 
						it++)
				{
					//(*it)->printAST();
					(*it)->evaluate();
					
				}

				// Delete the AST code, because it has already run in the interactive mode.
				$$->clear();
			}
		}

    | stmtlist error 
      { 
			 // just copy up the stmtlist when an error occurs
			 $$ = $1;

			 // The previous look-ahead token ought to be discarded with `yyclearin;'
			 yyclearin; 
       } 
;
 

stmt: COMMENT
	{
		$$ = new lp::CommentStmt($1);
		
	
	} 
	| SEMICOLON  /* Empty statement: ";" */
	  {
		// Create a new empty statement node
		$$ = new lp::EmptyStmt(); 
	  }
	| asgn  SEMICOLON
	  {
		// Default action
		// $$ = $1;
	  }
	| print SEMICOLON
	  {
		// Default action
		// $$ = $1;
	  }
	| read SEMICOLON
	  {
		// Default action
		// $$ = $1;
	  }
	| readstring SEMICOLON
	  {
		// Default action
		// $$ = $1;
	  }
	/*  NEW in example 17 */
	| if 
	 {
		// Default action
		// $$ = $1;
	 }

	| dowhile SEMICOLON
	{
		// Default action
		// $$ = $1;
	 }
	/*  NEW in example 17 */
	| while 
	 {
		// Default action
		// $$ = $1;
	 }

	| repeat 
	 {
		// Default action
		// $$ = $1;
	 }
	| for 
	 {
		// Default action
		// $$ = $1;
	 }
	| cases 
	 {
		// Default action
		// $$ = $1;
	 }
	/*  NEW in example 17 */
	| block 
	 {
		// Default action
		// $$ = $1;
	 }
	| clear 
	{
		// Default action
		// $$ = $1;
	
	}
	| place
	{
		// Default action
		// $$ = $1;
	}
;
block: LETFCURLYBRACKET stmtlist RIGHTCURLYBRACKET  
		{
			// Create a new block of statements node
			$$ = new lp::BlockStmt($2); 
		}
;

controlSymbol:  /* Epsilon rule*/
		{
			// To control the interactive mode in "if" and "while" sentences
			control++;
		}
	;

	/*  MODIFICADO en la última práctica */
if:	/* Simple conditional statement */
	IF controlSymbol cond THEN stmtlist END_IF 
    {
		// Create a new if statement node
		$$ = new lp::IfStmt($3, $5);

		// To control the interactive mode
		control--;
	}

	/* Compound conditional statement */
	| IF controlSymbol cond THEN stmtlist ELSE stmtlist END_IF
	 {
		// Create a new if statement node
		$$ = new lp::IfStmt($3, $5, $7);

		// To control the interactive mode
		control--;
	 }
;
dowhile: DO controlSymbol stmtlist WHILE controlSymbol cond 
		{
			// Create a new do-while statement node
			$$ = new lp::DoWhileStmt($6, $3);

			control--;
			control--;
		}
;

	/*  MODIFICADO en la última práctica */
while:  WHILE controlSymbol cond DO stmtlist END_WHILE
		{
			// Create a new while statement node
			$$ = new lp::WhileStmt($3, $5);

			// To control the interactive mode
			control--;
    }
;
	/*  AÑADIDO en la última práctica */
repeat: REPEAT controlSymbol stmtlist UNTIL cond 
		{
			// Create a new repeat statement node
			$$ = new lp::RepeatStmt($5, $3);

			control--;
		}
;
for: FOR controlSymbol VARIABLE FROM exp UNTIL exp DO stmtlist END_FOR
		{
			// Comprobamos en el caso de que la variable ya exista en la tabla de símbolos y la inicializamos al valor INICIAL

			$$ = new lp::ForStmt($3, $5, $7, $9);

		control --;
		}
	| 
	FOR controlSymbol VARIABLE FROM exp UNTIL exp STEP exp DO stmtlist END_FOR
		{
			// Comprobamos en el caso de que la variable ya exista en la tabla de símbolos y la inicializamos al valor INICIAL
			$$ = new lp::ForStmt($3, $5, $7, $11, $9);

		control --;
		}
;

cases: CASES LPAREN exp RPAREN value_list default END_CASES
		{
			// Create a new cases statement node
			$$ = new lp::CasesStmt($3, (std::list<lp::ValueStmt *> *) $5, (lp::DefaultStmt *) $6);
			
		}
;

value_list: VALUE exp COLON stmtlist
		{
			std::list<lp::ValueStmt *> * stmts = new std::list<lp::ValueStmt *>();
			stmts->push_back(new lp::ValueStmt($2, $4));
			$$ = stmts;
		}
		|
		value_list VALUE exp COLON stmtlist
		{
			$$ = $1;
			$$->push_back(new lp::ValueStmt($3, $5));
		}
;
default: DEFAULT COLON stmtlist
		{
			// Create a new default node
			$$ = new lp::DefaultStmt($3);
		}
		|
		{
			$$ = new lp::DefaultStmt(new std::list<lp::Statement *>());
		}
;
clear: CLEAR SEMICOLON
		{
			// Create a new clear node
			$$ = new lp::ClearScreenStmt();
		}
;

place : PLACE LPAREN exp COMMA exp RPAREN SEMICOLON
		{
			// Create a new place node
			$$ = new lp::PlaceStmt($3, $5);
		}
;


	/*  NEW in example 17 */
cond: 	LPAREN exp RPAREN
		{ 
			$$ = $2;
		}
;


asgn:   VARIABLE ASSIGNMENT exp 
		{ 
			// Create a new assignment node
			$$ = new lp::AssignmentStmt($1, $3);
		}

	|  VARIABLE ASSIGNMENT asgn 
		{ 
			// Create a new assignment node
			$$ = new lp::AssignmentStmt($1, (lp::AssignmentStmt *) $3);
		}

	   /* NEW in example 11 */ 
	| CONSTANT ASSIGNMENT exp 
		{   
 			execerror("Semantic error in assignment: it is not allowed to modify a constant ", $1);
		}
	   /* NEW in example 11 */ 
	| CONSTANT ASSIGNMENT asgn 
		{   
 			execerror("Semantic error in multiple assignment: it is not allowed to modify a constant ",$1);
		}
;

print:  PRINT exp 
		{
			// Create a new print node
			 $$ = new lp::PrintStmt($2);

		}
;	

read:  READ LPAREN VARIABLE RPAREN  
		{
			// Create a new read node
			 $$ = new lp::ReadStmt($3);
		}

  	  /* NEW rule in example 11 */
	| READ LPAREN CONSTANT RPAREN  
		{   
 			execerror("Semantic error in \"read statement\": it is not allowed to modify a constant ",$3);
		}
;

readstring: READ_STRING LPAREN VARIABLE RPAREN  
		{
			// Create a new read string node
			 $$ = new lp::ReadStringStmt($3);
		}

  	  /* NEW rule in example 11 */
	| READ_STRING LPAREN CONSTANT RPAREN  
		{   
 			execerror("Semantic error in \"read string statement\": it is not allowed to modify a constant ",$3);
		}


exp:	NUMBER 
		{ 
			// Create a new number node
			$$ = new lp::NumberNode($1);
		}
	| STRING
		{
			// Create a new string node
			$$ = new lp::StringNode($1);
		}
	| exp CONCAT exp
		{
			// Create a new concatenation node
			$$ = new lp::ConcatNode($1, $3);
		}

	| 	exp PLUS exp 
		{ 
			// Create a new plus node
			 $$ = new lp::PlusNode($1, $3);
		 }

	| 	exp MINUS exp
      	{
			// Create a new minus node
			$$ = new lp::MinusNode($1, $3);
		}

	| 	exp MULTIPLICATION exp 
		{ 
			// Create a new multiplication node
			$$ = new lp::MultiplicationNode($1, $3);
		}

	| 	exp DIVISION exp
		{
		  // Create a new division node	
		  $$ = new lp::DivisionNode($1, $3);
	   }
	| 	exp INT_DIVISION exp
		{
		  // Create a new integer division node	
		  $$ = new lp::IntDivisionNode($1, $3);
	   }

	| 	LPAREN exp RPAREN
       	{ 
		    // just copy up the expression node 
			$$ = $2;
		 }

  	| 	PLUS exp %prec UNARY
		{ 
		  // Create a new unary plus node	
  		  $$ = new lp::UnaryPlusNode($2);
		}

	| 	MINUS exp %prec UNARY
		{ 
		  // Create a new unary minus node	
  		  $$ = new lp::UnaryMinusNode($2);
		}

	|	exp MODULO exp 
		{
		  // Create a new modulo node	

		  $$ = new lp::ModuloNode($1, $3);
       }

	|	exp POWER exp 
     	{ 
		  // Create a new power node	
  		  $$ = new lp::PowerNode($1, $3);
		}

	 | VARIABLE
		{
		  // Create a new variable node	
		  $$ = new lp::VariableNode($1);
		}

	 | CONSTANT
		{
		  // Create a new constant node	
		  $$ = new lp::ConstantNode($1);

		}

	| BUILTIN LPAREN listOfExp RPAREN
		{
			// Get the identifier in the table of symbols as Builtin
			lp::Builtin *f= (lp::Builtin *) table.getSymbol($1);

			// Check the number of parameters 
			if (f->getNParameters() ==  (int) $3->size())
			{
				switch(f->getNParameters())
				{
					case 0:
						{
							// Create a new Builtin Function with 0 parameters node	
							$$ = new lp::BuiltinFunctionNode_0($1);
						}
						break;

					case 1:
						{
							// Get the expression from the list of expressions
							lp::ExpNode *e = $3->front();

							// Create a new Builtin Function with 1 parameter node	
							$$ = new lp::BuiltinFunctionNode_1($1,e);
						}
						break;

					case 2:
						{
							// Get the expressions from the list of expressions
							lp::ExpNode *e1 = $3->front();
							$3->pop_front();
							lp::ExpNode *e2 = $3->front();

							// Create a new Builtin Function with 2 parameters node	
							$$ = new lp::BuiltinFunctionNode_2($1,e1,e2);
						}
						break;

					default:
				  			 execerror("Syntax error: too many parameters for function ", $1);
				} 
			}
			else
	  			 execerror("Syntax error: incompatible number of parameters for function", $1);
		}

	| exp GREATER_THAN exp
	 	{
		  // Create a new "greater than" node	
 			$$ = new lp::GreaterThanNode($1,$3);
		}

	| exp GREATER_OR_EQUAL exp 
	 	{
		  // Create a new "greater or equal" node	
 			$$ = new lp::GreaterOrEqualNode($1,$3);
		}

	| exp LESS_THAN exp 	
	 	{
		  // Create a new "less than" node	
 			$$ = new lp::LessThanNode($1,$3);
		}

	| exp LESS_OR_EQUAL exp 
	 	{
		  // Create a new "less or equal" node	
 			$$ = new lp::LessOrEqualNode($1,$3);
		}

	| exp EQUAL exp 	
	 	{
		  // Create a new "equal" node	
 			$$ = new lp::EqualNode($1,$3);
		}

    | exp NOT_EQUAL exp 	
	 	{
		  // Create a new "not equal" node	
 			$$ = new lp::NotEqualNode($1,$3);
		}

    | exp AND exp 
	 	{
		  // Create a new "logic and" node	
 			$$ = new lp::AndNode($1,$3);
		}

    | exp OR exp 
	 	{
		  // Create a new "logic or" node	
 			$$ = new lp::OrNode($1,$3);
		}

    | NOT exp 
	 	{
		  // Create a new "logic negation" node	
 			$$ = new lp::NotNode($2);
		}
;


listOfExp: 
			/* Empty list of numeric expressions */
			{
			    // Create a new list STL
				$$ = new std::list<lp::ExpNode *>(); 
			}

	|  exp restOfListOfExp
			{
				$$ = $2;

				// Insert the expression in the list of expressions
				$$->push_front($1);
			}
;

restOfListOfExp:
			/* Empty list of numeric expressions */
			{
			    // Create a new list STL
				$$ = new std::list<lp::ExpNode *>(); 
			}

		|	COMMA exp restOfListOfExp
			{
				// Get the list of expressions
				$$ = $3;

				// Insert the expression in the list of expressions
				$$->push_front($2);
			}
;



%%



