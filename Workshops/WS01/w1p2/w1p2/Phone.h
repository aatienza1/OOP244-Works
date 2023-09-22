//Name: Alicia Atienza 
//Email: aatienza1@myseneca.ca
//ID: 68789041
//Date: 9/18/2023
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H
#include <cstdio>

using namespace std;
namespace sdds {

	struct Phone
	{
		char name[51];
		char areaCode[4];
		char prefix[4];
		char number[5];

	};
	//Prototype for phone module
	void phoneDir(const char* programTitle, const char* fileName);

	//Output for phone title
	void phoneTitle(const char* programTitle);

	//Output for broken phone
	void brokenPhone(const char* fileName);

	//Searching through phone
	void phoneSearch(const char* programTitle, std::FILE* fptr);

	//Running phone directory
	void runPhoneDirectory(const char* programTitle, const char* fileName);

}


#endif // !SDDS_PHONE_H