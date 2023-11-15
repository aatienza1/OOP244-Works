// Name: Alicia Atienza                Date: 11/09/2023            ID: 38782074			email:aatienza1@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Container.h"
#include "Pack.h"
namespace sdds {
    Pack::Pack(const char* content, int size, int unitSize, int noOfUnits) : Container(content, size* unitSize, noOfUnits* unitSize) {
        if (unitSize > 0) {
            // Set the unitSize attribute for Pack
            m_unitSize = unitSize;
            strcpy(m_content, content);
        }
        else {
            // Set the Pack to an empty state
            Container::setEmpty();
        }
    }
    int Pack::operator+=(int add)
    {

        int unitsAdded = Container::operator+=(add * m_unitSize) / m_unitSize;

        return unitsAdded;
    }
    int Pack::operator-=(int remove)
    {
        // Base class call
        int unitsRemoved = Container::operator-=(remove * m_unitSize); 

        // Calculate the units removed in terms of 'remove'
        unitsRemoved = unitsRemoved / m_unitSize;

        return unitsRemoved;
    }
    int Pack::unit() const
    {
        return m_unitSize;
    }
    int Pack::noOfUnits() const
    {
        return Container::volume() / m_unitSize;
    }

    int sdds::Pack::size() const
    {
        return Container::capacity() / m_unitSize;
    }

    Pack& Pack::clear(int packSize, int unitSize, const char* description)
    {
        if (m_unitSize > 0) {
            Container::clear(packSize * unitSize, description);
            m_unitSize = unitSize;
            
        }
        return *this;
    }

    std::ostream& Pack::print(std::ostream& ostr) const
    {
        Container::print(ostr); 
        if (this) {
            ostr << ", " << noOfUnits() << " in a pack of " << size();
        }
        return ostr;
    }

    std::istream& Pack::read(std::istream& istr) {
        bool valid = Container::volume() <= Container::capacity();

        // Checking if container is valid
        if (!valid) {
            std::cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
        }
        else {
            // Checks if number of units can fit in the size of the container
            if (noOfUnits() < size()) {
                int tempInt{};
                std::cout << "Add to " << m_content << ": " << "(" << volume() << "cc/" << capacity() << "), " << noOfUnits() << " in a pack of " << size() << std::endl;
                std::cout << "> ";
                istr >> tempInt;

                // Integer entry fail
                if (istr.fail()) {
                    while (istr.fail()) {
                        std::cout << "Invalid Integer, retry: ";
                        istr.clear();
                        istr >> tempInt;
                    }
                }

                // VAlue check
                else if (tempInt < 1 || tempInt >(size() - noOfUnits())) {
                    std::cout << "Value out of range [1<=val<=" << (size() - noOfUnits()) << "]: ";
                    while (tempInt < 1 || tempInt >(size() - noOfUnits())) {
                        istr >> tempInt;
                    }
                }

                // Using base class operator +=
                int added = Container::operator+=(tempInt * m_unitSize);
                
                // Showing pack size
                std::cout << "Added " << added/m_unitSize << std::endl;
            }
            else {
                std::cout << "Pack is full!, press <ENTER> to continue...";
            }
        }

        // Wait for Enter key press
        std::cin.get();

        return istr;
    }

}
