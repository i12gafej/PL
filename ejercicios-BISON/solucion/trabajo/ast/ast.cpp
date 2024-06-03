/*!	
	\file    ast.cpp
	\brief   Code of funcitons of AST clas
	\author  
	\date    2018-12-13
	\version 1.0
*/
#include <limits>
#include <iostream>
#include <stdlib.h>
#include <string>
// Incluido en el ultimo trabajo
#include <sstream>
#include <list>
#include <cstring>

// Para usar la funciones pow y std::abs
#include <cmath>

#include "ast.hpp"

#include "../table/table.hpp"

// warning
#include "../error/error.hpp"

// Macros for the screen
#include "../includes/macros.hpp"

// 
#include "../table/numericVariable.hpp"
#include "../table/logicalVariable.hpp"
#include "../table/StringVariable.hpp"
#include "../table/StringConstant.hpp"

#include "../table/numericConstant.hpp"
#include "../table/logicalConstant.hpp"

#include "../table/builtinParameter0.hpp"
#include "../table/builtinParameter1.hpp"
#include "../table/builtinParameter2.hpp"

#include "../parser/interpreter.tab.h"



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

extern lp::Table table; //!< Reference to the Table of Symbols


extern lp::AST *root; //!< Reference to the object at the base of the AST


///////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::VariableNode::getType() 
{ 
	// Get the identifier in the table of symbols as Variable
	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

	// Return the type of the Variable
	return var->getType();
}


void lp::VariableNode::printAST() 
{
  std::cout << "VariableNode: " << this->_id;
  std::cout << " (Type: " << this->getType() << ")" << std::endl;
}


double lp::VariableNode::evaluateNumber() 
{ 
	double result = 0.0;

	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as NumericVariable
		lp::NumericVariable *var = (lp::NumericVariable *) table.getSymbol(this->_id);

		// Copy the value of the NumericVariable
		result = var->getValue();
	}
	else
	{
		warning("Runtime error in evaluateNumber(): the variable is not numeric", 
				   this->_id);
	}

	// Return the value of the NumericVariable
	return result;
}


bool lp::VariableNode::evaluateBool() 
{ 
	bool result = false;

	if (this->getType() == BOOL)
	{
		// Get the identifier in the table of symbols as LogicalVariable
		lp::LogicalVariable *var = (lp::LogicalVariable *) table.getSymbol(this->_id);

		// Copy the value of the LogicalVariable
		result = var->getValue();
	}
	else
	{
		warning("Runtime error in evaluateBool(): the variable is not boolean",
				   this->_id);
	}

	// Return the value of the LogicalVariable
	return result;
}
std::string lp::VariableNode::evaluateString() 
{ 
	std::string result = "";

	if (this->getType() == STRING)
	{
		// Get the identifier in the table of symbols as StringVariable
		lp::StringVariable *var = (lp::StringVariable *) table.getSymbol(this->_id);

		// Copy the value of the StringVariable
		result = var->getValue();
	}
	else
	{
		warning("Runtime error in evaluateString(): the variable is not string",
				   this->_id);
	}

	// Return the value of the StringVariable
	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ConstantNode::printAST() 
{
  std::cout << "ConstantNode: " << this->_id;
  std::cout << " (Type: " << this->getType() << ")" << std::endl;
}

int lp::ConstantNode::getType() 
{ 
	// Get the identifier in the table of symbols as Constant
	lp::Constant *var = (lp::Constant *) table.getSymbol(this->_id);

	// Return the type of the Constant
	return var->getType();
}


double lp::ConstantNode::evaluateNumber() 
{ 
	double result = 0.0;

	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as NumericConstant
		lp::NumericConstant *constant = (lp::NumericConstant *) table.getSymbol(this->_id);

		// Copy the value of the NumericConstant
		result = constant->getValue();
	}
	else
	{
		warning("Runtime error in evaluateNumber(): the constant is not numeric", 
				   this->_id);
	}

	// Return the value of the NumericVariable
	return result;
}

bool lp::ConstantNode::evaluateBool() 
{ 
	bool result = false;

	if (this->getType() == BOOL)
	{
		// Get the identifier in the table of symbols as LogicalConstant
		lp::LogicalConstant *constant = (lp::LogicalConstant *) table.getSymbol(this->_id);

		// Copy the value of the LogicalConstant
		result = constant->getValue();
	}
	else
	{
		warning("Runtime error in evaluateBool(): the constant is not boolean",
				   this->_id);
	}

	// Return the value of the LogicalVariable
	return result;
}
std::string lp::ConstantNode::evaluateString() 
{ 
	std::string result = "";

	if (this->getType() == STRING)
	{
		// Get the identifier in the table of symbols as StringConstant
		lp::StringConstant *constant = (lp::StringConstant *) table.getSymbol(this->_id);

		// Copy the value of the StringConstant
		result = constant->getValue();
	}
	else
	{
		warning("Runtime error in evaluateString(): the constant is not string",
				   this->_id);
	}

	// Return the value of the StringVariable
	return result;
}


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
 

int lp::NumberNode::getType()
{
	return NUMBER;
}


void lp::NumberNode::printAST()
{
  std::cout << "NumberNode: " << this->_number << std::endl;
}

double lp::NumberNode::evaluateNumber() 
{ 
    return this->_number; 
}

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
//CREADO PARA LA ÚLTIMA PRACTICA

int lp::StringNode::getType()
{
	return STRING;
}

void lp::StringNode::printAST()
{
  std::cout << "StringNode: " << this->_string << std::endl;
}

std::string lp::StringNode::evaluateString() 
{ 
	return this->_string;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Nuevo de la ÚLTIMA practica
int lp::PreIncrementNode::getType(){
	return NUMBER;
}

void lp::PreIncrementNode::printAST() 
{
  std::cout << "PreIncrementNode: ++"  << std::endl;
  std::cout << "\t"; 
  std::cout << this->_id << std::endl;
}

double lp::PreIncrementNode::evaluateNumber() 
{
	double result = 0.0;
	// Check the type of the expression
	if (table.lookupSymbol(this->_id) == true)
	{
		// Get the identifier in the table of symbols as Variable
		lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

		if(var->getType() == NUMBER)
		{
			// Increment the value of the Variable
			lp::NumericVariable *v = (lp::NumericVariable *) var;
			result= v->getValue();
			v->setValue(result+ 1);
			return v->getValue();
		}
		else
		{
			warning("Runtime error: the variable is not numeric for ", "PreIncrement");
		}

	}
	else
	{
		warning("Runtime error: the variable does not exist ", "PreIncrement");
	}
	return result;
}

void lp::PostIncrementNode::printAST() 
{
  std::cout << "PostIncrementNode: ++"  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
}
int lp::PostIncrementNode::getType(){
	return NUMBER;
}

double lp::PostIncrementNode::evaluateNumber(){
	double result = 0.0;

	// Check the type of the expression
	if (table.lookupSymbol(this->_id) == true)
	{
		// Get the identifier in the table of symbols as Variable
		lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

		if(var->getType() == NUMBER)
		{
			// Increment the value of the Variable
			lp::NumericVariable *v = (lp::NumericVariable *) var;
			result= v->getValue();
			v->setValue(result+ 1);
			return result;
		}
		else
		{
			warning("Runtime error: the variable is not numeric for ", "PostIncrement");
		}

	}
	else
	{
		warning("Runtime error: the variable does not exist ", "PostIncrement");
	}
	return result;
}
int lp::PreDecrementNode::getType(){
	return NUMBER;
}

void lp::PreDecrementNode::printAST() 
{
  std::cout << "PreDecrementNode: ++"  << std::endl;
  std::cout << "\t"; 
  std::cout << this->_id << std::endl;
}

double lp::PreDecrementNode::evaluateNumber() 
{
	double result = 0.0;
	// Check the type of the expression
	if (table.lookupSymbol(this->_id) == true)
	{
		// Get the identifier in the table of symbols as Variable
		lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

		if(var->getType() == NUMBER)
		{
			// Decrement the value of the Variable
			lp::NumericVariable *v = (lp::NumericVariable *) var;
			result = v->getValue();
			v->setValue(result - 1);
			return v->getValue();
		}
		else
		{
			warning("Runtime error: the variable is not numeric for ", "PreDecrement");
		}

	}
	else
	{
		warning("Runtime error: the variable does not exist ", "PreDecrement");
	}
	return result;
}

void lp::PostDecrementNode::printAST() 
{
  std::cout << "PostDecrementNode: ++"  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
}
int lp::PostDecrementNode::getType(){
	return NUMBER;
}

double lp::PostDecrementNode::evaluateNumber(){
	double result = 0.0;

	// Check the type of the expression
	if (table.lookupSymbol(this->_id) == true)
	{
		// Get the identifier in the table of symbols as Variable
		lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

		if(var->getType() == NUMBER)
		{
			// Decrement the value of the Variable
			lp::NumericVariable *v = (lp::NumericVariable *) var;
			result= v->getValue();
			v->setValue(result - 1);
			return result;
		}
		else
		{
			warning("Runtime error: the variable is not numeric for ", "PostDecrement");
		}

	}
	else
	{
		warning("Runtime error: the variable does not exist ", "PostDecrement");
	}
	return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
int lp::NumericUnaryOperatorNode::getType()
{
	int result;

	if(this->_exp->getType() == NUMBER)
	{
		result = NUMBER;
	}
	else
	{
		warning("Runtime error: incompatible types for", "Numeric Unary Operator");
	}

	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::LogicalUnaryOperatorNode::getType()
{
	int result;

	if(this->_exp->getType() == BOOL)
	{
		result = BOOL;
	}
	else
	{
		warning("Runtime error: incompatible types for", "Logical Unary Operator");
	}
	
	return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Nuevo de la ÚLTIMA practica

void lp::AlternativeNode::printAST() 
{
  std::cout << "AlternativeNode: if"  << std::endl;
  std::cout << "\t"; 
  this->_cond->printAST();
  std::cout << "\t"; 
  this->_exp1->printAST();
  std::cout << "\t"; 
  this->_exp2->printAST();
}
int lp::AlternativeNode::getType()
{
	int result = 0;
		
	if (this->_cond->getType() == BOOL && this->_exp1->getType() == this->_exp2->getType())
		result = this->_exp1->getType();
	else
		warning("Runtime error: incompatible types for", "Alternative");

	return	result;
}

bool lp::AlternativeNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		if(this->_cond->evaluateBool())
		{
			result = this->_exp1->evaluateBool();
		}
		else
		{
			result = this->_exp2->evaluateBool();
		}
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "Alternative");
	}

	return result;
}

double lp::AlternativeNode::evaluateNumber() 
{
	double result = 0.0;

	if (this->getType() == NUMBER)
	{
		if(this->_cond->evaluateBool())
		{
			result = this->_exp1->evaluateNumber();
		}
		else
		{
			result = this->_exp2->evaluateNumber();
		}
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "Alternative");
	}

	return result;
}

std::string lp::AlternativeNode::evaluateString() 
{
	std::string result = "";

	if (this->getType() == STRING)
	{
		if(this->_cond->evaluateBool())
		{
			result = this->_exp1->evaluateString();
		}
		else
		{
			result = this->_exp2->evaluateString();
		}
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "Alternative");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::NumericOperatorNode::getType()
{
	int result = 0;
		
	if ( (this->_left->getType() == NUMBER) and (this->_right->getType() == NUMBER))
		result = NUMBER;
	else
		warning("Runtime error: incompatible types for", "Numeric Operator");

	return	result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


int lp::RelationalOperatorNode::getType()
{
	int result = 0;
		
	if ( (this->_left->getType() == NUMBER) and (this->_right->getType() == NUMBER))
		result = BOOL;
	else if ( (this->_left->getType() == BOOL) and (this->_right->getType() == BOOL))
		result = BOOL;
	else if ( (this->_left->getType() == STRING) and (this->_right->getType() == STRING))
		result = BOOL;
	else
		warning("Runtime error: incompatible types for", "Relational Operator");

	return	result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::LogicalOperatorNode:: getType()
{
	int result = 0;
		
	if ( (this->_left->getType() == BOOL) and (this->_right->getType() == BOOL))
	{
		// 
		result = BOOL;
	}
	else
		warning("Runtime error: incompatible types for", "Logical Operator");

	return	result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Nuevo de la ÚLTIMA practica

int lp::StringOperatorNode::getType()
{
	int result = 0;
		
	if ( (this->_left->getType() == STRING) and (this->_right->getType() == STRING))
	{
		// 
		result = STRING;
	}
	else
		warning("Runtime error: incompatible types for", "String Operator");

	return	result;
}


void lp::ConcatNode::printAST() 
{
  std::cout << "ConcatNode: || "<< std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

std::string lp::ConcatNode::evaluateString() 
{
	std::string result = "";

	// Ckeck the types of the expressions
	if (this->getType() == STRING)
	{
		result = this->_left->evaluateString() + this->_right->evaluateString();
	}
	else
	{
		warning("Runtime error: the expressions are not string for ", "StringOperator");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::UnaryMinusNode::printAST() 
{
  std::cout << "UnaryMinusNode: -"  << std::endl;
  std::cout << "\t"; 
  this->_exp->printAST();
}

double lp::UnaryMinusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		// Minus
		result = - this->_exp->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ", "UnaryMinus");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::UnaryPlusNode::printAST() 
{
  std::cout << "UnaryPlusNode: +"  << std::endl;
  std::cout << "\t"; 
  this->_exp->printAST();
}

double lp::UnaryPlusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		result = this->_exp->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ","UnaryPlus");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PlusNode::printAST() 
{
  std::cout << "PlusNode: +"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::PlusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = this->_left->evaluateNumber() + this->_right->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ", "Plus");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::MinusNode::printAST() 
{
  std::cout << "MinusNode: -"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::MinusNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = this->_left->evaluateNumber() - this->_right->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ", "Minus");
	}

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::MultiplicationNode::printAST() 
{
  std::cout << "MultiplicationNode: *"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::MultiplicationNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = this->_left->evaluateNumber() * this->_right->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ","Multiplication");
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::DivisionNode::printAST()
{
  std::cout << "DivisionNode: /" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::DivisionNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		double leftNumber, rightNumber;

		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();
	
		// The divisor is not zero
    	if(std::abs(rightNumber) > ERROR_BOUND)
		{
				result = leftNumber / rightNumber;
		}
		else
		{
			warning("Runtime error", "Division by zero");
		}
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Division");
	}

  return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Nuevo de la ÚLTIMA practica

void lp::IntDivisionNode::printAST()
{
  std::cout << "IntDivisionNode: //" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::IntDivisionNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		double leftNumber, rightNumber;

		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();
	
		// The divisor is not zero
		if(std::abs(rightNumber) > ERROR_BOUND)
		{
				result = (int) leftNumber / (int) rightNumber;
		}
		else
		{
			warning("Runtime error", "Division by zero");
		}
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "IntDivision");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ModuloNode::printAST()
{
  std::cout << "ModuloNode: %" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::ModuloNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		double leftNumber, rightNumber;

		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();
	
    	if(std::abs(rightNumber) > ERROR_BOUND)
				result = (int) leftNumber % (int) rightNumber;
		else
			warning("Runtime error", "Division by zero");
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Modulo");
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PowerNode::printAST() 
{
  std::cout << "PowerNode: ^"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::PowerNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = pow(this->_left->evaluateNumber(), this->_right->evaluateNumber());
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Power");
	}

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
int lp::BuiltinFunctionNode_0::getType()
{
	return	NUMBER;
}


void lp::BuiltinFunctionNode_0::printAST() 
{
  std::cout << "BuiltinFunctionNode_0: "  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
}

double lp::BuiltinFunctionNode_0::evaluateNumber() 
{
	// Get the identifier in the table of symbols as BuiltinParameter0
	lp::BuiltinParameter0 *f = (lp::BuiltinParameter0 *) table.getSymbol(this->_id);

	// Apply the function and copy the result
   	return f->getFunction()();
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::BuiltinFunctionNode_1::getType()
{
	int result = 0;
		
	if (this->_exp->getType() == NUMBER)
		result = NUMBER;
	else
		warning("Runtime error: incompatible type for", "BuiltinFunctionNode_1");

	return	result;
}

void lp::BuiltinFunctionNode_1::printAST() 
{
  std::cout << "BuiltinFunctionNode_1: "  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;  
  std::cout << "\t";
	this->_exp->printAST();
	std::cout << std::endl;
}

double lp::BuiltinFunctionNode_1::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as BuiltinParameter1
		lp::BuiltinParameter1 *f = (lp::BuiltinParameter1 *) table.getSymbol( this->_id);

		// Apply the function to the parameter and copy the result
		result = f->getFunction()(this->_exp->evaluateNumber());
	}
	else
	{
		warning("Runtime error: incompatible type of parameter for ", this->_id);
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::BuiltinFunctionNode_2::getType()
{
	int result = 0;
		
	if (this->_exp1->getType() == this->_exp2->getType())
		result = this->_exp1->getType();
	else
		warning("Runtime error: incompatible types for", "BuiltinFunctionNode_2");

	return	result;
}


void lp::BuiltinFunctionNode_2::printAST() 
{
  std::cout << "BuiltinFunctionNode_2: " << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";
  this->_exp1->printAST();
  std::cout << "\t";
	this->_exp2->printAST();
	std::cout << std::endl;
}

double lp::BuiltinFunctionNode_2::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as BuiltinParameter2
		lp::BuiltinParameter2 *f = (lp::BuiltinParameter2 *) table.getSymbol(this->_id);

		// Apply the function to the parameters and copy the result
	  	result = f->getFunction()(this->_exp1->evaluateNumber(),this->_exp2->evaluateNumber());
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", this->_id);
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::GreaterThanNode::printAST()
{
  std::cout << "GreaterThanNode: >" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::GreaterThanNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		if(this->_left->getType() == STRING && this->_right->getType() == STRING)
		{
			std::string leftString, rightString;
			leftString = this->_left->evaluateString();
			rightString = this->_right->evaluateString();

			result = (leftString > rightString);
		}
		else if(this->_left->getType() == NUMBER && this->_right->getType() == NUMBER)
		{
			double leftNumber, rightNumber;
			leftNumber = this->_left->evaluateNumber();
			rightNumber = this->_right->evaluateNumber();

			result = (leftNumber > rightNumber);
		}
	} 
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Greater than");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::GreaterOrEqualNode::printAST()
{
  std::cout << "GreaterOrEqualNode: >= " << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::GreaterOrEqualNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		if(this->_left->getType() == STRING && this->_right->getType() == STRING)
		{
			std::string leftString, rightString;
			leftString = this->_left->evaluateString();
			rightString = this->_right->evaluateString();

			result = (leftString >= rightString);
		}
		else if(this->_left->getType() == NUMBER && this->_right->getType() == NUMBER)
		{
			double leftNumber, rightNumber;
			leftNumber = this->_left->evaluateNumber();
			rightNumber = this->_right->evaluateNumber();

			result = (leftNumber >= rightNumber);
		}
	}
	
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Greater or equal than");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::LessThanNode::printAST()
{
  std::cout << "LessThanNode: <" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::LessThanNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{	if(this->_left->getType() == STRING && this->_right->getType() == STRING)
		{
			std::string leftString, rightString;
			leftString = this->_left->evaluateString();
			rightString = this->_right->evaluateString();

			result = (leftString < rightString);
		}
		else if(this->_left->getType() == NUMBER && this->_right->getType() == NUMBER)
		{
			double leftNumber, rightNumber;
			leftNumber = this->_left->evaluateNumber();
			rightNumber = this->_right->evaluateNumber();

			result = (leftNumber < rightNumber);
		}
	} 
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Less than");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::LessOrEqualNode::printAST()
{
  std::cout << "LessOrEqualNode: <=" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::LessOrEqualNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		if (this->_left->getType() == STRING && this->_right->getType() == STRING)
		{
			std::string leftString, rightString;
			leftString = this->_left->evaluateString();
			rightString = this->_right->evaluateString();

			result = (leftString <= rightString);
		}
		else if (this->_left->getType() == NUMBER && this->_right->getType() == NUMBER)
		{
			double leftNumber, rightNumber;
			leftNumber = this->_left->evaluateNumber();
			rightNumber = this->_right->evaluateNumber();

			result = (leftNumber <= rightNumber);
		}
	} 
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Less or equal than");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::EqualNode::printAST()
{
  std::cout << "EqualNode: ==" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::EqualNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		switch(this->_left->getType()){
			case NUMBER:
				double leftNumber, rightNumber;
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				// ERROR_BOUND to control the precision of real numbers
				result = ( std::abs(leftNumber - rightNumber) < ERROR_BOUND );
			break;
			case BOOL:
				bool leftBoolean, rightBoolean;
				leftBoolean = this->_left->evaluateBool();
				rightBoolean = this->_right->evaluateBool();

				// 
				result = (leftBoolean == rightBoolean);
				break;
			case STRING:{
				std::string leftString, rightString;
				leftString = this->_left->evaluateString();
				rightString = this->_right->evaluateString();

				//
				result = (leftString == rightString);
				break;}
		  default:
				warning("Runtime error: incompatible types of parameters for ", 
								"Equal operator");				
		}
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", 
						"Equal operator");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::NotEqualNode::printAST()
{
  std::cout << "NotEqualNode: !=" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::NotEqualNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		switch(this->_left->getType()){
			case NUMBER:
				double leftNumber, rightNumber;
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				// ERROR_BOUND to control the precision of real numbers
				result = ( std::abs(leftNumber - rightNumber) >= ERROR_BOUND );
			break;
			case BOOL:
				bool leftBoolean, rightBoolean;
				leftBoolean = this->_left->evaluateBool();
				rightBoolean = this->_right->evaluateBool();

				// 
				result = (leftBoolean != rightBoolean);
				break;
			case STRING:{
				std::string leftString, rightString;
				leftString = this->_left->evaluateString();
				rightString = this->_right->evaluateString();

				//
				result = (leftString != rightString);
				break;}
		  default:
				warning("Runtime error: incompatible types of parameters for ", 
								"Not Equal operator");				
		}
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "Not Equal operator");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AndNode::printAST()
{
  std::cout << "AndNode: &&" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::AndNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		bool leftBool, rightBool;

		leftBool = this->_left->evaluateBool();
		rightBool = this->_right->evaluateBool();

		result = leftBool and rightBool;
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator And");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::OrNode::printAST()
{
  std::cout << "OrNode: ||" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::OrNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		bool leftBool, rightBool;

		leftBool = this->_left->evaluateBool();
		rightBool = this->_right->evaluateBool();

		result = leftBool or rightBool;
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Or");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::NotNode::printAST()
{
  std::cout << "NotNode: !" << std::endl;
  std::cout << "\t";
  this->_exp->printAST();
}

bool lp::NotNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		result = not this->_exp->evaluateBool();
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Not");
	}

	return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Nuevo de la ÚLTIMA practica

void lp::PreIncrementStmt::printAST() 
{
  std::cout << "PreIncrementStmt: ++"  << std::endl;
  std::cout << "\t"; 
  std::cout << this->_id << std::endl;
  
}

void lp::PreIncrementStmt::evaluate() 
{
	// Check the type of the expression
	if (table.lookupSymbol(this->_id) == true)
	{
		// Get the identifier in the table of symbols as Variable
		lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

		if(var->getType() == NUMBER)
		{
			// Increment the value of the Variable
			lp::NumericVariable *v = (lp::NumericVariable *) var;
			v->setValue(v->getValue() + 1);
		}
		else
		{
			warning("Runtime error: the variable is not numeric for ", "PreIncrement");
		}

	}
	else
	{
		warning("Runtime error: the variable does not exist ", "PreIncrement");
	}
}

void lp::PostIncrementStmt::printAST() 
{
  std::cout << "PostIncrementStmt: ++"  << std::endl;
  std::cout << "\t"; 
  std::cout << this->_id << std::endl;
}

void lp::PostIncrementStmt::evaluate() 
{
	// Check the type of the expression
	if (table.lookupSymbol(this->_id) == true)
	{
		// Get the identifier in the table of symbols as Variable
		lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

		if(var->getType() == NUMBER)
		{
			// Increment the value of the Variable
			lp::NumericVariable *v = (lp::NumericVariable *) var;
			v->setValue(v->getValue() + 1);
		}
		else
		{
			warning("Runtime error: the variable is not numeric for ", "PostIncrement");
		}

	}
	else
	{
		warning("Runtime error: the variable does not exist ", "PostIncrement");
	}
}

void lp::PreDecrementStmt::printAST() 
{
  std::cout << "PreDecrementStmt: ++"  << std::endl;
  std::cout << "\t"; 
  std::cout << this->_id << std::endl;
  
}

void lp::PreDecrementStmt::evaluate() 
{
	// Check the type of the expression
	if (table.lookupSymbol(this->_id) == true)
	{
		// Get the identifier in the table of symbols as Variable
		lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

		if(var->getType() == NUMBER)
		{
			// Decrement the value of the Variable
			lp::NumericVariable *v = (lp::NumericVariable *) var;
			v->setValue(v->getValue() - 1);
		}
		else
		{
			warning("Runtime error: the variable is not numeric for ", "PreDecrement");
		}
	}
	else
	{
		warning("Runtime error: the variable does not exist ", "PreDecrement");
	}
}

void lp::PostDecrementStmt::printAST() 
{
  std::cout << "PostDecrementStmt: ++"  << std::endl;
  std::cout << "\t"; 
  std::cout << this->_id << std::endl;
}

void lp::PostDecrementStmt::evaluate() 
{
	// Check the type of the expression
	if (table.lookupSymbol(this->_id) == true)
	{
		// Get the identifier in the table of symbols as Variable
		lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

		if(var->getType() == NUMBER)
		{
			// Decrement the value of the Variable
			lp::NumericVariable *v = (lp::NumericVariable *) var;
			v->setValue(v->getValue() - 1);
		}
		else
		{
			warning("Runtime error: the variable is not numeric for ", "PostDecrement");
		}

	}
	else
	{
		warning("Runtime error: the variable does not exist ", "PostDecrement");
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AssignmentStmt::printAST() 
{
  std::cout << "assignment_node: ="  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";

  // Check the expression
	if (this->_exp != NULL)
	{
	  this->_exp->printAST();
    std::cout << std::endl;
  }
  // this->_asgn is not NULL: multiple assingment
  else 
    this->_asgn->printAST();

}

void lp::AssignmentStmt::evaluate() 
{
	/* Get the identifier in the table of symbols as Variable */
	/* 
		a = 2;
		a = b = 2;

		a: firstVar
		b: secondVar
	*/
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	// Check the expression
	if (this->_exp != NULL)
	{
		// Check the type of the expression of the asgn
		switch(this->_exp->getType())
		{
			case NUMBER:
			{
				double value;
				// evaluate the expression as NUMBER
			 	value = this->_exp->evaluateNumber();

				// Check the type of the first varible
				if (firstVar->getType() == NUMBER)
				{
				  	// Get the identifier in the table of symbols as NumericVariable
					lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value to the identifier in the table of symbols
					v->setValue(value);
				}
				// The type of variable is not NUMBER
				else
				{
					// Delete the variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the variable in the table of symbols as NumericVariable 
					// with the type NUMBER and the value 
					lp::NumericVariable *v = new lp::NumericVariable(this->_id,
											VARIABLE,NUMBER,value);
					table.installSymbol(v);
				}
			}
			break;

			case BOOL:
			{
				bool value;
				// evaluate the expression as BOOL
			 	value = this->_exp->evaluateBool();

				if (firstVar->getType() == BOOL)
				{
				  	// Get the identifier in the table of symbols as LogicalVariable
					lp::LogicalVariable *v = (lp::LogicalVariable *) table.getSymbol(this->_id);

					// Assignment the value to the identifier in the table of symbols
					v->setValue(value);
				}
				// The type of variable is not BOOL
				else
				{
					// Delete the variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the variable in the table of symbols as NumericVariable 
					// with the type BOOL and the value 
					lp::LogicalVariable *v = new lp::LogicalVariable(this->_id,
											VARIABLE,BOOL,value);
					table.installSymbol(v);
				}
			}
			break;

			case STRING:
			{
				std::string value;
				// evaluate the expression as STRING
			 	value = this->_exp->evaluateString();

				if (firstVar->getType() == STRING){
					lp::StringVariable *v = (lp::StringVariable *) table.getSymbol(this->_id);
					v->setValue(value);
				}
				else{
					table.eraseSymbol(this->_id);
					lp::StringVariable *v = new lp::StringVariable(this->_id,
											VARIABLE,STRING,value);
					table.installSymbol(v);
				}
			}
			break;

			default:
				warning("Runtime error: incompatible type of expression for ", "Assigment");
		}

	}

	//////////////////////////////////////////////
	// Allow multiple assigment -> a = b = c = 2;

	else // this->_asgn is not NULL
	{
		// IMPORTANT
		//  evaluate the assigment child
		this->_asgn->evaluate();


		/* Get the identifier of the previous asgn in the table of symbols as Variable */
		lp::Variable *secondVar = (lp::Variable *) table.getSymbol(this->_asgn->_id);

		// Get the type of the variable of the previous asgn
		switch(secondVar->getType())
		{
			case NUMBER:
			{
				/* Get the identifier of the previous asgn in the table of symbols as NumericVariable */
				lp::NumericVariable *secondVar = (lp::NumericVariable *) table.getSymbol(this->_asgn->_id);
				// Check the type of the first variable
				if (firstVar->getType() == NUMBER)
				{
				/* Get the identifier of the first variable in the table of symbols as NumericVariable */
				lp::NumericVariable *firstVar = (lp::NumericVariable *) table.getSymbol(this->_id);
				  	// Get the identifier o f the in the table of symbols as NumericVariable
//					lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value of the second variable to the first variable
					firstVar->setValue(secondVar->getValue());

				}
				// The type of variable is not NUMBER
				else
				{
					// Delete the first variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the first variable in the table of symbols as NumericVariable 
					// with the type NUMBER and the value of the previous variable 
					lp::NumericVariable *firstVar = new lp::NumericVariable(this->_id,
											VARIABLE,NUMBER,secondVar->getValue());
					table.installSymbol(firstVar);
				}
			}
			break;

			case BOOL:
			{
				/* Get the identifier of the previous asgn in the table of symbols as LogicalVariable */
				lp::LogicalVariable *secondVar = (lp::LogicalVariable *) table.getSymbol(this->_asgn->_id);
				// Check the type of the first variable
				if (firstVar->getType() == BOOL)
				{
				/* Get the identifier of the first variable in the table of symbols as LogicalVariable */
				lp::LogicalVariable *firstVar = (lp::LogicalVariable *) table.getSymbol(this->_id);
				  	// Get the identifier o f the in the table of symbols as NumericVariable
//					lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value of the second variable to the first variable
					firstVar->setValue(secondVar->getValue());

				}
				// The type of variable is not BOOL
				else
				{
					// Delete the first variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the first variable in the table of symbols as NumericVariable 
					// with the type BOOL and the value of the previous variable 
					lp::LogicalVariable *firstVar = new lp::LogicalVariable(this->_id,
											VARIABLE,BOOL,secondVar->getValue());
					table.installSymbol(firstVar);
				}
			}
			break;
			case STRING:  // Nuevo de la ÚLTIMA practica
			{
				/* Get the identifier of the previous asgn in the table of symbols as StringVariable */
				lp::StringVariable *secondVar = (lp::StringVariable *) table.getSymbol(this->_asgn->_id);
				// Check the type of the first variable
				if (firstVar->getType() == STRING)
				{
				/* Get the identifier of the first variable in the table of symbols as StringVariable */
				lp::StringVariable *firstVar = (lp::StringVariable *) table.getSymbol(this->_id);
				  	// Get the identifier o f the in the table of symbols as StringVariable
					//lp::StringVariable *n = (lp::StringVariable *) table.getSymbol(this->_id);
				
					// Assignment the value of the second variable to the first variable
					firstVar->setValue(secondVar->getValue());
				}
				else{
					// Delete the first variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the first variable in the table of symbols as StringVariable 
					// with the type STRING and the value of the previous variable 
					lp::StringVariable *firstVar = new lp::StringVariable(this->_id,
											VARIABLE,STRING,secondVar->getValue());
					table.installSymbol(firstVar);
				}
			}
			default:
			{
				warning("Runtime error: incompatible type of expression for ", "Assigment");
			}
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PrintStmt::printAST() 
{
  std::cout << "printASTStmt: printAST"  << std::endl;
  std::cout << "\t";
  this->_exp->printAST();
  std::cout << std::endl;
}


void lp::PrintStmt::evaluate() 
{
	// std::cout << BIYELLOW; 
	// std::cout << "print: ";
	// std::cout << RESET; 

	switch(this->_exp->getType())
	{
		case NUMBER:
				std::cout << this->_exp->evaluateNumber() << std::endl;
				break;
		case BOOL:
			if (this->_exp->evaluateBool())
				std::cout << "verdadero" << std::endl;
			else
				std::cout << "falso" << std::endl;
		
			break;
		case STRING:
		{
			std::string input = this->_exp->evaluateString();
			// En el caso en el que las comillas en "LEER CADENA" sean simples
			if(input[0] == '\'' && input[input.length()-1] == '\'')
				input = input.substr(1, input.length()-2);
			for (std::size_t i = 0; i < input.length(); ++i) {
				char c = input[i];
				if(c == '\\'){
					i++;
					c = input[i];
					
					switch(c){
						case 'n':
							std::cout << '\n';
							break;
						case 't':
							std::cout << '\t';
							break;
						case '\\':
							std::cout << '\\';
							break;
						case '\'':
							std::cout << '\'';
							break;
						default:
							std::cout << c;
							break;
					}
				}
				else{
					std::cout << c;
				}
			}
			std::cout << std::endl;
		}			
		break;

		default:
			warning("Runtime error: incompatible type for ", "print");
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Nuevo de la ÚLTIMA practica

void lp::ClearScreenStmt::printAST() 
{
  std::cout << "ClearScreenStmt"  << std::endl;
}
void lp::ClearScreenStmt::evaluate() 
{
	// Clear the screen
	std::cout << CLEAR_SCREEN;
}

void lp::PlaceStmt::printAST() 
{
  std::cout << "PlaceStmt: place"  << std::endl;
  std::cout << "\t";
  this->_x->printAST();
  std::cout << "\t";
  this->_y->printAST();
  std::cout << std::endl;
}

void lp::PlaceStmt::evaluate() 
{
	// Get the position of the cursor
	if(this->_x->getType() != NUMBER || this->_y->getType() != NUMBER)
	{
		warning("Runtime error: incompatible type for ", "Place");
		return;
	}
	else{
		int x = this->_x->evaluateNumber();
		int y = this->_y->evaluateNumber();

		// Place the cursor in the position (x,y)
		PLACE(x,y);
	}

}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ReadStmt::printAST() 
{
  std::cout << "ReadStmt: read"  << std::endl;
  std::cout << "\t";
  std::cout << this->_id;
  std::cout << std::endl;
}


void lp::ReadStmt::evaluate() 
{   
	double value;
	// std::cout << BIYELLOW; 
	// std::cout << "Insert a numeric value --> " ;
	// std::cout << RESET; 
	std::cin >> value;
	if (std::cin.fail()) {
	
		std::cin.clear();
	
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		warning("Runtime error: incompatible type for ", "Read");
	} else {
		/* Get the identifier in the table of symbols as Variable */
		lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

		// Check if the type of the variable is NUMBER
		if (var->getType() == NUMBER)
		{
			/* Get the identifier in the table of symbols as NumericVariable */
			lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);
							
			/* Assignment the read value to the identifier */
			n->setValue(value);
		}
		// The type of variable is not NUMBER
		else
		{
			// Delete $1 from the table of symbols as Variable
			table.eraseSymbol(this->_id);

				// Insert $1 in the table of symbols as NumericVariable 
			// with the type NUMBER and the read value 
			lp::NumericVariable *n = new lp::NumericVariable(this->_id, 
										VARIABLE,NUMBER,value);

			table.installSymbol(n);
		}
	}

	
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Nuevo de la ÚLTIMA practica

void lp::ReadStringStmt::printAST() 
{
	std::cout << "ReadStringStmt: read"  << std::endl;
	std::cout << "\t";
	std::cout << this->_id;
	std::cout << std::endl;
}

void lp::ReadStringStmt::evaluate()
{
	std::string value;
	std::getline(std::cin, value);

	/* Get the identifier in the table of symbols as Variable */
	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

	// Check if the type of the variable is STRING
	if (var->getType() == STRING)
	{
		/* Get the identifier in the table of symbols as StringVariable */
		lp::StringVariable *s = (lp::StringVariable *) table.getSymbol(this->_id);
						
		/* Assignment the read value to the identifier */
		s->setValue(value);
	}
	// The type of variable is not STRING
	else
	{
		// Delete $1 from the table of symbols as Variable
		table.eraseSymbol(this->_id);

			// Insert $1 in the table of symbols as StringVariable 
		// with the type STRING and the read value 
		lp::StringVariable *s = new lp::StringVariable(this->_id, 
									  VARIABLE,STRING,value);

		table.installSymbol(s);
	}

}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::EmptyStmt::printAST() 
{
  std::cout << "EmptyStmt "  << std::endl;
}

void lp::EmptyStmt::evaluate() 
{
  // Empty
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// CREADO EN LA ÚLTIMA PRÁCTICA

void lp::CommentStmt::printAST() 
{
  std::cout << "CommentStmt: "  << std::endl;
  std::cout << "\t";
  std::cout << this->_comment;
  std::cout << std::endl;
}
void lp::CommentStmt::evaluate() 
{
  // Empty
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// MODIFICADO EN LA ÚLTIMA PRÁCTICA

void lp::IfStmt::printAST() 
{
  std::cout << "IfStmt: "  << std::endl;
  // Condition
  std::cout << "\t";
  this->_cond->printAST();

  // Consequent
  std::list<Statement *>::iterator stmtIter;

  std::cout << "BlockStmt: "  << std::endl;

  for (stmtIter = this->_stmts1->begin(); stmtIter != this->_stmts1->end(); stmtIter++) 
  {
     (*stmtIter)->printAST();
  }

 // The alternative is printASTed if exists
  if (this->_stmts2 != NULL)
  {
	std::cout << "ElseBlockStmt: "  << std::endl;

	for (stmtIter = this->_stmts2->begin(); stmtIter != this->_stmts2->end(); stmtIter++) 
	{
	   (*stmtIter)->printAST();
	}
  }
}


void lp::IfStmt::evaluate() 
{
   // If the condition is true,
	if (this->_cond->evaluateBool() == true ){
     // the consequent is run 
	  	std::list<Statement *>::iterator stmtIter;

		for (stmtIter = this->_stmts1->begin(); stmtIter != this->_stmts1->end(); stmtIter++) 
		{
			(*stmtIter)->evaluate();
		}
	}

    // Otherwise, the alternative is run if exists
	else if (this->_stmts2 != NULL){
		if(this->_cond->evaluateBool() == false ){
			std::list<Statement *>::iterator stmtIter;

			for (stmtIter = this->_stmts2->begin(); stmtIter != this->_stmts2->end(); stmtIter++) 
			{
				(*stmtIter)->evaluate();
			}
		}
		
	}
}




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// MODIFICADO EN LA ÚLTIMA PRÁCTICA

void lp::WhileStmt::printAST() 
{
  std::cout << "WhileStmt: "  << std::endl;
  // Condition
  std::cout << "\t";
  this->_cond->printAST();

  // Body of the while loop
  std::list<Statement *>::iterator stmtIter;

  std::cout << "BlockStmt: "  << std::endl;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
  {
     (*stmtIter)->printAST();
  }

  std::cout << std::endl;
}


void lp::WhileStmt::evaluate() 
{
  // While the condition is true. the body is run 
  while (this->_cond->evaluateBool() == true)
  {	
	  std::list<Statement *>::iterator stmtIter;

	for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
	{
		(*stmtIter)->evaluate();
	}
  }

}

void lp::DoWhileStmt::printAST() 
{
  std::cout << "DoWhileStmt: "  << std::endl;
  // Body of the do-while loop
  std::list<Statement *>::iterator stmtIter;

  std::cout << "BlockStmt: "  << std::endl;

	for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
	{
		(*stmtIter)->printAST();
	}

  // Condition
  std::cout << "\t";
  this->_cond->printAST();
  std::cout << std::endl;
}

void lp::DoWhileStmt::evaluate() 
{
  // The body is run at least once
  do
  {
	std::list<Statement *>::iterator stmtIter;
	
	for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
	{
		
		(*stmtIter)->evaluate();
	}
  }
  while (this->_cond->evaluateBool() == true);
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// MODIFICADO EN LA ÚLTIMA PRÁCTICA

void lp::RepeatStmt::printAST() 
{
  std::cout << "RepeatStmt: "  << std::endl;
  // Body of the repeat loop
  std::list<Statement *>::iterator stmtIter;

  std::cout << "BlockStmt: "  << std::endl;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
  {
	 (*stmtIter)->printAST();
  }

  // Condition
  std::cout << "\t";
  this->_cond->printAST();
  std::cout << std::endl;
}

void lp::RepeatStmt::evaluate()
{
  // The body is run until the condition is true
  do
  {
	std::list<Statement *>::iterator stmtIter;
	

	for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
	{
		(*stmtIter)->evaluate();
	}
  }
  while (this->_cond->evaluateBool() == false);
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// AÑADIDO EN LA ÚLTIMA PRÁCTICA


void lp::ForStmt::printAST() 
{
  std::cout << "ForStmt: "  << std::endl;
  // Initial value
  std::cout << "From: \t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";
  this->_exp1->printAST();

  // Final value
  std::cout << "To: \t";
  this->_exp2->printAST();

  // Step
  std::cout << "Step: \t";
  this->_exp3->printAST();

  // Body of the for loop
  std::list<Statement *>::iterator stmtIter;

  std::cout << "BlockStmt: "  << std::endl;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
  {
	 	(*stmtIter)->printAST();
  }

  std::cout << std::endl;
}

void lp::ForStmt::evaluate() 
{
	if(this->_exp1->getType() == NUMBER && this->_exp2->getType() == NUMBER)
	{
		if(table.lookupSymbol(this->_id) == true)
		{
			
				if(table.getSymbol(this->_id)->getToken() == VARIABLE)
				{
					table.eraseSymbol(this->_id);
					lp::NumericVariable *v = new lp::NumericVariable(this->_id, VARIABLE, NUMBER, this->_exp1->evaluateNumber());
					table.installSymbol(v);
				}
		}
		if(this->_exp3 == NULL)
		{
			this->_exp3 = new NumberNode(1);
			
			if(this->_exp1->evaluateNumber() > this->_exp2->evaluateNumber())
			{
				this->_exp3 = new NumberNode(-1);
			}

		} else {

			if((this->_exp3->evaluateNumber() > 0 && this->_exp1->evaluateNumber() > this->_exp2->evaluateNumber()) || 
			(this->_exp3->evaluateNumber() < 0 && this->_exp1->evaluateNumber() < this->_exp2->evaluateNumber()) )
			{
				warning("For loop is infinite", this->_id);
			}
		}
					// Get the initial value
		double value1 = this->_exp1->evaluateNumber();
		// Get the final value
		double value2 = this->_exp2->evaluateNumber();
		// Get the step
		double value3 = this->_exp3->evaluateNumber();

		// Get the identifier in the table of symbols as NumericVariable
		lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

		if(v != NULL) // En el caso en el que la variable ya exista, se actualiza su valor y se usa
		{
			// The step is not zero
			if (value3 != 0)
			{
				// The step is positive
				if (value1 < value2)
				{
					// The body is run
					for (double i = value1; i <= value2; i += value3)
					{
						v->setValue(i);

						std::list<Statement *>::iterator stmtIter;

						for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
						{
							(*stmtIter)->evaluate();
						}
					}
				}
				// The step is negative
				else
				{
					// The body is run
					for (double i = value1; i >= value2; i += value3)
					{
						v->setValue(i);

						std::list<Statement *>::iterator stmtIter;

						for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
						{
							(*stmtIter)->evaluate();
						}
					}
				}
			}
			else
			{
				warning("Runtime error: the step is zero in the for loop", "");
			}
		}
		
	} else {
		warning("Runtime error: incompatible type of expression for", "For loop");
	}



	
  
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// AÑADIDO EN LA ÚLTIMA PRÁCTICA

void lp::ValueStmt::printAST() 
{
  std::cout << "ValueStmt: ";
  switch(this->getExp()->getType()){
		case NUMBER:{
			std::cout << this->_exp->evaluateNumber() << std::endl;
			break;
		}
		case BOOL:{
			if (this->_exp->evaluateBool())
				std::cout << "verdadero" << std::endl;
			else
				std::cout << "falso" << std::endl;
			break;
		}
		case STRING:{
			std::cout <<this->_exp->evaluateString() << std::endl;
			break;
		}
		case CONSTANT:{
			std::cout <<this->_exp->evaluateNumber() << std::endl;
			break;
		}
		case VARIABLE:{
			VariableNode *v = (VariableNode *) this->_exp;
			switch(v->getType()){
				case NUMBER:{
					std::cout <<this->_exp->evaluateNumber() << std::endl;
					break;
				}
				case BOOL:{
					if (this->_exp->evaluateBool())
						std::cout <<" = \t" << "verdadero" << std::endl;
					else
						std::cout <<" = \t" << "falso" << std::endl;
					break;
				}
				case STRING:{
					std::cout <<" = \t" << this->_exp->evaluateString() << std::endl;
					break;
				}
				default:{
					warning("Runtime error: incompatible type for ", "ValueStmt");
					break;
				}
			}
			break;
		}
		default:{
			warning("Runtime error: incompatible type for ", "ValueStmt");
			break;
		}
	}

  std::cout << "\t\t";
  std::cout << "BlockStmt: "  << std::endl;
  for (std::list<Statement *>::iterator stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
  {
		  std::cout << "\t\t";
    	(*stmtIter)->printAST();
  }
  std::cout << std::endl;
}

void lp::ValueStmt::evaluate(){
	
	for (std::list<Statement *>::iterator stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
	{
		(*stmtIter)->evaluate();
	}
	
}

void lp::DefaultStmt::printAST() 
{
  std::cout << "DefaultStmt: "  << std::endl;
	std::cout << "\t\t";
  std::cout << "BlockStmt: "  << std::endl;
  if(this->isEmpty()){
	std::cout << "Empty "  << std::endl;
  } else{
	for (std::list<Statement *>::iterator stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
	{
			std::cout << "\t\t";
			(*stmtIter)->printAST();
	}
  }
  
  std::cout << std::endl;
  std::cout << std::endl;
}
void lp::DefaultStmt::evaluate(){
	for (std::list<Statement *>::iterator stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
	{
		(*stmtIter)->evaluate();
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// AÑADIDO EN LA ÚLTIMA PRÁCTICA

void lp::CasesStmt::printAST() 
{
  std::cout << "CasesStmt: "  << std::endl;
  std::cout << "\t";
  std::cout << "Expression: " ;
  this->_exp->printAST();
  std::cout << "\t";
  for (std::list<ValueStmt *>::iterator stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
  {
		(*stmtIter)->printAST();
		  std::cout << "\t";
  }
  std::cout << std::endl;
  if(this->_default != NULL){
	  std::cout << "\t";
	  this->_default->printAST();
  }  	
  else{
	std::cout << "\t";
	std::cout << "No default case" << std::endl;
  }
  	

}
void lp::CasesStmt::evaluate(){
	//vemos el tipo de la expresion
	//si es un numero
	bool done = false, error = false;
	switch(this->_exp->getType()){
		case NUMBER:{ 
			double value = this->_exp->evaluateNumber();
			//Recorremos las expresiones de los casos
			for (std::list<ValueStmt *>::iterator stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
			{
				// vemos de que tipo es en cada caso, por si no son tipos compatibles
				if(value == (*stmtIter)->getExp()->evaluateNumber()){
					(*stmtIter)->evaluate();
					done = true;
					break;
				} else {
					warning("Runtime error: incompatible type for ", "CasesStmt");
					error = true;
					break;
				}
			}
			if(!done && !error){
				this->_default->evaluate();
				done = true;
			}
			break;
		}
		case STRING:{ 
			std::string value = this->_exp->evaluateString();
			for (std::list<ValueStmt *>::iterator stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
			{
				if(value == (*stmtIter)->getExp()->evaluateString()){
					(*stmtIter)->evaluate();
					done = true;
					break;
				} else {
					warning("Runtime error: incompatible type for ", "CasesStmt");
					error = true;
					break;
				}
			}
			if(!done && !error){
				this->_default->evaluate();
				done = true;
			}
			break;
		}
		
		case BOOL:{
			bool value = this->_exp->evaluateBool();
			for (std::list<ValueStmt *>::iterator stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
			{
				if(value == (*stmtIter)->getExp()->evaluateBool()){
					(*stmtIter)->evaluate();
					done = true;
					break;
				} else {
					warning("Runtime error: incompatible type for ", "CasesStmt");
					error = true;
					break;
				}
			}
			if(!done && !error){
				this->_default->evaluate();
				done = true;
			}
			break;
		}
		case VARIABLE:{
			VariableNode *v = (VariableNode *) this->_exp;
			for(std::list<ValueStmt *>::iterator stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++){
				//NUMERIC VARIABLE y VARIABLE or CONSTANT
				if(v->getType() == NUMBER){
					if((*stmtIter)->getExp()->evaluateNumber() == v->evaluateNumber()){
						(*stmtIter)->evaluate();
						done = true;
						break;
					}
				}
				//LOGICAL VARIABLE y VARIABLE or CONSTANT
				else if(v->getType() == BOOL){
					if((*stmtIter)->getExp()->evaluateBool() == v->evaluateBool()){
						(*stmtIter)->evaluate();
						done = true;
						break;
					}
				}
				//STRING VARIABLE y VARIABLE or CONSANTE 
				else if(v->getType() == STRING){
					if((*stmtIter)->getExp()->evaluateString() == v->evaluateString()){
						(*stmtIter)->evaluate();
						done = true;
						break;
					}
				}
				else {
					warning("Runtime error: incompatible type for ", "CasesStmt");
					error = true;
					break;
				}
			}
			
			if(!done && !error){
				this->_default->evaluate();
				done = true;
			}
			break;
		}
		case CONSTANT:{
			ConstantNode *v = (ConstantNode *) this->_exp;
			for(std::list<ValueStmt *>::iterator stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++){
				if(v->getType() == NUMBER)
				{
					if(v->evaluateNumber() == (*stmtIter)->getExp()->evaluateNumber()){
						(*stmtIter)->evaluate();
						done = true;
						break;

					}
				} else if(v->getType() == BOOL){
					if(v->evaluateBool() == (*stmtIter)->getExp()->evaluateBool()){
						(*stmtIter)->evaluate();
						done = true;
						break;
					}
				} else if(v->getType() == STRING){
					if(v->evaluateString() == (*stmtIter)->getExp()->evaluateString()){
						(*stmtIter)->evaluate();
						done = true;
						break;
					}
				} else {
					warning("Runtime error: incompatible type for ", "CasesStmt");
					error = true;
					break;
				}
			}
			if(!done && !error){
				this->_default->evaluate();
				done = true;
			}
			break;
		}
		default:{
			warning("Runtime error: incompatible type for ", "CasesStmt");
			break;
		}
	
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

void lp::BlockStmt::printAST() 
{
  std::list<Statement *>::iterator stmtIter;

  std::cout << "BlockStmt: "  << std::endl;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
  {
     (*stmtIter)->printAST();
  }
}


void lp::BlockStmt::evaluate() 
{
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
  {
    (*stmtIter)->evaluate();
  }
}





///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AST::printAST() 
{
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = stmts->begin(); stmtIter != stmts->end(); stmtIter++) 
  {
     (*stmtIter)->printAST();
  }
}



void lp::AST::evaluate() 
{
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = stmts->begin(); stmtIter != stmts->end(); stmtIter++) 
  {
    (*stmtIter)->evaluate();
  }
}

