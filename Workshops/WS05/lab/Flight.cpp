/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date:10/14/2023            Reason
// ID: 38782074
// Email: aatienza1@myseneca.ca
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title , "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title,title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char *)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight::operator bool() const
    {

        bool result = false;

        // Return true if plane is valid
        if (m_passengers > 0 && m_fuel >= (m_passengers * 600)) result = true;

        return result;
    }

    Flight::operator int() const
    {
        // Passenger return
        return m_passengers;
    }

    Flight::operator double() const
    {
        // Fuel return
        return m_fuel;
    }

    Flight::operator const char* () const
    {
        // Title return
        return m_title;
    }

    bool Flight::operator~() const
    {
        bool result = false;

        // Return true if there are no more passengers
        if (m_passengers == 0) result = true;
        return result;
    }

    Flight& Flight::operator=(Flight& flightMove)
    {
        // Moving everyone from the right plane to the left plane
        m_fuel = flightMove.m_fuel;
        m_passengers = flightMove.m_passengers;
        strcpy(m_title, flightMove.m_title);

        // Showing how the right plane is now empty
        flightMove.emptyPlane();

        return *this;
    }

    Flight& Flight::operator=(int flightNum)
    {
        // Setting flight numbers of passengers to valid (positive/not more than capacity)
        if (flightNum > 0 && flightNum <= Boen747Capacity) {
            m_passengers = flightNum;
        }
        else {

            // Set flight to 0 if not valid
            emptyPlane();
        }

        return *this;
    }

    Flight& Flight::operator=(double flightFuel)
    {
        // Setting fuel numbers to valid (positive/not more than capacity)
        if (flightFuel > 0.0 && flightFuel <= FuelTankCapacity) {
            m_fuel = flightFuel;
        }

        // Emptying fuel else wise
        else {
            emptyPlane();
        }
        return *this;
    }

    Flight& Flight::operator+=(double fuelUp)
    {
        // Adding more fuel to the tank as long as the value isn't negative or the plane is at cap
        if (!(fuelUp < 0) && !(m_fuel == FuelTankCapacity)) {
            m_fuel += fuelUp;
        }
        return *this;
    }

    Flight& Flight::operator+=(int passUp)
    {
        // Adding more passengers to the plane as long as the value isn't negative or the plane is not at full capacity
        if (passUp > 0 && (m_passengers + passUp) <= Boen747Capacity) {
            m_passengers += passUp;
        }
        return *this;
    }

    Flight& Flight::operator-=(double fuelDown)
    {
        // Pumping fuel out of the tank as long as the value isn't negative or tank is empty
        if (!(m_fuel <= 0.0) && !(fuelDown < 0.0)) {
            m_fuel -= fuelDown;
        }
        return *this;
    }

Flight& Flight::operator-=(int passDown)
{
    // Disembarking passengers from the plane
    if (m_passengers >= passDown && passDown >= 0) {
        m_passengers -= passDown;
    }

    return *this;
}

    Flight& Flight::operator<<(Flight& rightFlight)
    {
        // Calculating if planes are valid
        if (&rightFlight != this && m_passengers > 0 && m_passengers < Boen747Capacity) {

            // Calculating space by subtracting passengers from maximum
            int availableSpace = Boen747Capacity - m_passengers;

            // Setting the amount of passengers we want to move
            int passengersToMove = availableSpace;

            // If amount of passengers in the flight are more than what's in flight
            // set passengers to passengers to satisfy above if statement and say that it's "Full"
            if (passengersToMove > rightFlight.m_passengers) {
                passengersToMove = rightFlight.m_passengers;
            }

            // Add these passengers to move
            m_passengers += passengersToMove;

            // Subtracting number of passengers in right flight by remaining
            rightFlight.m_passengers -= passengersToMove;
        }

        return *this;
    }



    Flight& Flight::operator>>(Flight& leftFlight)
    {
        // Calculating if planes are valid
        if (&leftFlight != this && leftFlight.m_passengers < Boen747Capacity) {

            // How much space is available to move
            int availableSpace = Boen747Capacity - leftFlight.m_passengers;

            // This is how many passengers we can move
            int passengersToMove = availableSpace;

            // If number of passengers to move is greater than the people
            // in the plane we're moving, we don't move it
            if (passengersToMove > m_passengers) {
                passengersToMove = m_passengers;
            }

            // Move passengers from this Flight to leftFlight
            leftFlight.m_passengers += passengersToMove;

            // Subtracting number of passengers in left flight by remaining
            m_passengers -= passengersToMove;
        }

        return *this;
    }


    int Flight::operator+(const Flight& flightRef) const
    {
        int result = 0;
    
        // Adding the sum of passengers
        if (m_passengers > 0 && flightRef.m_passengers > 0) {

            // If flights are valid, return the number of passengers
            result = m_passengers + flightRef.m_passengers;
        }
        // Return false if not (0)
        return result;
    }

    int Flight::value() const
    {
        return m_passengers;
    }


    int &operator+=(int& passTransfer, const Flight& flightRef)
    {
        // Using helper function 
        passTransfer += flightRef.value();
        return passTransfer;

    }

}