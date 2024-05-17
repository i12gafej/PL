/*!
 \file   StringVariable.cpp
    \brief  Code of some functions of StringVariable class
    \author
    \date   2023-05-14
*/

#include <iostream>

#include "StringVariable.hpp"



void lp::StringVariable::read()
{
  // Inherited attributes
   std::cout << "Name of the StringVariable: ";
   std::cin >> this->_name;

   std::cout << "Token of the StringVariable: ";
   std::cin >> this->_token;
   // The \n character is read 
   std::cin.ignore(); 

   std::cout << "Type of the StringVariable: ";
   std::cin >> this->_type;
   // The \n character is read 
   std::cin.ignore();

   std::cout << "Value of the StringVariable: ";
    std::cin >> this->_value;
    // The \n character is read

    std::cin.ignore();
}

void lp::StringVariable::write() const
{
  // Inherited methods
    std::cout << "Name:" << this->getName() << std::endl;
    std::cout << "Token:" << this->getToken() << std::endl;
    std::cout << "Type:" << this->getType() << std::endl;

    // Own method
    std::cout << "Value:" << this->getValue() << std::endl;
}

lp::StringVariable &lp::StringVariable::operator=(const lp::StringVariable &n)
  {
  	// Check that is not the current object
    if (this != &n)
    {
        // Inherited methods
        this->setName(n.getName());

        this->setToken(n.getToken());

        this->setType(n.getType());

        // Own method
        this->setValue(n.getValue());
    }

    return *this;
  }

  /*!
    \namespace lp
    \brief    Name space for the subject Language Processors
  */
namespace lp{
    std::istream &operator>>(std::istream &i, lp::StringVariable &n)
    {
        // Inherited attributes
        i >> n._name;

        i >> n._token;
        // The \n character is read
        i.ignore();

        i >> n._type;
        // The \n character is read
        i.ignore();

        i >> n._token;
        // The \n character is read
        i.ignore();

        i >> n._value;
        // The \n character is read
        i.ignore();

        return i;
    }

    std::ostream &operator<<(std::ostream &o, lp::StringVariable const &n)
    {
        // Inherited attributes
        o << n._name << std::endl;
        o << n._token << std::endl;
        o << n._type << std::endl;

        // Own method
        o << n._value << std::endl;

        return o;
    }


}