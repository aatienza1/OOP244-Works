/***********************************************************************
// Final project Milestone 2
// Module: Aidman
// File: Aidman.h
// Version 2.0
// Description
// Header for the aid management
// Revision History
// Had to re-do citations because they weren't showing the proper module names
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 11/14/2023            email: aatienza1@myseneca.ca
***********************************************************************/

#include <iostream>
#include "AidMan.h"
#include "Utils.h"
#include "Date.h"

using namespace std;
using namespace sdds;

namespace sdds {
	unsigned int AidMan::menu() const
	{
		// Output for if there's a file or not

		if (m_filename != nullptr) {
			cout << "Aid Management System" << endl;
			cout << "Date: " << Date() << endl;
			cout << "Data file: " << m_filename << endl;
		}
		else {
			cout << "Aid Management System" << endl;
			cout << "Date: "<< Date() << endl;
			cout << "Data file: No file" << endl;
		}

		cout << endl;
		unsigned int selection = m_menu.run();

		return selection;
	}

	// Had to initailize m_menu in the constructor itself
	AidMan::AidMan(const char* filename) : m_menu("1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n", 7) {
		ut.alocpy(m_filename, filename);
	}


	AidMan::AidMan(const AidMan& copy)
	{
		ut.alocpy(m_filename, copy.getFilename());
	}
	AidMan::~AidMan()
	{
		delete[]m_filename;
	}
	const char* AidMan::getFilename() const
	{
		return m_filename;
	}
	AidMan& AidMan::operator=(const AidMan& other)
	{
		if (this != &other) {
			ut.alocpy(m_filename, other.getFilename());
		}
		return *this;
	}
	AidMan& AidMan::run()
	{

		// Looping the entry
		bool keepGoing = false;
		while (!keepGoing) {

			// Using menu as it returns the unsigned int (which uses getint)
			unsigned int selection = menu();
			switch (selection) {
			case 0:
				cout << "Exiting Program!" << endl;
				keepGoing = true;
				break;
			case 1:
				cout << endl;
				cout << "****List Items****" << endl;
				cout << endl;
				break;
			case 2:

				cout << endl;
				cout << "****Add Item****" << endl;
				cout << endl;

				break;
			case 3:

				cout << endl;
				cout << "****Remove Item****" << endl;
				cout << endl;
				break;
			case 4:

				cout << endl;
				cout << "****Update Quantity****" << endl;
				cout << endl;
				break;
			case 5:

				cout << endl;
				cout << "****Sort****" << endl;
				cout << endl;
				break;
			case 6:

				cout << endl;
				cout << "****Ship Items****" << endl;
				cout << endl;

				break;
			case 7:

				cout << endl;
				cout << "****New/Open Aid Database****" << endl;
				cout << endl;

				break;
			}
		}
				return *this;
	}

}

