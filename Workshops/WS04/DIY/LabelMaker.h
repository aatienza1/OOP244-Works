//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Alicia Atienza
//ID: 38782074
//Email: aatienza1@myseneca.ca
//Date 10/7/2023
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"

namespace sdds {
	class LabelMaker {
		Label* m_labels;

		// Number of labels
		int m_labelNumber{};

		// Length
		int m_length{};

		// Dynamic array for storing label names
	public:
		// Dynamic array of labels 
		LabelMaker(int noOfLabels);

		// Gets content of the labels
		void readLabels();

		// Prints the labels
		void printLabels();

		// Deallocates memory when labelmaker goes out of scope
		~LabelMaker();
	};
}
#endif //SDDS_LABELMAKER_H