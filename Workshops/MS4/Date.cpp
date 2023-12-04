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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Date.h"
#include "Utils.h"

using namespace std;
using namespace sdds;

namespace sdds {
	bool Date::validate()
	{
		bool result = false;

		int date{};

		// We are getting the current system date via year since it's the first param 
		// in getSystemDate
		ut.getSystemDate(&date);

		if (m_year > maximumValueYear || m_year < (date % 100)) {
			m_state = "Invalid year in date";
			m_state = 1;
		}
		else if (m_month < 1 || m_month > 12) {
			m_state = "Invalid month in date";
			m_state = 2;
		}
		// Using util function to calculate the days in the month/year
		else if (m_day < 1 || m_day > ut.daysOfMon(m_month, m_year)) {
			m_state = "Invalid day in date";
			m_state = 3;
		}
		else if (m_dateValid == false) {
			m_state = "Invalid date value";
			m_state = 0;
		}

		else {
			result = true;
		}
		return result;
	}
	int Date::uniqueDateValue() const
	{
		return m_year * 372 + m_month * 31 + m_day;
	}
	Date::Date(int year, int month, int day)
	{
		m_format = true;
		m_dateValid = false;

		// Getting default for invalid date
		if (year == 0 || month == 0 || day == 0)
		{
			ut.getSystemDate(&m_year, &m_month, &m_day);
		}
		// Date is valid
		else {
			m_year = year;
			m_month = month;
			m_day = day;
			validate();
		}

	}
	bool Date::operator==(const Date& compareOther) const
	{
		return uniqueDateValue() == compareOther.uniqueDateValue();
	}
	bool Date::operator!=(const Date& compareOther) const
	{
		return uniqueDateValue() != compareOther.uniqueDateValue();
	}
	bool Date::operator<(const Date& compareOther) const
	{
		return uniqueDateValue() < compareOther.uniqueDateValue();
	}
	bool Date::operator>(const Date& compareOther) const
	{
		return uniqueDateValue() > compareOther.uniqueDateValue();
	}
	bool Date::operator<=(const Date& compareOther) const
	{
		return uniqueDateValue() <= compareOther.uniqueDateValue();
	}
	bool Date::operator>=(const Date& compareOther) const
	{
		return uniqueDateValue() >= compareOther.uniqueDateValue();
	}
	const Status& Date::state() const
	{
		return m_state;
	}
	 Date& Date::formatted(bool value)
	{

		if (value == false) {
			m_format = false;
		}
		else {
			m_format = true;
		}
		return *this;
	}
	Date::operator bool() const
	{
		return m_state;
	}
	ostream& Date::write(ostream& ostr) const
	{
		if (m_format) {
			int year = 0;
			if (m_year < 1000) {
				year = m_year + 2000;
			}
			else {
				year = m_year;
			}
			ostr << year;
			ostr << '/';
			ostr.fill('0');
			ostr.width(2);
			ostr << m_month;
			ostr << '/';
			ostr.width(2);
			ostr << m_day;
			ostr.fill(' ');
		}
		else {
			ostr << (m_year % 100);
			ostr.fill('0');
			ostr.width(2);
			ostr << m_month;
			ostr.width(2);
			ostr << m_day;
			ostr.fill(' ');
		}
		return ostr;
	}
	istream& Date::read(istream& istr)
	{
		int input{};
		istr >> input;

		if (istr.fail()) {
			istr.setstate(ios::failbit);
		}
		else {
			// Invalidat Date read
			if (input >= 100000) {
				m_year = input / 10000;
				m_month = (input / 100) % 100;
				m_day = input % 100;
				m_dateValid = true;
			}
			else if (input >= 10000 && input < 99999) {
				m_year = input / 100;
				m_month = input % 100;
				m_day = 0;
				m_dateValid = true;

			}
			else if (input >= 100 && input < 9999) {
				m_year = m_year;
				m_month = input / 100;
				m_day = input % 100;
				m_dateValid = true;

			}
			else {
				m_year = m_year;
				m_month = input / 100;
				m_day = input % 100;
				m_dateValid = true;

			}
		}

		if (!validate()) {
			istr.setstate(ios::badbit);
		}
		return istr;
	}
	ostream& operator<<(ostream& ostr, const Date& date)
	{
		return date.write(ostr);
	}
	istream& operator>>(istream& istr, Date& date)
	{
		return date.read(istr);
	}
}