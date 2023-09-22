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
// Name: Alicia Atienza            Date            Reason
***********************************************************************/
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
    bool read(char*& name) {
        // Local array of 128 characters to read for fscanf
        char localArray[128];

        // Calculator for length of array later
        int length{};

        // Result variable
        bool ok = false;

        // fscanf read of name of employee with return of 1 from localArray
        if (fscanf(fptr, "%127[^\n]\n", localArray) == 1) {

            // Set the reference parameter of the function to a dynamic memory 
            // equal to the length of the scanned name

            // Calculating length of scanned name 
            length = strlen(localArray);

            // Setting the reference parameter of the function to the length + 1
            name = new char[length + 1];

            // Copy the name into the new reference parameter 
            strcpy(name, localArray);

            ok = true;

        }
        delete[] name;

        return ok;
    }

    // Accepts as a parameter, a reference to an integer representing the employee number
    bool read(int& employeeNumber) {
        // Variable to store parameter in
        int employeeParam{};
        bool ok = false;

        // Reads from the file the employee number to see if it returns true (1)
        if (fscanf(fptr, "%d,", employeeParam) == 1) {

            // Stores it in the parameter
            employeeNumber = employeeParam;

            // Return true if read was successful
            ok = true;

        }
        return ok;
    }

    //  Accepts as a parameter, a reference to a double precision number representing the employee's salary
    bool read(double& employeeSalary) {

        // Variable to store parameter in
        double salaryParam{};
        bool ok = false;

        // Reads from the file the employee salary to see if it returns true (1)
        if (fscanf(fptr, "%lf,", salaryParam) == 1){

            // Stores it in the parameter
            employeeSalary = salaryParam;

            ok = true;
        }

        return ok;
   }
   
}