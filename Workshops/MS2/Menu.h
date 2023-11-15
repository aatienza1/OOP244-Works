/***********************************************************************
// Final project Milestone 2
// Module: Menu
// File: Menu.h
// Version 2.0
// Description
// Data structures for menu
// Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
// Had to re-do citations because they weren't showing the proper module names
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 11/14/2023            Reason
***********************************************************************/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

#define MAX_LIST 15

using namespace std;


namespace sdds {
	class Menu {
	private:
		char* m_content{};
		unsigned int m_list;

	public:
		// Constructor with params for items on list and number of options
		Menu(const char* name, unsigned int options = MAX_LIST);

		// Copy Constructor
		Menu(const Menu& copy);

		// Need to create this constructor for the AidMan
		Menu();
		// Copy assignment
		Menu& operator=(const Menu& other);

		// Destructor for dma de-allocation
		virtual ~Menu();

		// Invalid state (String is null or options is more than max)
		Menu& setEmpty();

		// Returning the content list because alocpy cannot convert argument
		const char* getContent()const;

		// Unsigned int
		unsigned int run() const;

	};

}

#endif