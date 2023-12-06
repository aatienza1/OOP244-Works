/***********************************************************************
// Final project Milestone 2
// Module: Utils
// File: Utils.h
// Version 1.0
// Description
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
// Revision History
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 11/14/2023            email: aatienza1@myseneca.ca
***********************************************************************/

#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include <iostream>
#include "Menu.h"
#include "iProduct.h"

using namespace std;

namespace sdds {
	const int sdds_max_num_items = 100;
	class AidMan {
	private:
		char* m_filename{};
		Menu m_menu{};

		// User's selection of the system
		unsigned int menu() const;

		// Array of iProd items
		iProduct* m_iprodPointer[sdds_max_num_items]{};

		int m_noOfItems{};

	public:
		// Initializes the main menu with text
		// Parameter is a filename
		AidMan(const char* filename);

		AidMan();

		// Copy constructor
		AidMan(const AidMan& copy);

		// Destructor
		virtual ~AidMan();

		// Getting the filename to copy
		const char* getFilename()const;

		// Copy Assignment operaotr
		AidMan& operator=(const AidMan& other);

		// Runs the whole application
		// Loops selection choices until 0 is hit
		AidMan& run();

		// New/Open Aid Database
		AidMan& save();
		AidMan& deallocate();
		bool load();

		// Menu item 1
		int list(const char* sub_desc = nullptr);

		// Menu item 2
		int search(int sku)const;
		AidMan& AddItem();

		// Menu item 3
		AidMan& remove(int index);
		AidMan& RemoveItem();

		// Menu item 4
		AidMan& UpdateItem();

		// Menu item 5
		AidMan& Sort();

		// Menu item 6
		//AidMan& ShipItems();
	};

}

#endif