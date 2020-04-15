//CS201 HW1 
//Author Tuna Dalbeler

#pragma once

#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"
#include <stdio.h>

using namespace std;

class RegistrationSystem
{
public:
	RegistrationSystem();
	~RegistrationSystem();

	void addStudent(const int studentId, const string firstName, const string lastName);
	void deleteStudent(const int studentId);

	void addCourse(const int studentId, const int courseId, const string courseName);
	void withdrawCourse(const int studentId, const int courseId);
	void cancelCourse(const int courseId);
	void showStudent(const int studentId);
	void showCourse(const int courseId);
	void showAllStudents();

	

private:
	int studentSize;
	Student* studentArray;
	int* sizePtr;

	int courseSize;
	Course* courseArray;
	int* courseSizePtr;

	int findStudentByID(const int id);

	int findCourseByID(const int id);

};
