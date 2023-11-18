/***********************************************************************
// OOP244 Workshop #8 lab (part 1)
//
// File  Rectangle.cpp
// Version 1.0
// Author   Alicia Atienza
// Description
// The Rectangle class inherits the LblShape class to create a frame with a label inside.
// Revision History
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 11/17/2023
**********************************************************************/

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include <iostream>
#include "LblShape.h"
using namespace std;

namespace sdds {
	class Rectangle : public LblShape {
	private:
		int m_width{};
		int m_height{};
	public:
		Rectangle();
		Rectangle(const char* label, int width, int height);
		void getSpecs(istream& istr);
		void draw(ostream& ostr)const;
	};
}


#endif
