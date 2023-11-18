/***********************************************************************
// OOP244 Workshop #8 lab (part 1)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// File  LblShape.cpp
// Version 1.0
// Author   Alicia Atienza
// Description
// Inherits abstract data 
// Revision History
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 11/17/2023
**********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LblShape.h"

using namespace std;
using namespace sdds;

namespace sdds {
	const char* LblShape::label()const
	{
		// Returning m_label for other classes
		return m_label;
	}
	LblShape::LblShape()
	{
		// base class constructor
		m_label = nullptr;
	}
	void LblShape::getSpecs(istream& istr)
	{
		// using temporary string for label length
		char tempString[256]{};

		istr.get(tempString, 256, ',');
		istr.ignore();

		delete[] m_label;
		m_label = new char[strlen(tempString) + 1];
		strcpy(m_label, tempString);
	}
	LblShape::LblShape(const char* label)
	{
		// deallocate
		delete[]m_label;
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
	}
	LblShape::~LblShape()
	{
		delete[]m_label;
	}
}