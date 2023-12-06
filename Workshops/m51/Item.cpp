/***********************************************************************
// Final project Milestone 3
// Module: item
// File: Item.cpp
// Version 1.3
// Description
// Concrete class derived from iProduct
// Revision History
// Changed copy assignment to copy m_sku
// Added m_sku query
// added removing items
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 11/24/2023            email: aatienza1@myseneca.ca
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Item.h"
#include "Utils.h"

using namespace sdds;
namespace sdds {
	// Ensure initialization of nullptr
	Item::Item()
	{
		clear();
	}

	Item::~Item()
	{
		delete[]m_description;
	}
	Item::Item(const Item& other)
	{
		operator=(other);
	}
	Item& Item::operator=(const Item& other)
	{
		if (this != &other) {
			ut.alocpy(m_description, other.m_description);
			m_price = other.m_price;
			m_quantity = other.m_quantity;
			m_neededQuantity = other.m_neededQuantity;
			m_linear = other.m_linear;
			m_sku = other.m_sku;
			m_state = other.m_state;
		}
		else {
			clear();
		}
		return *this;
	}
	int Item::qtyNeeded() const
	{
		return m_neededQuantity;
	}
	int Item::qty() const
	{
		return m_quantity;
	}
	int Item::sku() const
	{
		return m_sku;
	}
	bool Item::isLinear() const
	{
		return m_linear;
	}
	Item::operator double() const
	{
		return m_price;
	}
	Item::operator bool() const
	{
		return (m_state && m_sku > 0);
	}
	int Item::operator-=(int quantity)
	{
		return (m_quantity -= quantity);
	}
	int Item::operator+=(int quantity)
	{
		return (m_quantity += quantity);
	}
	void Item::linear(bool flag)
	{
		m_linear = flag;
	}
	Item& Item::clear()
	{
		// Safe state
		m_price = 0;
		m_quantity = 0;
		m_neededQuantity = 0;
		delete[]m_description;
		m_description = nullptr;
		m_linear = false;
		return *this;
	}
	bool Item::operator==(int sku) const
	{
		bool result = false;
		if (m_sku == sku) {
			result = true;
		}
		return result;
	}
	bool Item::operator==(const char* description) const
	{
		bool result = false;

		// Checking if description is nullptr, or if it's exact same
		if (description != nullptr && strstr(m_description, description)) {
			result = true;
		}

		return result;
	}
	std::ofstream& Item::save(std::ofstream& ostr) const
	{
		if (m_state) {
			ostr << '\n' << m_sku << '\t' << m_description << '\t' << m_quantity << '\t' << m_neededQuantity << '\t' << m_price;
		}
		else {
			ostr.setstate(std::ios::failbit);
		}
		return ostr;
	}


	std::ifstream& Item::load(std::ifstream& ifstr)
	{
		// Clear existing description
		delete[] m_description;
		m_description = nullptr;

		ifstr >> m_sku;
		if (ifstr.fail()) {
			m_state = "Input file stream read failed!";
		}
		else {
			char tempDesc[1000];
			ifstr.ignore();
			ifstr.getline(tempDesc, 1000, '\t');

			// Properly copy the description
			ut.alocpy(m_description, tempDesc);

			ifstr >> m_quantity;
			ifstr.ignore();

			ifstr >> m_neededQuantity;
			ifstr.ignore();

			ifstr >> m_price;
			ifstr.ignore(1);
		}
		return ifstr;
	}


	std::ostream& Item::display(std::ostream& ostr) const
	{
		if (!m_state) {
			ostr << m_state;
		}
		if (m_linear) {
			ostr << m_sku << " | ";

			// Linear but greater than 35
			if (m_description != nullptr) {
				if (strlen(m_description) > 35) {
					for (int i = 0; i < 35; i++) {
						ostr << m_description[i];
					}
					m_description[35] = '\0';
				}
				else {
					// Linear but less than 35
					ostr << setw(35) << setfill(' ') << left << m_description;
				}
			}

			ostr << " | " << setw(4) << setfill(' ') << right << m_quantity << " | " << setw(4) << m_neededQuantity << " | " << setw(7) << m_price << " |";
		}

		// Not linear
		else if (!m_linear) {
			ostr << "AMA Item:" << std::endl;
			ostr << m_sku << ": " << m_description << std::endl;
			ostr << "Quantity Needed: " << m_neededQuantity << std::endl;
			ostr << "Quantity Available: " << m_quantity << std::endl;
			ostr << "Unit Price: $" << fixed << setprecision(2) << m_price << std::endl;
			ostr << "Needed Purchase Fund: $" << fixed << setprecision(2) << (m_price * (double(m_neededQuantity) - double(m_quantity))) << std::endl;
		}
		else {
			ostr << "Something Went Wrong... " << endl;
		}
		return ostr;
	}


	int Item::readSku(std::istream& istr)
	{
		m_sku = ut.getint(40000, 99999, "SKU: ", nullptr);
		return m_sku;
	}
	std::istream& Item::read(std::istream& istr)
	{
		// Description can be unknown length of characters
		char tempDesc[1000]{};
		m_state.clear();

		std::cout << "AMA Item:" << std::endl;
		std::cout << "SKU: " << m_sku << std::endl;
		std::cout << "Description: ";
		istr.ignore();
		istr.getline(tempDesc, 1000, '\n');
		// Proper copy of description
		ut.alocpy(m_description, tempDesc);
		std::cout << "Quantity Needed: ";
		m_neededQuantity = ut.getint(1, 9999);
		std::cout << "Quantity On Hand: ";
		m_quantity = ut.getint(0, m_neededQuantity);
		std::cout << "Unit Price: $";
		m_price = ut.getdouble(0.0, 9999.00);

		if (istr.fail()) {
			m_state = "Console entry failed!";
		}

		return istr;
	}
}