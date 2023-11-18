/***********************************************************************
// OOP244 Workshop #8 lab (part 1)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// File  Rectangle.cpp
// Version 1.0
// Author   Alicia Atienza
// Description
// The Rectangle class inherits the LblShape class to create a frame with a label inside.
// Revision History
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 11/17/2023
**********************************************************************/

#define _CRT_WARNINGS_SECURE
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Rectangle.h"

using namespace std;
using namespace sdds;

namespace sdds {
	Rectangle::Rectangle() :LblShape()
	{
		m_width = 0;
		m_height = 0;
	}
	Rectangle::Rectangle(const char* labelName, int width, int height): LblShape(labelName)
	{
		int length = (strlen(label()) + 2);
		// Calculates if stae is valid
		if (height < 3 || width < length) {
			m_width = 0;
			m_height = 0;
		}
		else {
			m_width = width;
			m_height = height;
		}
	}
	void Rectangle::getSpecs(istream& istr)
	{
		// Get the shape from base class
		LblShape::getSpecs(istr);

		// Comma <:^)
		char comma; 
		istr >> m_width >> comma >> m_height;
		istr.ignore(256, '\n'); 
	}
	 void Rectangle::draw(ostream& ostr)const
	{
		if (m_height != 0 && m_width !=0) {
			// First line
			ostr << '+';
			for (int i = 1; i <= m_width - 2; ++i) {
				ostr << '-';
			}
			ostr << '+' << std::endl;

			// Second line
			ostr << '|';
			ostr << std::left << setw(m_width - 2) << label() << '|';
			ostr << std::endl;

			// (m_height - 3) lines
			for (int i = 1; i <= m_height - 3; ++i) {
				ostr << '|';
				ostr << setw(m_width - 2) << std::right << ' ' << '|';
				ostr << endl;
			}

			// Last line
			ostr << '+';
			for (int i = 1; i <= m_width - 2; ++i) {
				ostr << '-';
			}
			ostr << '+';
		}
	}
}