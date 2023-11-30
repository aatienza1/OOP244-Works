/***********************************************************************
// Final project Milestone 3
// Module: Utils
// File: Utils.h
// Version 1.1
// Author  Alicia Atienza
// Description
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
// Revision History
// Added getdouble
// -----------------------------------------------------------
// Name :Alicia Atienza                Date : 11/24/2023           Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstring>
#include <iomanip>
#include "Utils.h"
using namespace std;
namespace sdds {
    Utils ut;
    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    void Utils::alocpy(char*& destination, const char* source)
    {
        delete[] destination;
        destination = nullptr;
        if (source != NULL) {
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
    }
    int Utils::getint(const char* prompt) {
        // Checking that prompt is not null for display
        if (prompt != nullptr) {
            cout << prompt;
        }

        int value{};

        cin >> value;
        while (cin.fail()) {
            cout << "Invalid Integer, retry: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> value;
        }
        return value;
    }

    int Utils::getint(int min, int max, const char* prompt, const char* errMes) {
        int value{};
        if (prompt != nullptr) {
            cout << prompt;
        }

        // Added bool to exit out of the program
        bool validInput = false;
        while (!validInput) {
            value = getint();

            if (value >= min && value <= max) {
                validInput = true;
            }
            else {
                if (errMes != nullptr) {
                    cout << errMes;
                }
                else {
                    cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
                }
            }
        }

        return value;
    }
    double Utils::getdouble(const char* prompt)
    {
        if (prompt != nullptr) {
            cout << prompt;
        }

        double value{};

        cin >> value;
        while (cin.fail()) {
            cout << "Invalid number, retry: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> value;
        }
        return value;
    }
    double Utils::getdouble(double min, double max, const char* prompt, const char* errMes)
    {
        double value{};
        if (prompt != nullptr) {
            cout << prompt;
        }

        // Added bool to exit out of the program
        bool validInput = false;
        while (!validInput) {
            value = getdouble();

            if (value >= min && value <= max) {
                validInput = true;
            }
            else {
                if (errMes != nullptr) {
                    cout << errMes;
                }
                else {
                    // This is to allow for digits to show up
                    cout << "Value out of range [" << fixed << setprecision(2) << min << "<=val<=" << max << "]: ";
                }
            }
        }

        return value;
    }
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

}