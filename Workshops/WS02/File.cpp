/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name: Alicia Atienza            Date:9/22/2023              Reason
***********************************************************************/
// Student No: 38780274 (Apologies for previous lab, I put my old university student number)
// Email: aatienza1@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
    //TODO: read functions go here    
    bool read(char*& name, const char filename[]) {
        // Local array of 128 characters to read for fscanf
        char localArray[128];

        // Calculator for length of array later
        int length{};

        // Result variable
        bool ok = false;

        // fscanf read of name of employee with return of 1 from localArray
        if (fscanf(fptr, "%127[^\n]\n", localArray) == 1) {

            // Calculating length of scanned name 
            length = strlen(localArray);

            // Setting the reference parameter of the function to the length + 1
            name = new char[length + 1];

            // Copy the name into the new reference parameter 
            strcpy(name, localArray);

            ok = true;

        }
        return ok;
    }

    // Accepts as a parameter, a reference to an integer representing the employee number
    bool read(int& employeeNumber, const char filename[]) {
        // Variable to store parameter in
        int employeeParam{};
        bool ok = false;

        // Reads from the file the employee number to see if it returns true (1)
        if (fscanf(fptr, "%d,", &employeeParam) == 1) {

            // Stores it in the parameter
            employeeNumber = employeeParam;

            // Return true if read was successful
            ok = true;

        }
        return ok;
    }

    //  Accepts as a parameter, a reference to a double precision number representing the employee's salary
    bool read(double& employeeSalary, const char filename[]) {

        // Variable to store parameter in
        double salaryParam{};
        bool ok = false;

        // Reads from the file the employee salary to see if it returns true (1)
        if (fscanf(fptr, "%lf,", &salaryParam) == 1){

            // Stores it in the parameter
            employeeSalary = salaryParam;

            ok = true;
        }

        return ok;
   }
   
}