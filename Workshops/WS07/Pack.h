// Name: Alicia Atienza                Date: 11/09/2023            ID: 38782074			email:aatienza1@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_PACK_H
#define SDDS_PACK_H
namespace sdds {
	class Pack : public Container {
	private:
		int m_unitSize{};
		char m_content[50]{};
	public:
		Pack(const char* content, int size, int unitSize = 330, int noOfUnits = 0);
		int operator+= (int add);
		int operator-=(int remove);

		int unit()const;
		int noOfUnits()const;
		int size()const;

		Pack& clear(int packSize, int unitSize, const char* description);
		std::ostream& print(std::ostream& ostr)const; 
		std::istream& read(std::istream& istr);

	};
	std::ostream& operator<<(std::ostream& ostr, const Container& container);
	std::istream& operator>>(std::istream& istr, Container& container);
}

#endif