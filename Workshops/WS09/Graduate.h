/***********************************************************************
// OOP244 Workshop # 9: Graduate Module
//
// File: Graduate.h
// Date: 11/22/2023
// Author: Alicia Atienza
// Description: This program demonstrates the concept of Polymorphism
// using an example of Student and Graduate.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_GRADUATE_H
#define SDDS_GRADUATE_H
#include "Student.h"

namespace sdds {
	class Graduate: public Student {
	private:
		char* m_supervisor{};
		char* m_thesisTitle{};
	public:
		Graduate();
		Graduate(const char* name, int age,const char* thesis, const char* supervisor);
		~Graduate();
		Graduate(const Graduate& other);
		Graduate& operator=(const Graduate& other);
		void display();
	};
}
#endif