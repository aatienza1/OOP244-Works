/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  Employee.cpp
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

#include <iostream>
#include <iomanip>
#include "Employee.h"
#include "File.h"
using namespace std;

namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument

    // Receives as a parameter, a reference to an object of type Employee
    bool load(Employee& emp) {

        // Initializing boolean
        bool ok{};

        // Initializing variables to be used for read
        char* employeeName{};
        int employeeNumber{};
        double employeeSalary{};

        // Loads from the file the information about the employee
        openFile(DATAFILE);

        // Returns true if the three overloaded functions return as true
        // Calls the three overloaded read functions and sets the three attributes of the Employee

        if (read(employeeNumber, DATAFILE) &&
            read(employeeSalary, DATAFILE) &&
            read(employeeName, DATAFILE)) {

            emp.m_name = employeeName;
            emp.m_empNo = employeeNumber;
            emp.m_salary = employeeSalary;
            ok = true;
        }

        // Closing file becausE AND IF THERE'S A MEMORY LEAK ISSUE I BET YOU IT'S GONNA BE HERE

        delete[] employeeName;

        // Returns the combined result of the three read functions
        return ok;
    }
    // TODO: Finish the implementation of the 0 arg load function 
     // Load: an overload of the load function with no parameters
    bool load() {
        int i = 0; // Initialize the loop counter
        bool ok = true; // Initialize ok to true

        // If not successful print the following error message and 
        // exit the function returning false;
        if (!openFile(DATAFILE)) {
            cout << "Could not open data file: " << DATAFILE << endl;
            return false;
        }

        // Get the number of records (employees) from the file
        noOfEmployees = noOfRecords();

        // Create a dynamically allocated array of Employee
        employees = new Employee[noOfEmployees];

        // Load each record from the file and store it in the array elements.
        for (i = 0; i < noOfEmployees; i++) {
            // Read functions (inputted datafile as second argument, was not working before)
            if (read(employees[i].m_empNo, DATAFILE) &&
                read(employees[i].m_salary, DATAFILE) &&
                read(employees[i].m_name, DATAFILE)) {
            }
            else {

                //Ending program if error!!!
                ok = false;
                return ok;
            }
        }

        // Displaying error message
        if (!ok) {
            cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;

            // Deallocating memory (NOTE TO SELF USE DELETE[] IF THIS DOES NOT WORK)
            deallocateMemory(); 

            closeFile(); 
            return false;
        }

        // Clean up and close the file
        closeFile();
        return true;
    }

    // TODO: Implementation for the display functions go here
    void display(const Employee& emp) {
        int i{};
        cout << employees[i].m_empNo << ": " << employees[i].m_name
            << "$" << employees[i].m_salary << endl;
    }

    void display() {
        int i{};
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;

        sort();

        // NOTE TO SELF: setprecision removes the 0 without casting double to int for the salary
        // use <iomanip> to do this
        // YOU MUST ADD FIXED because if you don't it gives you some code
        for (i = 0; i < noOfEmployees; i++) {
            cout << i + 1 << "- " << employees[i].m_empNo << ": " << employees[i].m_name
            << "," << " $" << fixed << setprecision(0) << employees[i].m_salary << endl;
        }


    }

    // TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory() {
        int i{};

        // Deallocate all the memory used by the the dynamic array of employees
        for (i = 0; i < noOfEmployees; i++) {
            delete[] employees[i].m_name;
        }
    }


}
