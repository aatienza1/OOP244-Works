//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Alicia Atienza
//ID: 38782074
//Email: aatienza1@myseneca.ca
//Date 10/7/2023
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#define FRAME_MAX 9
#define LABEL_MAX 71

namespace sdds {
	// Default frame that never changes
	const char defaultFrame[FRAME_MAX] = { "+-+|+-+|" };

	class Label {
		// Frame that will change to either default or user assigned
		char m_frame[FRAME_MAX] = {};

		// Dynamic name
		char* m_content{};

		// Frame length
		int m_length{};
	public:
		// Create empty label with default frames
		Label();

		// Creates empty label and set frames unless arg is nullptr
		Label(const char* frameArg);

		// Creates a label with the frame set to frameArg, dynamic and never more than 70
		Label(const char* frameArg, const char* content);

		// Make sure no memory leak
		~Label();

		// Reads content and stores it in the label
		std::istream& readLabel();

		// Prints the label around content
		std::ostream& printLabel()const;

		// Sets content of the label dynamically
		Label& text(const char* content);
	};

}
#endif //SDDS_LABEL_H