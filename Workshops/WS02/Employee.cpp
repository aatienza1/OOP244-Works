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

        if (read(employeeNumber) &&
            read(employeeSalary) &&
            read(employeeName)) {

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
       int i{};

       char* employeeName{};
       int employeeNumber{};
       double employeeSalary{};

       bool ok = false;

       // If not successful print the following error message and 
       // exit the function returning false;
       if (!openFile(DATAFILE)) {

           cout << "Could not open data file: data_file_name" << endl;
           return false;
       }
       else {
           ok = true;
       }

       // Get the number of records (employees) from the file (use the function(s) from the File module) 
       // and store it in the global variable.
       noOfEmployees = noOfRecords();


       // Create a dynamically allocated array of Employee to the number of the records 
       // in the file and hold its address in the corresponding global variable.
       // NOTE TO SELF: we use Employee because it is it's own object, similar to how one
       // would say "new int" or "new char" when allocating memory
       employees = new Employee[noOfEmployees];

       // Load each record from the file and store it in the array elements.
       if (ok) {
           for (i = 0; i < noOfEmployees; i++) {
               employees[i].m_name = employeeName;
               employees[i].m_empNo = employeeNumber;
               employees[i].m_salary = employeeSalary;

           }
       }
       // If something goes wrong during data loading, display error message
       // Deallocate all the memory and return false
       else {
           cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
           delete[] employees;
           return false;
       }

       // DOUBLE CHECK HERE!!!!!!!!!!! I BET YOU THERE WILL BE A MEMORY LEAK ISSUE AND IT'S HERE <:^)
       closeFile();

       return ok;

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
       
       // Iterate over the sorted array an print each employee in this format:

       for (i = 0; i < noOfEmployees; i++) {
           cout << "IDX-" << i << " " << employees[i].m_empNo 
               << ": " << employees[i].m_name
               << ", $" << employees[i].m_salary << endl;
       }
   }

   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory() {
       int i{};

       // Deallocate all the memory used by the the dynamic array of employees
       for (i = 0; i < noOfEmployees; i++) {
           delete[] employees;
       }
   }


}