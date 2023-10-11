//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Alicia Atienza
//ID: 38782074
//Email: aatienza1@myseneca.ca
//Date 10/9/2023
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LabelMaker.h"
#include "Label.h"

namespace sdds {

	LabelMaker::LabelMaker(int noOfLabels) {
		m_labelNumber = noOfLabels;

		// Dynamically allocated
		m_labels = new Label[m_labelNumber]; 
	}

	void LabelMaker::readLabels()
	{
		std::cout << "Enter " << m_labelNumber << " labels:" << std::endl;
		// Iterating through every label
		for (int i = 0; i < m_labelNumber; i++) {

			std::cout << "Enter label number " << i + 1 << '\n' << "> ";

			// Using read function from Labels.h to read the labels
			m_labels[i].readLabel();
		}

	}
	void LabelMaker::printLabels()
	{
		//Iterating through every label again
		for (int i = 0; i < m_labelNumber; i++) {

			// Using the print function to print out every label
			m_labels[i].printLabel();
			std::cout << std::endl;
		}
	}
	LabelMaker::~LabelMaker()
	{
		// Deallocate memory
		delete[] m_labels;
	}
}
