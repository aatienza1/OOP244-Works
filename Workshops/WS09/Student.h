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
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

namespace sdds {
	class Student {
	private:
		char* m_name{};
		int m_age{};
	public:
		Student();
		Student(const char* name, int age);
		virtual ~Student();
		Student(const Student& other);
		Student& operator=(const Student& other);
		virtual void display();
	};
}
#endif