//Name: Alicia Atienza 
//Email: aatienza1@myseneca.ca
//ID: 68789041
//Date: 9/18/2023
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <cstring>
#include "cStrTools.h"
#include "Phone.h"


using namespace sdds;
using namespace std;

namespace sdds {
	void phoneDir(const char* programTitle, const char* fileName) {
		char partialName[50];

		// Arrays for the area code formatting
		char name[50];
		char areaCode[4];
		char prefix[4];
		char number[5];
		char fullName[50];

		// Comparison Arrays
		char lowerCaseFullName[50];
		char lowerCasePartialName[50];
		
		//Checking for file
		FILE* fptr = fopen(fileName, "r");
		if (fptr) {

			//	When running, after showing the title, the program should prompt for a partial name entry.
			cout << programTitle << " phone direcotry search" << endl; cout
				<< "-------------------------------------------------------" << endl;

			// Do loop to keep partial name entries until exit is entered
			do {
				cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
				cout << "> ";
				cin >> partialName;

				// Rewind the file because after typing input it would not display anything
				rewind(fptr);
				
				//	After receiving the partial name the program should search through the names 
				// in the file and if a name is found containing the partial entry, the matching phone record is displayed
				
				//This format was taken from the assignment hint, number of fields it needs to find is 4
				while (fscanf(fptr, "%[^\t]\t%s\t%s\t%s\n", name, areaCode, prefix, number) == 4) {

					// Copying field 1 into the full name
					strCpy(fullName, name);

					// Removing white space from full name
					trim(fullName);

					// Converting both partialNAme and the fullName into lower case in preparation for strStr
					toLowerCaseAndCopy(lowerCaseFullName, fullName);
					toLowerCaseAndCopy(lowerCasePartialName, partialName);

					// Comparing the partial results with strSTr
					const char* result = strStr(lowerCaseFullName, lowerCasePartialName);

					// If the results are true, then print out the fields above
					//	Nothing is displayed if no match is found.
					if (result) {
						cout << name << ": " << "(" << areaCode << ") " << prefix << "-" << number << endl;

					}

				}
				//	If the user enters '!' the program exits.
			} while (strcmp(partialName, "!") != 0);

			//	A thank you message is displayed at the end of the program.

			cout << "Thank you for using " << programTitle << " directory." << endl;

		}

		//	If the data file cannot be opened the program exits displaying an error message
		else {

			cout << "Broken Phone Book phone direcotry search" << endl; 
			cout << "-------------------------------------------------------" << endl;

			cout << fileName << " file not found!" << endl;

			cout << "Thank you for using Broken Phone Book directory." << endl;

		}
		fclose(fptr);
	}
}