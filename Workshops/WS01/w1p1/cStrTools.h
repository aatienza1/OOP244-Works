//Name: Alicia Atienza 
//Email: aatienza1@myseneca.ca
//ID: 68789041
//Date: 9/13/2023

#ifndef SDDS_STRCHARS_H
#define SDDS_STRCHARS_H

namespace sdds {
	char toLower(char ch);
	int strCmp(const char* s1, const char* s2);
	int strnCmp(const char* s1, const char* s2, int len);
	void strCpy(char* des, const char* src);
	int strLen(const char* str);
	const char* strStr(const char* str, const char* find);
	int isAlpha(char ch);
	int isSpace(char ch);
	void trim(char word[]);
	void toLowerCaseAndCopy(char des[], const char source[]);
}


#endif // !SDDS_STRCHARS_H