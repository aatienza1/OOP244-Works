/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name: Alicia Atienza            Date:9/22/2023              Reason
***********************************************************************/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare overloaded read function prototypes
   bool read(char*& name, const char filename[]);
   bool read(int& employeeNumber, const char filename[]);
   bool read(double& employeeSalary, const char filename[]);

}

#endif // !SDDS_FILE_H_