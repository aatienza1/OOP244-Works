
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Alicia Atienza
//ID: 38782074
//Email: aatienza1@myseneca.ca
//Date 10/7/2023

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iomanip>
#include <iostream>
#include "CarInventory.h"

namespace sdds {

	// Reset by setting to nullptr and zero
	void CarInventory::resetInfo()
	{
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0.0;
	}

	// Default constructor
	CarInventory::CarInventory()
	{
		resetInfo();
	}

	// Constructor with default parameters
	CarInventory::CarInventory(const char* type, const char* brand, const char* model,
		int year, int code, double price) {
		resetInfo();
		setInfo(type, brand, model, year, code, price);
	}

	// Destructor
	CarInventory::~CarInventory()
	{
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
		resetInfo();
	}

	// Setting dynamic info
	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		// Deallocate the old memory if it was previously allocated
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;

		// Allocate new memory and copy data
		int length = strlen(type);
		m_type = new char[length + 1];
		strcpy(m_type, type);

		length = strlen(brand);
		m_brand = new char[length + 1];
		strcpy(m_brand, brand);

		length = strlen(model);
		m_model = new char[length + 1];
		strcpy(m_model, model);

		m_year = year;
		m_code = code;
		m_price = price;

		return *this;
	}



	// Display info
	void CarInventory::printInfo() const
	{
		std::cout << "| " << std::left << std::setw(11) << m_type;
		std::cout << "| " << std::left << std::setw(17) << m_brand;
		std::cout << "| " << std::left << std::setw(16) << m_model;
		std::cout << " | " << m_year << " |";
		std::cout << std::setw(5) << std::right << m_code << " |";
		std::cout << std::setw(10) << std::fixed << std::setprecision(2) << m_price << " |" << std::endl;
	}

	// Checking if names + year/code/price has been validated
	bool CarInventory::isValid() const {
		bool validation = false;
		if (m_type != nullptr && m_brand != nullptr && m_model != nullptr &&
			m_year >= 1990 && m_code >= 100 && m_code <= 999 && m_price > 0) {
			validation = true;
		}
		return validation;
	}

	// Checking if cars are similar + for nullptr
	bool CarInventory::isSimilarTo(const CarInventory& car) const
	{
		bool isSimilar = false;
		if ((m_year == car.m_year) &&
			(strcmp(m_type, car.m_type) == 0) &&
			(strcmp(m_brand, car.m_brand) == 0) &&
			(strcmp(m_model, car.m_model) == 0) &&
			(m_type != nullptr) &&
			(m_brand != nullptr) &&
			(m_model != nullptr) &&
			(car.m_type != nullptr) &&
			(car.m_brand != nullptr) &&
			(car.m_model != nullptr)) {
			isSimilar = true;
		}

		return isSimilar;
	}

	// Iterating through to see if any car names are similar
	int find_similar(CarInventory car[], const int num_cars)
	{
		int found = 0;
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {

				if (car[i].isSimilarTo(car[j])) {
					found = i;
				}
			}
		}
		return found;
	}
}