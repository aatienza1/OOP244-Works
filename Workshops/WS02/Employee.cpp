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
// Name: Alicia Atienza            Date            Reason
***********************************************************************/
#include <iostream>
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
    bool load(Employee& employees) {

        // Initializing boolean
        bool ok{};

        // Initializing variables to be used for read
        char* employeeName{};
        int employeeNumber{};
        double employeeSalary{};

        // Loads from the file the information about the employee
        openFile(DATAFILE);

        // Returns true if the three overloaded functions return as true
        if (read(employeeNumber, DATAFILE) &&
            read(employeeSalary, DATAFILE) &&
            read(employeeName, DATAFILE)) {
            bool ok = true;
        }
        // Function returns false if any of the reads fail
        else {
            bool ok = false;
        }

        // Calls the three overloaded read functions and sets the three attributes of the Employee
        if (ok) {
            employees.m_name = employeeName;
            employees.m_empNo = employeeNumber;
            employees.m_salary = employeeSalary;
        }

        // Closing file becausE AND IF THERE'S A MEMORY LEAK ISSUE I BET YOU IT'S GONNA BE HERE

        closeFile();

        // Returns the combined result of the three read functions
        return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
    // Load: an overload of the load function with no parameters
   bool load() {
       int i{};
       // Open the file (use function(s) from the File module)
       openFile(DATAFILE);
       // If not successful print the following error message and 
       // exit the function returning false;
       if (!openFile(DATAFILE)) {

           cout << "Could not open data file: data_file_name" << endl;
           return false;
       }

       // Get the number of records (employees) from the file (use the function(s) from the File module) 
       // and store it in the global variable.
       noOfEmployees = noOfRecords();


       // Create a dynamically allocated array of Employee to the number of the records 
       // in the file and hold its address in the corresponding global variable.
       // NOTE TO SELF: we use Employee because it is it's own object, similar to how one
       // would say "new int" or "new char" when allocating memory
       employees = new Employee[noOfEmployees];

       for (i = 0; i < noOfEmployees; i++) {
           if (load(employees)) {


           }
       }

   }

   // TODO: Implementation for the display functions go here
   void display() {
       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;
   }


   // TODO: Implementation for the deallocateMemory function goes here



}