/***********************************************************************
// OOP244 Workshop #8 lab (part 1)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// File  Line.cpp
// Version 1.0
// Author   Alicia Atienza
// Description
// Inherits lblshape to create a horizontal line
// Revision History
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 11/17/2023
**********************************************************************/
#include <iostream>
#include <cstring>
#include "Line.h"

using namespace sdds;
using namespace std;

namespace sdds {
	Line::Line() {
		m_length = 0;
	}
	Line::Line(const char* label, int length):LblShape(label) {
		m_length = length;
	}

	void Line::getSpecs(istream& istr)
	{
		// Getting specs
		LblShape::getSpecs(istr);  
		istr >> m_length;
		istr.ignore(256, '\n'); 
	}

	void Line::draw(ostream& ostr)const
	{
		// Checking that length and label are in valid state
		if (m_length > 0 && label() != nullptr) {
			ostr << label() << endl;
			for (int i = 0; i < m_length; ++i) {
				ostr << '=';
			}
		}
	}

}