/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 10/14/2023            Reason
// ID: 38782074
// Email: aatienza1@myseneca.ca
// I have done all the coding by myself and only copied the code that my professor 
// provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include "Portfolio.h"

using namespace std;
namespace sdds {


    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }

    Portfolio::Portfolio() {
       emptyPortfolio();
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && ( type == 'V' || type == 'G' || type == 'I') ) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const{
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Value: ";
            cout.width(10);
            cout << double(*this);
            cout << " | ";
            cout << " Type: ";
            cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    Portfolio::operator double() const
    {
        return m_value;
    }

    Portfolio::operator const char*() const
    {
        return m_stock;
    }

    Portfolio::operator char() const
    {
        return m_type;
    }

    Portfolio::operator bool() const
    {
        bool result = false;

        // Return true if investment type is appropriate value
        if (m_type == 'G' || m_type == 'V' || m_type == 'I') {
            result = true;
        }

        return result;
    }

    Portfolio& Portfolio::operator+=(double value)
    {
        // Adding a double to m_value as long as it's valid
        if (*this && value >= 0) {
            m_value += value;
        }
        return *this;
    }

    Portfolio& Portfolio::operator-=(double value)
    {
        // Subtracting a double from m_value as long as it's valid
        if (*this && value >= 0) {
            m_value -= value;

        }
        return *this;
    }

    bool Portfolio::operator~() const
    {
        bool result = false;

        // Evaluating if m_value is a negative, if so return true
        if (m_value < 0) {
            result = true;
        }
        return result;
    }

    Portfolio Portfolio::operator<<(Portfolio& leftDollar)
    {
        //  Moving the money and making sure it doesn't return back

        if (this != &leftDollar && *this && leftDollar) {

            m_value += leftDollar.m_value;

            // Setting ALL of leftDollar to empty
            leftDollar.emptyPortfolio();
        }
        return *this;
    }

    Portfolio Portfolio::operator>>(Portfolio& rightDollar)
    {
        // Moving money and making sure it doesn't return
        if (&rightDollar != this && *this && rightDollar) {
            rightDollar.m_value += m_value;

            // Set to empty
            this->emptyPortfolio();
        }
        return *this;
    }

    double Portfolio::value() const
    {
        return m_value;
    }

    double operator+(const Portfolio& left, const Portfolio& right)
    {
        double result{};

        // Shifting from left to right using helper function
        if (left.value() >= 0 && right.value() >= 0) {
            result = left.value() + right.value();

            // Setting right to empty
        }
        return result;
    }

    double operator+=(double& left, const Portfolio& right)
    {
        double result{ 0 };

        // Shifting from left to right using helper function
        if (right.value() >= 0) {
            result = left += right.value();
        }
        return result;
    }


}