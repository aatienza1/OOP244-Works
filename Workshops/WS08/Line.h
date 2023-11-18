/***********************************************************************
// OOP244 Workshop #8 lab (part 1)
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// File  Line.h
// Version 1.0
// Author   Alicia Atienza
// Description
// Inherits lblshape to create a horizontal line
// Revision History
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 11/17/2023
**********************************************************************/
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include <iostream>
#include "LblShape.h"
using namespace std;
namespace sdds{
	class Line : public LblShape {
	private: 
		int m_length;

	public:
		Line();
		Line(const char* label, int length);
		void getSpecs(istream& istr);
		void draw(ostream& ostr)const;
	};
}

#endif