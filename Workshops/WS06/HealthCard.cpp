
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date:11/3/2023         Reason
// ID: 38782074
// Email: aatienza1@myseneca.ca
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
//*********************************************************************** /
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "HealthCard.h"
using namespace std;
namespace sdds {
	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const
	{
		// Checking that everything will validate properly
		bool result = false;
		if (name != nullptr && name[0] != '\0' && number > 999999999 && number < 9999999999 
			&& strlen(vCode) == 2 && strlen(sNumber) == 9) result = true;
		return result;
	}
	void HealthCard::setEmpty()
	{
		// Setting HealthCard to an empty invalid state
		m_name = nullptr;
	}
	void HealthCard::allocateAndCopy(const char* name)
	{
		// Deleting the previous memory, setting new memory 
		delete[] m_name;
		int length = strlen(name);
		m_name = new char[length + 1];
		strcpy(m_name, name);
	}

	void HealthCard::extractChar(istream& istr, char ch) const
	{
		// Peeking to check the next character in the HealthCard
		if (istr.peek() == ch)istr.ignore();
		else {

			// Ignore the character if false and set to false
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
	}

	ostream& HealthCard::printIDInfo(ostream& ostr) const
	{
		// Output of healthcard into ostr object
		ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
		return ostr;
	}

	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
	{
	
		if (validID(name, number, vCode, sNumber)) {

			// Use DMA function to allocate
			allocateAndCopy(name);

			// Copy rest
			m_number = number;
			strcpy(m_vCode, vCode);
			strcpy(m_sNumber, sNumber);
		}
		else {

			// ID was invalid, set to safe empty state
			delete[] m_name;
			setEmpty();
		}
	}

	HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[])
	{
		// Our default parameters are already in the header, setting into safe empty state
		set(name, number, vCode, sNumber);
	}

	HealthCard::HealthCard(const HealthCard& hc)
	{
		// If object is valid, set HealthCard to the params of valid object
		*this = hc;
	}

	HealthCard& HealthCard::operator=(const HealthCard& hc)
	{
		// Making sure it isn't a self (current obj isn't the param)
		if (this != &hc) {

			// Copy construct the param obj
			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		}
		return *this;
	}

	HealthCard::~HealthCard()
	{
		delete[] m_name;
	}

	HealthCard::operator bool()const
	{
		// m_name is nullptr
		bool result = false;
		if (m_name != nullptr)result = true;
		return result;
	}

	ostream& HealthCard::print(ostream& ostr, bool toFile) const
	{
		if (*this) {
			// printing out if bool is true
			if (toFile) {
				ostr << m_name;
				ostr << ',';
				printIDInfo(ostr);
				ostr << endl;

			}
			else {
				//if false, do not print
				ostr.width(50);
				ostr.fill('.');
				ostr.setf(ios::left);
				ostr << m_name;
				printIDInfo(ostr);
			}
		}
		return ostr;
	}

	istream& HealthCard::read(istream& istr)
	{
		// Creating all temporary variables
		char tempName[MaxNameLength]{};
		long long tempId{};
		char tempCode[3]{};
		char tempStock[10]{};

		// Reading the name via local variable
		istr.get(tempName, MaxNameLength, ',');

		extractChar(istr, ',');

		// Reading the ID via local viarable
		istr >> tempId;

		extractChar(istr, '-');

		// Reading the code via local variable
		istr.get(tempCode, 3, ',');

		extractChar(istr, ',');

		istr.get(tempStock, 10, '\n');

		extractChar(istr, '\n');
		
		if (istr) {
			set(tempName, tempId, tempCode, tempStock);
		}
		else {
			istr.clear();
			istr.ignore(1000, '\n');
		}
		return istr;
	}

	ostream& operator<<(ostream& ostr, const HealthCard& hc)
	{
		//if vlaid, use print function to print on screen and not file (onfile is false)
		// if not valid, print "Invalid Card Number"
		if (hc) {
			hc.print(ostr, false);
		}
		else {
			ostr << "Invalid Health Card Record";
		}
		return ostr;
	}

	istream& operator>>(istream& istr, HealthCard& hc)
	{
		
		return hc.read(istr);
	}


}
