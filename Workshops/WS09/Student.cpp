/***********************************************************************
// OOP244 Workshop # 9: Graduate Module
//
// File: Student.cpp
// Date: 11/22/2023
// Author: Alicia Atienza
// Description: This program demonstrates the concept of Polymorphism
// using an example of Student and Graduate.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;
using namespace sdds;
namespace sdds {
    Student::Student()
    {
        // Safe state
        m_name = nullptr; 
        m_age = 0;
    }

    Student::Student(const char* name, int age)
    {
        // Constructor
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
        m_age = age;
    }

    Student::~Student()
    {
        delete[] m_name;
    }

    Student::Student(const Student& other)
    {
        // Copy constructor
        m_name = new char[strlen(other.m_name) + 1]; 
        strcpy(m_name, other.m_name);
        m_age = other.m_age;
    }

    Student& Student::operator=(const Student& other)
    {
    
        // Assignment constructor
        if (this != &other)
        {
            delete[] m_name; 
            m_name = new char[strlen(other.m_name) + 1];
            strcpy(m_name, other.m_name);
            m_age = other.m_age;
        }
        return *this;
    }

    void Student::display()
    {
        cout << "Name: " << m_name << endl;
        cout << "Age: " << m_age << endl;
    }

}