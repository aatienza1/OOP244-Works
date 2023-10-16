/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 10/14/2023            Reason
// ID: 38782074
// Email: aatienza1@myseneca.ca
***********************************************************************/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

   const int Boen747Capacity = 388;
   const int FuelTankCapacity = 238840;

   class Flight {

      int m_passengers = 0;
      double m_fuel = 0;
      char m_title[16];
      void emptyPlane();

   public:
      Flight();
      Flight(int passengers, double fuel, const char* title);
      std::ostream& display()const;
      // Returns true or false if plane has min amount of fuel to fly
      operator bool() const;

      // Returns flight # passengers
      operator int() const;

      // Returns flight fuel
      operator double() const;

      // Returns Flight title
      operator const char* () const;

      // Returns true if flight number == 0
      bool operator~() const;

      // Transfer full flight details to another flight object
      Flight &operator=(Flight &flightMove);

      // Transfer only the passnegers to another flight object
      Flight &operator=(int flightNum);

      // Transfer only the flight fuel to another object
      Flight &operator=(double flightFuel);

      // Adding more fuel to the plane
      Flight &operator+=(double fuelUp);

      // Adding more passengers to the plane
      Flight &operator+=(int passUp);

      // Subtracting fuel that's being used from the plane
      Flight &operator-=(double fuelDown);

      // Passengers disembarking the flight
      Flight &operator-=(int passDown);

      // Total number of passengers to be the sum of max capacity
      Flight &operator<<(Flight& rightFlight);

      // Passengers transferring planes
      Flight &operator>>(Flight& leftFlight);

      // Sum of passengers from current flight and other flight
      int operator+(const Flight &flightRef)const;

      // Helper function
      int value()const;
   };
   int& operator+=(int& passTransfer, const Flight& flightRef);

}
#endif // SDDS_FLIGHT_H