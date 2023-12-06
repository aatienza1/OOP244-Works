/***********************************************************************
// Final project Milestone 3
// Module: item
// File: Item.h
// Version 1.2
// Description
// Concrete class derived from iProduct
// Revision History
// Added sku getter
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 11/24/2023            email: aatienza1@myseneca.ca
***********************************************************************/
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include "iProduct.h"
#include "Status.h"

namespace sdds {
	class Item :public iProduct {
	private:
		double m_price{};
		int m_quantity{};
		int m_neededQuantity{};
		char* m_description{};
		bool m_linear = false;
	protected:
		Status m_state{};
		int m_sku{};
	public:
		// Construction
		Item();
		~Item();
		Item(const Item& other);
		Item& operator=(const Item& other);

		// Virtual public query iProduct overrides
		virtual void linear(bool isLinear);
		virtual int qtyNeeded()const;
		virtual int qty()const;
		int sku()const;
		bool isLinear()const;
		virtual operator double()const;
		virtual operator bool()const;

		// Virtual public modifier iProduct pverrodes
		virtual int operator-=(int quantity);
		virtual int operator+=(int quantity);

		// Public modifier
		Item& clear();

		// Virtual operator == iProduct overrides
		virtual bool operator==(int sku)const;
		virtual bool operator==(const char* description)const;

		// Virtual input/output method iProduct overrides
		virtual std::ofstream& save(std::ofstream& ostr)const;
		virtual std::ifstream& load(std::ifstream& istr);
		virtual std::ostream& display(std::ostream& ostr = cout)const;
		virtual int readSku(std::istream& istr = cin);
		virtual std::istream& read(std::istream& istr = cin);
	};
}
#endif