//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Alicia Atienza
//ID: 38782074
//Email: aatienza1@myseneca.ca
//Date 10/7/2023

#ifndef SDDS_CAR_INVENTORY_H
#define SDDS_CAR_INVENTORY_H

namespace sdds {
	class CarInventory {
	private:
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		void resetInfo();
	public:
		CarInventory();
		CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1.0);
		~CarInventory();
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const CarInventory& car) const;
	};

	int find_similar(CarInventory car[], const int num_cars);
}

#endif // SDDS_CAR_INVENTORY_H
