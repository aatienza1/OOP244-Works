/***********************************************************************
// OOP244 Workshop # 9: Graduate Module
//
// File: Graduate.cpp
// Date: 11/22/2023
// Author: Alicia Atienza
// Description: This program demonstrates the concept of Polymorphism
// using an example of Student and Graduate.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Graduate.h"

using namespace sdds;
using namespace std;

namespace sdds {
	Graduate::Graduate()
	{
		m_supervisor = nullptr;
		m_thesisTitle = nullptr;
	}
	// Passing through the parent (name and age)
	Graduate::Graduate(const char* name, int age, const char* thesis, const char* supervisor) 
		:Student(name,age)
	{
		m_supervisor = new char[strlen(supervisor) + 1];
		m_thesisTitle = new char[strlen(thesis) + 1];

		strcpy(m_supervisor, supervisor);
		strcpy(m_thesisTitle, thesis);
	}
	Graduate::~Graduate()
	{
		delete[] m_supervisor;
		delete[] m_thesisTitle;
	}

	// Passing through parent (name and age again)
	Graduate::Graduate(const Graduate& other)
		: Student(other)  
	{
		m_supervisor = nullptr;
		m_thesisTitle = nullptr;

		if (other.m_supervisor) {
			m_supervisor = new char[strlen(other.m_supervisor) + 1];
			strcpy(m_supervisor, other.m_supervisor);
		}

		if (other.m_thesisTitle) {
			m_thesisTitle = new char[strlen(other.m_thesisTitle) + 1];
			strcpy(m_thesisTitle, other.m_thesisTitle);
		}
	}

	Graduate& Graduate::operator=(const Graduate& other)
	{
		if (this != &other) {
			Student::operator=(other);

			delete[] m_supervisor;
			delete[] m_thesisTitle;

			m_supervisor = new char[strlen(other.m_supervisor) + 1];
			m_thesisTitle = new char[strlen(other.m_thesisTitle) + 1];

			strcpy(m_supervisor, other.m_supervisor);
			strcpy(m_thesisTitle, other.m_thesisTitle);
		}
		return *this;
	}
	void Graduate::display()
	{
		// Using parent display
		Student::display();
		cout << "Thesis Title: " << m_thesisTitle << endl;
		cout << "Supervisor: " << m_supervisor << endl;
		cout << "---------------------------------------------" << endl;
	}
}