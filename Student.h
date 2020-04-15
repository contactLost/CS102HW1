//CS201 HW1 
//Author Tuna Dalbeler
#pragma once
#include <string>


using namespace std;

class Student
{
public:
	Student(const int studentIDin = 0 , const string studentNamein = "", const string studentSurnamein = "");
	~Student();

	void setID(int id);
	void setName(string name);
	void setSurname(string surname);

	int getID();
	string getName();
	string getSurname();

	void enrollCourse(int courseID);

	int studentID;
	string studentName;
	string studentSurname;

	int getCourseCount();
	bool hasCourse(int courseID); 

	void withdrawCourse(int courseID);

	void printCourseOfTheStudent();
	int * returnCourseList();
	int returnCourseListSize();
private:
	int courseCount;
	int* courseIDList;
};

