// Name: Alicia Atienza                Date: 11/09/2023            ID: 38782074			email:aatienza1@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Container.h"
namespace sdds {
	Container& Container::setEmpty()
	{
		m_content[0] = '\0';
		m_capCC = -1;
		m_volume = 0;
		return *this;
	}
	int Container::capacity() const
	{
		// Return capacity
		return m_capCC;
	}
	int Container::volume() const
	{
		// Return volume
		return m_volume;
	}
	Container::Container(const char* content, int capacity, int volume)
	{
		// Copy description if correct, set to invalid if not
		if (content != nullptr && capacity > volume) {
			strcpy(m_content, content);
			m_capCC = capacity;
			m_volume = volume;
		}
		else {
			setEmpty();
		}
	}
	int Container::operator+=(int add)
	{
		// Addition statement for if it does not exceed volume
		if (!(add < 0) && !(m_volume == m_capCC) && ((add + m_volume) <= m_capCC)) {
			m_volume += add;
		}
		// Exceeds volume
		else if ((add + m_volume) > m_capCC && m_volume < m_capCC) {
			add = m_capCC - m_volume;
			m_volume += add;
		}
		return add;
	}
	int Container::operator-=(int remove)
	{
		// Removes if it doesn't go into negatives
		if (m_volume > remove) {
			m_volume -= remove;
		}
		// Removal will go to negative
		else{
			remove = m_volume;
			m_volume = 0;
		}
		return remove;
	}

	Container::operator bool() const
	{
		bool result = false;
		if (m_content != nullptr && m_capCC >= 0) {
			result = true;
		}
		return result;
	}

	Container& Container::clear(int capacity, const char* desc)
	{
		 // Clearing as long as state isn't invalid
		if (capacity > 0 && desc != nullptr) {
			strcpy(m_content, desc);
			m_capCC = capacity;
		}
		return *this;
	}
	std::ostream& Container::print(std::ostream& ostr) const
	{

		// Printing if everything is valid
		if (m_content != nullptr && m_volume <= m_capCC && m_capCC >= 0 && m_volume >= 0) {
			ostr << m_content << ": (" << m_volume << "cc/" << m_capCC << ")";
		}
		else {
			// Invalid container
			ostr << "****: (**cc/***)";
		}
		return ostr;
	}
	std::istream& Container::read(std::istream& istr)
	{
		int tempInt{};
		bool valid = m_content != nullptr && m_volume <= m_capCC;
		// If container is broken print the following

		if (!valid) {
			std::cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << std::endl;
		}
		else {
			std::cout << "Add to " << m_content << ": " << "(" << m_volume << "cc" << "/" << m_capCC << ")" << std::endl;
			// IF statement for if container has no remainder
			std::cout << "> ";
			std::cin >> tempInt;
				if (tempInt >= 1 && tempInt <= 220000) {
					if ((m_volume + tempInt) < m_capCC) {
						m_volume += tempInt;
						std::cout << "Added " << tempInt << " CCs" << std::endl;
						
					}
					// If statement with remainder
					else {
						int remainder = m_capCC - m_volume;
						m_volume += remainder;
						tempInt = tempInt - remainder;
						std::cout << "Added " << remainder << " CCs" << std::endl;
					}
				}
				// Invalid integer entry
				else if (std::cin.fail()){
					while (std::cin.fail()) {
						std::cout << "Invalid Integer, retry: ";
						std::cin.clear();
						std::cin.ignore(256, '\n');
						std::cin >> tempInt;
					}
				}

				// Invalid range
				else if (tempInt < 1 && tempInt > 220000) {
					std::cout << "Value out of range [" << 1 << "<=val<=" << 220000 << "]: ";
					while (tempInt < 1 && tempInt > 220000) {
						std::cin >> tempInt;
					}
				}

		}
		return istr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Container& container)
	{
		container.print(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Container& container)
	{
		container.read(istr);
		return istr;
	}

}
