//CS201 HW1 
//Author Tuna Dalbeler
#pragma once

#include <string>
#include "Student.h"
#include <string>

using namespace std;

class Course
{
public:
	Course(void);
	~Course(void);

	void setCourseID(int id);
	void setCourseName(string name);

	int getCourseID();
	string getCourseName();

private:
	int courseID;
	string courseName;

};


