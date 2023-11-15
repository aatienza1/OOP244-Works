/* Citation and Sources...
Final Project Milestone 1
Module: Status
Filename: Status.cpp
Version 1.0
Author	Alicia Atienza
Revision History
-----------------------------------------------------------
Date      Reason
2023/4/2023  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H

#include <iostream>

using namespace std;
namespace sdds {
    class Status {
        char* m_description{};
        int m_code{};
    public:
        Status(const char* description = nullptr, int code = 0);
        ~Status();
        Status(const Status& original);
        Status& clear();
        Status& operator=(int code);
        Status& operator=(const char* description);

        operator int() const;
        operator const char* ()const;
        operator bool()const;
        ostream& print(ostream& ostr)const;

    };

    ostream& operator<<(ostream& ostr, const Status& stat);

}

#endif // !SDDS_STATUS_H
