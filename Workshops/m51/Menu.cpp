/***********************************************************************
// Final project Milestone 2
// Module: Menu.cpp
// File: Menu.cpp
// Version 2.0
// Description
// A module for menu
// Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
// Had to re-do citations because they weren't showing the proper module names
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 11/14/2023            email: aatienza1@myseneca.ca
***********************************************************************/

#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"

using namespace sdds;
using namespace std;


namespace sdds {
	Menu::Menu(const char* name, unsigned int options)
	{
		// As long as it's not null or over the max limit, it is not invalid
		if (name != nullptr && options < MAX_LIST) {
			ut.alocpy(m_content, name);
			m_list = options;
		}
		else {
			setEmpty();
		}
	}

	Menu::Menu(const Menu& copy)
	{
		// Copy constructor
		ut.alocpy(m_content, copy.getContent());
		m_list = copy.m_list;
	}
	Menu::Menu()
	{
		// Necessary for AidMan
	}
	Menu& Menu::operator=(const Menu& other)
	{
		// Assignemtn constructor
		if (this != &other) {
			ut.alocpy(m_content, other.getContent());
			m_list = other.m_list;
		}
		return *this;
	}
	Menu::~Menu()
	{
		delete[] m_content;
	}
	Menu& Menu::setEmpty()
	{
		// Setting to an invalid state, which is m_content is null ptr
		// And over maximum list
		delete[] m_content;
		m_content = nullptr;
		m_list = MAX_LIST + 1;
		return *this;
	}
	const char* Menu::getContent()const
	{
		return m_content;
	}
	unsigned int Menu::run() const
	{
		// Use this to check the validity of the string
		unsigned int result{};
		if (m_content != nullptr) {
			cout << m_content << "0- Exit" << endl;
			result = ut.getint(0, 7, "> ");
		}
		else {
			cout << m_content << "0- Exit" << endl;
		}
		return result;
	}


}