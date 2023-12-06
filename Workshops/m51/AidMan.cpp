/***********************************************************************
// Final project Milestone 2
// Module: Aidman
// File: Aidman.h
// Version 1.2
// Description
// Header for the aid management
// Revision History
// Had to re-do citations because they weren't showing the proper module names
// Added new methods (Save/deallocate/load/list) and included perishable,iomanip and fstream headers and added
proper default constructor to aidman
// Added new methods (search/additem)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 11/14/2023            email: aatienza1@myseneca.ca
***********************************************************************/
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include "AidMan.h"
#include "Item.h"
#include "Perishable.h"
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

		cout << "---------------------------------" << endl;
		unsigned int selection = m_menu.run();

		return selection;
	}

	// Had to initailize m_menu in the constructor itself
	AidMan::AidMan(const char* filename) : m_menu("1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n", 7) {
		ut.alocpy(m_filename, filename);
	}

	// Constructor for when file sucks
	AidMan::AidMan(): m_menu("1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n", 7) {
		delete[]m_filename;
		m_filename = nullptr;
	}


	AidMan::AidMan(const AidMan& copy)
	{
		ut.alocpy(m_filename, copy.getFilename());
	}
	AidMan::~AidMan()
	{
		deallocate();
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
			if (selection != 0 && m_filename == nullptr) { selection = 7; }
			switch (selection) {
			case 0:
				cout << "Exiting Program!" << endl;
				save();
				keepGoing = true;
				break;
			case 1:
				cout << endl;
				cout << "****List Items****" << endl;
				list();
				cout << endl;
				break;
			case 2:

				cout << endl;
				cout << "****Add Item****" << endl;
				AddItem();
				cout << endl;

				break;
			case 3:

				cout << endl;
				cout << "****Remove Item****" << endl;
				RemoveItem();
				cout << endl;
				break;
			case 4:

				cout << endl;
				cout << "****Update Quantity****" << endl;
				UpdateItem();
				cout << endl;
				break;
			case 5:

				cout << endl;
				cout << "****Sort****" << endl;
				Sort();
				cout << endl;
				break;
			case 6:

				cout << endl;
				cout << "****Ship Items****" << endl;
				//ShipItems();
				cout << endl;

				break;
			case 7:

				cout << endl;
				cout << "****New/Open Aid Database****" << endl;
				load();
				cout << endl;

				break;
			}
		}
				return *this;
	}

	AidMan& AidMan::save()
	{
		if (m_filename != nullptr) {
			ofstream aidFileWrite{};
			aidFileWrite.open(m_filename);

			//Iterate through every item and save it
			for (int i = 0; i < m_noOfItems; i++) {
				m_iprodPointer[i]->save(aidFileWrite);
			}
		}
		return *this;
	}

	AidMan& AidMan::deallocate()
	{
		// Iterate through every item and delete it
		for (int i = 0; i < m_noOfItems; i++) {
			delete m_iprodPointer[i];
			m_iprodPointer[i] = nullptr;
		}
		delete[] m_filename;
		m_filename = nullptr;
		m_noOfItems = 0;
		return *this;
	}

	bool AidMan::load()
	{
		bool result = false;
		string tempName{};
		save();
		deallocate();

		// Entering in temp variable to copy over
		cout << "Enter file name: ";
		cin >> tempName;

		// Use c_str() because it will not accept array characters
		ut.alocpy(m_filename, tempName.c_str());

		ifstream openFile{};
		openFile.open(m_filename);

		if (!openFile) {
			cout << "Failed to open " << m_filename << " for reading!" << endl;
			cout << "Would you like to create a new data file?" << endl;

			cout << "1- Yes!" << endl;
			cout << "0- Exit" << endl;

			int selection = ut.getint(1, 2, "> ", nullptr);

			if (selection == 1) {
				ofstream newFile(m_filename);
				newFile.close();
			}
			if (selection == 0) {}
		}
		// File open was successful, begin loop
		else {
			int firstDigiSku{};

			// Check first character of the record, using first digitof SKU
			while (firstDigiSku != EOF && openFile && m_noOfItems < sdds_max_num_items) {
				firstDigiSku = openFile.peek();

				// while we are not at the end of file
				if (openFile && firstDigiSku != EOF && m_noOfItems < sdds_max_num_items) {
					// SKU for perishable = 1 / 3
					if (firstDigiSku >= '1' && firstDigiSku <= '3') {
						m_iprodPointer[m_noOfItems] = new Perishable;
						
					}
					// SKU for non perishable = 4/9
					else if (firstDigiSku >= '4' && firstDigiSku <= '9') {
						m_iprodPointer[m_noOfItems] = new Item;
					}
					// Fail
					else {
						openFile.setstate(ios::failbit);
					}
					// call load to load data from file
					if (m_iprodPointer[m_noOfItems]) {
						m_iprodPointer[m_noOfItems]->load(openFile);
						if (*m_iprodPointer[m_noOfItems]) {
							m_noOfItems++;
						}
						else { 
							delete m_iprodPointer[m_noOfItems]; 
							m_iprodPointer[m_noOfItems] = nullptr; 
						}
					}
				}
			}
			cout << m_noOfItems << " records loaded!" << endl;
		}

		return result;
	}

	int AidMan::list(const char* sub_desc)
	{
		int tempNum{};
		int tempSelection{};
		cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

		// Printing
		if (m_noOfItems > 0) {
			for (int i = 0; i < m_noOfItems; i++) {
				if (!sub_desc || *m_iprodPointer[i] == sub_desc) {
					m_iprodPointer[i]->linear(true);
					cout << setw(4) << setfill(' ') << (i + 1) << " | " << *m_iprodPointer[i] << endl;
					m_iprodPointer[i]->linear(false);
					tempNum++;
				}
			}
			cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
			cin.ignore();
			if (sub_desc == nullptr) {
				cout << "Enter row number to display details or <ENTER> to continue:" << endl;
				cout << "> ";
				if (cin.peek() != '\n') {
					cin >> tempSelection;
					if (tempSelection > -1 && tempSelection <= m_noOfItems) {
						cout << *m_iprodPointer[tempSelection - 1] << endl;
					}
					else if (cin.peek() == '\n') {
						cin.ignore();
					}
				}
			}
		}
		return tempNum;

	}

	int AidMan::search(int sku) const
	{
		int result = -1;
		for (int i = 0; i < m_noOfItems; i++) {
			// Checking both array boundaries and if the pointer is not null
			if (i >= 0 && i < m_noOfItems && m_iprodPointer[i] && sku == m_iprodPointer[i]->sku())
				result = i;
		}
		return result;
	}


	AidMan& AidMan::AddItem()
	{
		// this isn't working yet lol???
		if (m_noOfItems >= sdds_max_num_items) {
			cout << "Database full!" << endl;
		}
		else {
			int selection{};
			cout << "1- Perishable" << endl;
			cout << "2- Non-Perishable" << endl;
			cout << "-----------------" << endl;
			cout << "0- Exit" << endl;
			selection = ut.getint(0, 2, "> ");
			// add nullptr check

			if (m_iprodPointer[m_noOfItems] != nullptr) {
				delete[]m_iprodPointer[m_noOfItems];
				m_iprodPointer[m_noOfItems] = nullptr;
			}
			if (selection == 0) {
				cout << "Aborted" << endl << endl;
			}
			else if (selection == 1) {
				m_iprodPointer[m_noOfItems] = new Perishable;
			}
			else if (selection == 2) {
				m_iprodPointer[m_noOfItems] = new Item;
				// memory error is here, issues de-allocating when item fails
			}

			if (m_iprodPointer[m_noOfItems]) {
				int tempSku{};
				m_iprodPointer[m_noOfItems]->readSku(cin);
				tempSku = m_iprodPointer[m_noOfItems]->sku();

				if (search(tempSku) == -1) {
					m_iprodPointer[m_noOfItems]->read(cin);
					if (*m_iprodPointer[m_noOfItems]) {
						m_noOfItems++;
					}
				}
				else{
					// Delete item if it doesn't meet certain conditions
					delete m_iprodPointer[m_noOfItems];
					cout << "Sku: " << tempSku << " is already in the system, try updating quantity instead.\n";

				}
			}
		}
		return *this;
	}
	AidMan& AidMan::remove(int index)
	{
		// deletetete!!
		delete m_iprodPointer[index];

		// Shifting products
		for (int i = index; i < m_noOfItems; i++) {
			m_iprodPointer[i] = m_iprodPointer[i + 1];
		}

		// good bye sku
		m_noOfItems--;
		return *this;
	}
	AidMan& AidMan::RemoveItem()
	{
		char tempDesc[150]{};
		int skuMatch{};
		cout << "Item description: ";
		cin >> tempDesc;

		skuMatch = list(tempDesc);
		if (skuMatch != -1) {
			int removeSku = ut.getint(10000, 99999, "Enter SKU: ");
			if (search(removeSku) == -1) {
				cout << "SKU Not Found!" << endl;
			}
			// remove sku
			else if (search(removeSku) != 1) {
				int selection{};

				cout << "Following item will be removed: " << endl;
				cout << *m_iprodPointer[search(removeSku)] << endl;
				cout << "Are you sure?" << endl;
				cout << "1- Yes!" << endl;
				cout << "0- Exit" << endl;

				// select sku to be removed
				selection = ut.getint(0, 1, "> ");
				if (selection == 1) {
					remove(search(removeSku));
					cout << "Item removed!" << endl;
				}
				else if (selection == 0) {
					cout << "Aborted!" << endl;
				}
			}
		}

		return *this;
	}
	AidMan& AidMan::UpdateItem()
	{
		// Using similar logic as adding an item to find the item
		char tempDesc[150]{};
		cout << "Item description: ";
		cin >> tempDesc;

		// get the list
		int skuMatch = list(tempDesc);

		if (skuMatch != -1) {
			int updateQuantity = ut.getint(10000, 99999, "Enter SKU: ");
			int updateIndex = search(updateQuantity);

			if (updateIndex == -1) {
				cout << "SKU Not Found!" << endl;
			}
			else {
				// using querys
				int qNeeded = m_iprodPointer[updateIndex]->qtyNeeded();
				int qOnHand = m_iprodPointer[updateIndex]->qty();

				int selection{};
				cout << "1- Add" << endl;
				cout << "2- Reduce" << endl;
				cout << "0- Exit" << endl;
				selection = ut.getint(0, 2, "> ");

				if (selection == 1) {
					if ((qNeeded - qOnHand) <= 0) {
						cout << "Quantity Needed already fulfilled!" << endl;
					}
					else {
						int toAdd = ut.getint(1, qNeeded - qOnHand, "Quantity to add: ");
						*m_iprodPointer[updateIndex] += toAdd;
						cout << toAdd << " items added!" << endl;
					}
				}
				else if (selection == 2) {
					if (qOnHand == 0) {
						cout << "Quantity on hand is zero!" << endl;
					}
					else {
						int toRemove = ut.getint(1, qOnHand, "Quantity to reduce: ");
						*m_iprodPointer[updateIndex] -= toRemove;
						cout << toRemove << " items removed!" << endl;
					}
				}
				else if (selection == 0) {
					cout << "Aborted!" << endl;
				}
			}
		}
		else {
			cout << "No items match this description." << endl;
		}

		return *this;
	}

	AidMan& AidMan::Sort()
	{
		// declared outside of loop to be used later
		int i, j;
		for (i = 0; i < m_noOfItems; i++) {
			int qNeeded = m_iprodPointer[i]->qtyNeeded();
			int qOnHand = m_iprodPointer[i]->qty();
			int difference = qOnHand - qNeeded;

			// next item for comparison
			for (j = 0; j < m_noOfItems; i++) {
				int qNeeded2 = m_iprodPointer[j]->qtyNeeded();
				int qOnHand2 = m_iprodPointer[j]->qty();
				int difference2 = qOnHand2 - qNeeded2;

				if (difference < difference2) {
					iProduct* tempProduct{};
					tempProduct = m_iprodPointer[i];
					m_iprodPointer[i] = m_iprodPointer[j];
					m_iprodPointer[j] = tempProduct;

				}
			}
		}
		cout << "Sort Completed!\n" << endl;
		return *this;
	}
	//AidMan& AidMan::ShipItems()
	//{
	//	int shippedItems{};
	//	Date currentDate{};

	//	// shipping the items
	//	ofstream shippingFile("shippingOrder.txt");

	//	// putting it into the ofstream file
	//	shippingFile << "Shipping Order, Date: " << current << "\n";
	//	shippingFile << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry";
	//	shippingFile << "-----+-------+-------------------------------------+------+------+---------+-----------";

	//	// code for the rest of the loop of going through

	//	cout << "-----+-------+-------------------------------------+------+------+---------+-----------";

	//	cout << "Shipping Order for 999times saved!";
	//	return *this;
	//}
	}



