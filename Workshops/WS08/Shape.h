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

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

using namespace std;
namespace sdds{
	class Shape {
	public:
		virtual void draw(ostream& ostr) const = 0;
		virtual void getSpecs(istream& istr) = 0;
		virtual ~Shape();
	};
	ostream& operator<<(ostream& ostr, const Shape& obj);
	istream& operator>>(istream& istr, Shape& obj);
}

#endif //SDDS_SHAPE_H