/* Citation and Sources...
Final Project Milestone 1
Module: Date
Filename: Date.cpp
Version 1.0
Author	Alicia Atienza
Revision History
-----------------------------------------------------------
Date      Reason
2023/4/2023  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include "Status.h"

using namespace std;


namespace sdds {
	const int maximumValueYear = 2030;
	class Date {
		int m_year{};
		int m_month{};
		int m_day{};

		Status m_state{};
		bool m_format{};
		bool m_dateValid{};

		bool validate();

		int uniqueDateValue() const;

	public:
		Date(int year = 0, int month = 0, int day = 0);
		bool operator==(const Date& compareOther)const;
		bool operator!=(const Date& compareOther)const;
		bool operator<(const Date& compareOther)const;
		bool operator>(const Date& compareOther)const;
		bool operator<=(const Date& compareOther)const;
		bool operator>=(const Date& compareOther)const;

		const Status& state() const;

		Date& formatted(bool value);

		operator bool() const;
		ostream& write(ostream& ostr) const;
		istream& read(istream& istr);
	};

	ostream& operator<<(ostream& ostr, const Date& date);
	istream& operator>>(istream& istr, Date& date);
}


#endif // !SDDS_DATE_H