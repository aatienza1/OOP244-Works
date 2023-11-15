// Name: Alicia Atienza                Date: 11/09/2023            ID: 38782074			email:aatienza1@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H
namespace sdds {

	class Container {
	private:
		char m_content[50]{};
		int m_capCC{};
		int m_volume{};
	protected:
		Container& setEmpty();
		int capacity()const;
		int volume()const;
	public:
		Container(const char* content, int capacity, int volume = 0);

		virtual int operator+=(int add);
		virtual int operator-=(int remove);
		operator bool()const;

		virtual ~Container() = default;

		virtual Container& clear(int capacity, const char* desc);
		virtual std::ostream& print(std::ostream& ostr)const;
		virtual std::istream& read(std::istream& istr);

	};
	std::ostream& operator<<(std::ostream& ostr,const Container& container );
	std::istream& operator>>(std::istream& istr, Container& container);

}

#endif