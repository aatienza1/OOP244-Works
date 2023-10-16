// -----------------------------------------------------------
// Name:Alicia Atienza                 Date:9/29/2023            StudentID: 38782074		email:aatienza1@myseneca.ca
//*********************************************************************** /
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Train.h"
#define MIN_TIME 700
#define MAX_TIME 2300
#define MAX_NO_OF_PASSENGERS 1000

using namespace sdds;
namespace sdds {
	void Train::initialize() {
		m_trainName = nullptr;
		m_noOfPassengers = -1;
		m_departTime = -1;
	}
	bool Train::validTime(int value)const {

		// Checking if the value is in between the Maximum and Minimum minutes
		if (value > MIN_TIME && value < MAX_TIME) {

			// Preparing the value integer for the 59 minute comparison
			int lastTwoDigits = value % 100;

			// Comparing the last two digits to 59 minutes
			if (lastTwoDigits <= 59) {
				return true;
			}
		}
		else {
			return false;
		}

		return false;
	}
	bool Train::validNoOfPassengers(int value)const {

		// Checking that value is valid and less than the maximum amount of passengers
		return (value > 0 && value < MAX_NO_OF_PASSENGERS);
	}
	void Train::set(const char* name) {
		delete[] m_trainName;
		m_trainName = nullptr;

		// Checking that name is not null and not an empty stringretu
		if (name != nullptr && name[0] != '\0') {

			// Allocating memory for the new train name
			int length = strlen(name);
			m_trainName = new char[length + 1];
			strcpy(m_trainName, name);
		}

	}
	void Train::set(int noOfPassengers, int departure)
	{
		// If passengers and time are valid, copy the variables
		if (validNoOfPassengers(noOfPassengers) && validTime(departure)) {
			m_noOfPassengers = noOfPassengers;
			m_departTime = departure;
		}
		else {
			m_noOfPassengers = -1;
			m_departTime = -1;
		}
	}
	void Train::set(const char* name, int noOfPassengers, int departure)
	{
		// Deleting m_trainName and making int nullptr
		delete[] m_trainName;
		m_trainName = nullptr;

		if (name != nullptr && name[0] != '\0' && validNoOfPassengers(noOfPassengers) && validTime(departure)) {

			// Allocating the memory for m_trainName
			int length = strlen(name);
			m_trainName = new char[length + 1];

			// Copying all the input variables into our member variables
			strcpy(m_trainName, name);
			m_noOfPassengers = noOfPassengers;
			m_departTime = departure;
		}
		else {

			// Train is invalid, m_trainName already nulptr
			m_noOfPassengers = -1;
			m_departTime = -1;
		}
	}

	void Train::finalize()
	{
		delete[] m_trainName;
	}
	bool Train::isInvalid() const
	{
		// If any of the states are invalid, return true
		return (m_trainName == nullptr || m_noOfPassengers == -1 || m_departTime == -1);
	}
	int Train::noOfPassengers() const
	{
		// Return number of passengers if invalid is false
		if (!isInvalid()) return m_noOfPassengers;
		return -1;
	}
	const char* Train::getName() const
	{
		// Return train name if invalid is false
		if (!isInvalid()) return m_trainName;
		return "Invalid";
	}
	int Train::getDepartureTime() const
	{
		// Return departure time if invalid is false
		if (!isInvalid()) return m_departTime;
		return -1;
	}
	void Train::display() const
	{
		// If invalid is false, display
		if (!isInvalid()) {
			std::cout <<
				"NAME OF THE TRAIN:    " << m_trainName << std::endl <<
				"NUMBER OF PASSENGERS: " << m_noOfPassengers << std::endl <<
				"DEPARTURE TIME:       " << m_departTime << std::endl;
		}
		else {
			std::cout << "Train in an invalid State!" << std::endl;
		}
	}
}