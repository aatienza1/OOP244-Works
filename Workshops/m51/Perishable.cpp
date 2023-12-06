/***********************************************************************
// Final project Milestone 3
// Module: Perishable
// File: Perishable.cpp
// Version 1.0
// Description
// Concrete class derived from iem
// Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 11/28/2023            email: aatienza1@myseneca.ca
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Perishable.h"
#include "Date.h"
#include "Utils.h"

using namespace sdds;
namespace sdds {
	Perishable::Perishable()
	{
		delete[]m_instructions;
		m_instructions = nullptr;
		m_expiryDate = 0;
	}
	Perishable::Perishable(const Perishable& other)
	{
		operator=(other);
	}
	Perishable& Perishable::operator=(const Perishable& other)
	{
		if (this != &other) {
			// copy item as well
			Item::operator=(other);
			ut.alocpy(m_instructions, other.m_instructions);
			m_expiryDate = other.m_expiryDate;
		}
		else {
			Item::clear();
			delete[]m_instructions;
			m_instructions = nullptr;
			m_expiryDate = 0;
		}

		return *this;
	}
	Perishable::~Perishable()
	{
		delete[]m_instructions;
	}
	const Date& Perishable::expiry() const
	{
		return m_expiryDate;
	}

std::ofstream& Perishable::save(std::ofstream& ostr) const
    {
        if (m_expiryDate.state()) {
            Item::savePerishable(ostr);
            if (m_instructions != nullptr) {
                ostr << m_instructions;
            }
            ostr << '\t';
            const_cast<Date&>(expiry()).formatted(false);
            ostr << m_expiryDate;
            const_cast<Date&>(expiry()).formatted(true);
			ostr << endl;

        }
        return ostr;
    }

	std::ifstream& Perishable::load(std::ifstream& ifstr) {
		Item::load(ifstr);

		if (ifstr.fail()) {
			m_state = "Input file stream read (perishable) failed!";
			return ifstr;
		}

		// put instructions inside
		char tempInstructions[1000];
		if (ifstr.getline(tempInstructions, 1000, '\t') && isalpha(tempInstructions[0])) {
			ut.alocpy(m_instructions, tempInstructions);
		}
		ifstr >> m_expiryDate;
		ifstr.ignore();

		return ifstr;
	}


	std::ostream& Perishable::display(std::ostream& ostr) const
	{

		if (!m_expiryDate.state()) {
			ostr << m_expiryDate;

		}
		else {
			if (isLinear()) {
				Item::display(ostr);

				if (m_instructions != nullptr && m_instructions[0] != '\0') {
					ostr << "*";
				}
				else {
					ostr << " ";
				}
				ostr << m_expiryDate;
			}
			else {
				ostr << "Perishable ";
				Item::display(ostr);
				ostr << "Expiry date: ";

				// cast out of const in order to format
				ostr << m_expiryDate;
				// Handling instructions
				if (m_instructions != nullptr && m_instructions[0] != '\0') {
					ostr << "\nHandling Instructions: " << m_instructions << '\n';
				}
				else {
					ostr << "\n";
				}
			}
		}
		return ostr;
	}

	int Perishable::readSku(std::istream& istr) {
		m_sku = ut.getint(10000, 39999, "SKU: ", nullptr);
		return m_sku;
	}

	std::istream& Perishable::read(std::istream& istr)
	{
		Item::read(istr);
		delete[] m_instructions;
		m_instructions = nullptr;

		std::cout << "Expiry date (YYMMDD): ";
		m_expiryDate.read(istr);

		// Cast to false for read to properly input 
		istr.ignore(1000, '\n');


		std::cout << "Handling Instructions, ENTER to skip: ";
		if (istr.peek() != '\n') {
			m_instructions = new char[1000];
			istr.getline(m_instructions, 1000);
		}
		else {
			istr.ignore(); 
		}

		if (istr.fail()) {
			m_state = "Perishable console date entry failed!";
		}

		return istr;
	}



}