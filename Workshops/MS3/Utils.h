/***********************************************************************
// Final project Milestone 3
// Module: Utils
// File: Utils.h
// Version 1.1
// Description
//
// Revision History
// Added getdouble
// -----------------------------------------------------------
// Name: Alicia Atienza                 Date: 11/24/2023            Reason
***********************************************************************/
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds {
    const int sdds_testYear = 2023;
    const int sdds_testMon = 12;
    const int sdds_testDay = 9;
    class Utils {
        bool m_testMode = false;
    public:
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        int daysOfMon(int mon, int year)const;
        void testMode(bool testmode = true);
        // Safely allocates memory
        void alocpy(char*& destination, const char* source);

        // Display int if prompt not null
        int getint(const char* prompt = nullptr);
        int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);

        // Getting doubles
        double getdouble(const char* prompt = nullptr);
        double getdouble(double min, double max, const char* prompt = nullptr, const char* errMes = nullptr);
    };
    extern Utils ut;
}

#endif // !SDDS_UTILS_H
