/* Citation and Sources...
Final Project Milestone 1
Module: Status
Filename: Status.cpp
Version 1.0
Author	Alicia Atienza
Revision History
-----------------------------------------------------------
Date      Reason
2023/4/2023  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Status.h"
#include "Utils.h"

using namespace std;
using namespace sdds;

namespace sdds {

	// Constructor with defaults set
	Status::Status(const char* description, int code)
	{
		if (description != nullptr)
		{
			ut.alocpy(m_description, description);
		}
	}

	// Destructor
	Status::~Status()
	{
		delete[] m_description;
	}

	// Object copy if not empty
	Status::Status(const Status& copyStat)
	{
		if (copyStat.m_description != nullptr) {
			ut.alocpy(m_description, copyStat.m_description);
			m_code = copyStat.m_code;
		}

		// Clear resets to original state
		else {
			clear();
		}
	}
	Status& Status::clear()
	{
		delete[]m_description;
		m_description = nullptr;
		m_code = 0;

		return *this;
	}

	// Return int
	Status& Status::operator=(int code)
	{
		m_code = code;
		return *this;
	}

	// Copy description, return it
	Status& Status::operator=(const char* description)
	{
		ut.alocpy(m_description, description);
		return *this;
	}

	// Return code
	Status::operator int() const
	{
		return m_code;
	}

	// Return description
	Status::operator const char* () const
	{
		return m_description;
	}

	// Check if there's a message inside
	Status::operator bool() const
	{
		return m_description == nullptr;
	}

	// HELPER FUNCTION NECESSARY for sending to << insertion operator
	ostream& Status::print(ostream& ostr) const
	{

		// If the code is 0 we want to print out the description
		if (m_code == 0) {
			ostr << m_description;
		}
		// We print out the error
		else {
			ostr << "ERR#" << m_code << ": " << m_description;
		}
		return ostr;
	}
	ostream& operator<<(ostream& ostr, const Status& copyStat)
	{
		// If it's in a false state, print out 
		if (!copyStat) {
			copyStat.print(ostr);
		}
		return ostr;
	}
}