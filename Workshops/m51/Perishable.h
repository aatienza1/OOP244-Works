/***********************************************************************
// Final project Milestone 3
// Module: Perishable
// File: Perishable.h
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
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include "Item.h"
#include "Date.h"

namespace sdds{
	class Perishable : public Item {
	private:
		Date m_expiryDate{};
		char* m_instructions{};
	public:
		// Default constructor to create empty perishable item
		Perishable();
		// Perishable can be copied
		Perishable(const Perishable& other);
		// Perishable can be assigned
		Perishable& operator=(const Perishable& other);
		// Deconstructor
		~Perishable();
		// Return constant ref of expiry date
		const Date& expiry()const;
		// Overrides
		virtual std::ofstream& save(std::ofstream& ostr)const;
		virtual std::ifstream& load(std::ifstream& istr);
		virtual std::ostream& display(std::ostream& ostr = cout)const;
		virtual int readSku(std::istream& istr = cin);
		virtual std::istream& read(std::istream& istr = cin);
	};

}
#endif //perishable