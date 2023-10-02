// -----------------------------------------------------------
// Name:Alicia Atienza                 Date:10/02/2023            StudentID: 38782074		email:aatienza1@myseneca.ca
//*********************************************************************** /
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Train.h"

using namespace sdds;
namespace sdds{
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
			else{
				return false;
			}

		}
		else {
			return false;
		}

	}
	bool Train::validNoOfPassengers(int value)const {

		// Checking that value is valid and less than the maximum amount of passengers
		return (value > 0 && value < MAX_NO_OF_PASSENGERS);
	}
	void Train::set(const char* name) {
		delete[] m_trainName;
		m_trainName = nullptr;
		
		// Checking that name is not null and not an empty stringretu
		if (name != nullptr && name[0] != '\0' ) {

			// Allocating memory for the new train name
			int length = strlen(name);
			m_trainName = new char[length + 1];
			strcpy(m_trainName,name);
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

		// If everything is invalid
		if (name != nullptr && name[0] != '\0' && validNoOfPassengers(noOfPassengers) && validTime(departure)) { 

			// Allocating the memory for m_trainName
			int length = strlen(name);
			m_trainName = new char[length + 1];

			// Copying all the input variables into our member variables
			strcpy(m_trainName, name);
			m_noOfPassengers = noOfPassengers;
			m_departTime = departure;
		}

		// If just time is invalid
		else if (name != nullptr && name[0] != '\0' && validNoOfPassengers(noOfPassengers) && !validTime(departure)) {
			// Allocating the memory for m_trainName
			int length = strlen(name);
			m_trainName = new char[length + 1];

			// Copying all the input variables into our member variables
			strcpy(m_trainName, name);
			m_noOfPassengers = noOfPassengers;
			m_departTime = -1;
		}

		// If time and passengers are invalid
		else if (name != nullptr && name[0] != '\0' && !validNoOfPassengers(noOfPassengers) && !validTime(departure)) {

			// Allocating the memory for m_trainName
			int length = strlen(name);
			m_trainName = new char[length + 1];

			// Copying all the input variables into our member variables
			strcpy(m_trainName, name);
			m_noOfPassengers = -1;
			m_departTime = -1;
		}
		else {

			// Train is invalid, m_trainName already nulptr
			m_noOfPassengers = -1;
			m_departTime = -1;
		}
	}

	void Train::finalize()
	{
		if (m_trainName != nullptr)
		{
			delete[] m_trainName;
			m_trainName = nullptr;
		}
	}
	bool Train::isInvalid() const
	{
		// If any of the states are invalid, return true
		return (m_trainName == nullptr || m_noOfPassengers == -1 || m_departTime == -1 );
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
		if (!isInvalid()) {
			return m_departTime;
		}
		else {
			return -1;
		}
		 
	}
	void Train::display() const
	{
		// If invalid is false, display
		if (!isInvalid()) {
			std::cout << 
				"NAME OF THE TRAIN:    " << this->m_trainName << std::endl <<
				"NUMBER OF PASSENGERS: " << this->m_noOfPassengers << std::endl <<
				"DEPARTURE TIME:       " << this->m_departTime << std::endl;
		}
		else {
			std::cout << "Train in an invalid State!" << std::endl;
		}
	}
	bool Train::load(int& input)
	{
		int passengers{};
		int totalPassengers{};

		std::cout << "Enter number of passengers boarding:" << std::endl;
		std::cout << "> ";
		std::cin >> passengers; 

		// Calculate if new total would be more than max (100 passengers)
		if ((m_noOfPassengers + passengers) > MAX_NO_OF_PASSENGERS) { 

			// Find the difference of the passengers and return that
			input = (m_noOfPassengers + passengers) - MAX_NO_OF_PASSENGERS; 

			// Fill the train 
			m_noOfPassengers = 1000; 
			return false; 
		}
		else {

			// They are valid, fill the train
			m_noOfPassengers += passengers; 
			return true; 
		}
	}

	bool Train::updateDepartureTime()
	{
		int departure{};
		std::cout << "Enter new departure time:" << std::endl;
		std::cout << "> ";
		std::cin >> departure;

		// If departure time is valid return true, else false and invalidate depart time
		if (validTime(departure)) {
			m_departTime = departure;
			return true;
		}
		else {
			m_departTime = -1;
			return false;
		}
	}

	bool Train::transfer(const Train& other)
	{
		// Check if either train is in an invalid state
		if (this->isInvalid() || other.isInvalid()) {
			return false;
		}
		else {
			// Calculate the length of the combined name
			int combinedLength = strlen(this->m_trainName) + strlen(other.m_trainName) + 3;

			// Allocate memory for the combined name
			char* combinedName = new char[combinedLength];

			// Copy the name of the current train to the combinedName
			strcpy(combinedName, this->m_trainName);

			// Append ", " and the second name
			strcat(combinedName, ", ");
			strcat(combinedName, other.m_trainName);

			// Deallocate memory for the current train's name
			delete[] this->m_trainName;

			// Set the new name for the current Train
			this->m_trainName = combinedName;

			// Update the number of passengers for the current train
			this->m_noOfPassengers += other.m_noOfPassengers;

			return true;
		}
	}

}