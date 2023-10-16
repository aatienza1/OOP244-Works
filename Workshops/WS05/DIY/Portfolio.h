/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 10/14/2023            Reason
// ID: 38782074
// Email: aatienza1@myseneca.ca
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_

#include <iostream>

namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;

   public:
       void emptyPortfolio();
       Portfolio();
       Portfolio(double value, const char* stock, char type);
       void dispPortfolio() const;
       std::ostream& display() const;
       // Gets the value of Portfolio m_value without modifications
       operator double() const;

       // Name for m_stock
       operator const char* () const;

       // Type of investment 
       operator char() const;

       // Returns true if investment type is correct
       operator bool() const;

       // Add a double to portfolio
       Portfolio &operator +=(double value);

       // Subtract the double value from portfolio
       Portfolio& operator -=(double value);

       // Return true if m_value is negative
       bool operator ~()const;

       // Moving investment, total investment will be on left sum of portfolios
       Portfolio operator<<(Portfolio& leftDollar);

       // Moving investment, total investment will be on right sum of portfolios
       Portfolio operator>>(Portfolio& rightDollar);

       // Helper function
       double value()const;
   };

   // Accepts left and right and returns a double
   double operator+(const Portfolio& left, const Portfolio& right);

   // Accepts a double and returns a double
   double operator+=(double& left, const Portfolio& right);
}
#endif // SDDS_Portfolio_H_