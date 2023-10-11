//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Alicia Atienza
//ID: 38782074
//Email: aatienza1@myseneca.ca
//Date 10/9/2023
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iomanip>
#include <iostream>
#include "Label.h"
namespace sdds {


	Label::Label()
	{
		// Using default frame
		strcpy(m_frame, defaultFrame);

		// Set m_content to nullptr for ostream function
		m_content = nullptr;

	}
	Label::Label(const char* frameArg)
	{
		if (frameArg == nullptr) {

			// Using default frame
			strcpy(m_frame, defaultFrame);
		}
		else {

			// Using argument name
			strcpy(m_frame, frameArg);
		}

		// Set m_content to nullptr for ostream function
		m_content = nullptr;
	}
	Label::Label(const char* frameArg, const char* content)
	{
		if (frameArg == nullptr) {

			// Using default frame
			strcpy(m_frame, defaultFrame);
		}
		else {

			// Using argument name
			strcpy(m_frame, frameArg);
		}

		m_content = new char[strlen(content) + 1];
		strcpy(m_content, content);
	}
	Label::~Label()
	{
		delete[] m_content;
	}
	std::istream& Label::readLabel()
	{
		char content[LABEL_MAX] = {};

		// Getting the content of the label, max limit is 70
		std::cin.getline(content, LABEL_MAX);


		delete[] m_content;
		m_content = new char[strlen(content) + 1];
		strcpy(m_content, content);

		m_length = strlen(content);

		if (m_length >= LABEL_MAX) {
			m_length = 71;
		}

		return std::cin;
	}
	std::ostream& Label::printLabel() const
	{
		// If there is text inside of m_content we want to print it out
		if (m_content != nullptr) {
			// Top frame
			std::cout << m_frame[0];
			std::cout.fill(m_frame[1]);
			std::cout.width(m_length + 3);
			std::cout << m_frame[2] << std::endl;

			// Frame above text line
			std::cout << m_frame[7];
			std::cout.width(m_length + 3);
			std::cout.fill(' ');
			std::cout << m_frame[3] << std::endl;

			// Middleline
			std::cout << m_frame[7];
			std::cout.width(m_length + 1);
			std::cout << m_content << " ";
			std::cout << m_frame[3] << std::endl;

			// Frame below text line
			std::cout << m_frame[7];
			std::cout.width(m_length+ 3);
			std::cout.fill(' ');
			std::cout << m_frame[3] << std::endl;

			// Bottom Frame
			std::cout << m_frame[6];
			std::cout.width(m_length + 3);
			std::cout.fill(m_frame[5]);
			std::cout << m_frame[4];
		}

		return std::cout;
	}
	Label& Label::text(const char* content)
	{
		m_length = strlen(content);
		m_content = new char[strlen(content) + 1];
		strcpy(m_content, content);
		return *this;
	}
}