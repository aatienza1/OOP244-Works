/***********************************************************************
// OOP244 Workshop #8 lab (part 1)
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// File  LblShape.h
// Version 1.0
// Author   Alicia Atienza
// Description
// Inherits abstract data
// Revision History
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 11/17/2023
***********************************************************************/
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"
using namespace std;
namespace sdds {
	class LblShape: public Shape {
	private: 
		char* m_label{};
	protected:
		const char* label() const;
	public:
		LblShape();
		LblShape(const char* label);
		~LblShape();
		LblShape(const LblShape& other) = delete;
		LblShape& operator=(const LblShape& other) = delete;
		void getSpecs(istream& istr);
	};
}

#endif