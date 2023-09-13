//Name: Alicia Atienza 
//Email: aatienza1@myseneca.ca
//ID: 68789041
//Date: 9/13/2023

#include <iostream>
#include "Word.h"
using namespace sdds;
using namespace std;
int main() {
	char filename[256];
	programTitle();
	cout << "Enter filename: ";
	cin >> filename;
	wordStats(filename);
	return 0;
}