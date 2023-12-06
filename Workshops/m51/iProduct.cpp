/***********************************************************************
// Final project Milestone 3
// Module: iProduct
// File: iProduct.h
// Version 1.0
// Description
// Header for the iProduct
// Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 11/24/2023            email: aatienza1@myseneca.ca
***********************************************************************/
#include <iostream>
#include "iProduct.h"

using namespace sdds;
namespace sdds {
	std::istream& operator>>(std::istream& istr, iProduct& reading)
	{
		reading.read(istr);
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, iProduct& displaying)
	{
		displaying.display(ostr);
		return ostr;
	}
}