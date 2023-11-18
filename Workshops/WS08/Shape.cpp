/***********************************************************************
// OOP244 Workshop #8 lab (part 1)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// File  Shape.cpp
// Version 1.0
// Author   Alicia Atienza
// Description
// Base class for LblShape
// Revision History
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 11/17/2023         
***********************************************************************/
#include <iostream>
#include "Shape.h"

using namespace sdds;
using namespace std;
namespace sdds {
	Shape::~Shape()
	{
		// Virtual :O
	}

	ostream& operator<<(ostream& ostr, const Shape& obj)
	{
		obj.draw(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, Shape& obj)
	{
		obj.getSpecs(istr);
		return istr;
	}
}