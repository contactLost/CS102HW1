//CS201 HW1 
//Author Tuna Dalbeler
#include "Student.h"
#include <string>
#include "RegistrationSystem.h"
#include "Course.h"

using namespace std;


Student::Student(const int studentIDin , const string studentNamein , const string studentSurnamein )
{
	studentID = studentIDin ;
	studentName = studentNamein;
	studentSurname = studentSurnamein;

	courseCount = 0;
	//courseIDList = new int[courseCount];
}

Student::~Student()
{
	//delete[] courseIDList;
}

void Student::setID(int id)
{
	studentID = id;
}
void Student::setName(string name)
{
	studentName = name;
}
void Student::setSurname(string surname)
{
	studentSurname = surname;
}

int Student::getID() 
{
	return studentID;
}
string Student::getName()
{
	return studentName;
}
string Student::getSurname()
{
	return studentSurname;
}

void Student::enrollCourse(int id)
{

	int* tempCourseList = new int[courseCount + 1];

	if (courseCount != 0) {
		
		for (int i = 0; i < courseCount; i++) {
			tempCourseList[i] = courseIDList[i];
		}

	}

	tempCourseList[courseCount] = id;
	

	if (courseCount != 0) {
		delete[] courseIDList;
	}

	courseIDList = tempCourseList;

	courseCount = courseCount + 1;

	cout << "Course " << courseIDList[courseCount - 1] << " has been added to student " << studentID << endl;
}

int Student::getCourseCount()
{
	return courseCount;
}

bool Student::hasCourse(int courseID)
{
	for (int i = 0; i < courseCount; i++) {
		if (courseIDList[i] == courseID)
			return true;
	}


	return false;
}

void Student::withdrawCourse(int courseID)
{

	int tempCourseIDIndex = -1;



	for (int i = 0; i < courseCount; i++) {

		if (courseIDList[i] == courseID) {
			tempCourseIDIndex = i;
			break;
		}
	}

	if (tempCourseIDIndex != -1) {

		int* tempNewCourseIdList = new int[courseCount - 1];

		for (int i = 0; i < tempCourseIDIndex; i++) {

		tempNewCourseIdList[i] = courseIDList[i];

		}

		for (int i = tempCourseIDIndex; i < courseCount - 1; i++) {

		tempNewCourseIdList[i] = courseIDList[i + 1];

		}

		delete[] courseIDList;
		courseIDList = tempNewCourseIdList; // potential memory leak delete tempNewCourseIdList ?

		courseCount = courseCount - 1;
	}


}

void Student::printCourseOfTheStudent() // for debug purposes
{

	for (int i = 0; i < courseCount; i++) {
		cout << courseIDList[i] << endl;
	}

}

int* Student::returnCourseList() {
	return courseIDList;
}

int Student::returnCourseListSize() {
	return courseCount;
}
//void Student::registerToCourse( const int courseId ) 
//{
//
//	//create temp arr
//	int* tempCourseIdArray = new int[courseCount + 1];
//
//	//copy old arr to new one
//
//	for (int i = 0; i < courseCount; i++) {
//		courseIDList[i] = tempCourseIdArray[i];
//	}
//	// delete old arr
//	delete[] courseIDList;
//
//	// replace old arr
//	courseIDList = tempCourseIdArray;
//	// course count + 1
//
//	courseCount++;
//}
//
//void Student::printCourseIDListOfStudent(){
//
//	cout << "Print course ID list. Course ID List size: " << courseCount << endl;
//
//	for (int i = 0; i < courseCount; i++) {
//
//		cout << courseIDList[i] << endl;
//	}
//
//}