//CS201 HW1 
//Author Tuna Dalbeler
#include "Course.h"

#include "Student.h"
#include "RegistrationSystem.h"

using namespace std;

Course::Course()
{
	courseID = 0;
	courseName = " ";

}

Course::~Course()
{
	
}


void Course::setCourseID(int id) 
{
	courseID = id;
}
void Course::setCourseName(string name)
{
	courseName = name;
}
int Course::getCourseID()
{
	return courseID;
}
string Course::getCourseName()
{
	return courseName;
}

//void Course::enrollStudent(const int id) 
//{
//	//Create temporary array with size+1
//	int tempSize = enrolledStudentIDListSize + 1;
//	int* tempArr = new int[tempSize];
//
//	// copying old array elements to new array 
//	for (int i = 0; i < tempSize - 1 ; i++) {
//		tempArr[i] = enrolledStudentIDList[i];
//		cout << "tempArr : " << tempArr[i] << endl;
//		cout << "esýdl : " << enrolledStudentIDList[i] << endl;
//	}
//
//	// insert new student to list
//	tempArr[tempSize - 1] = id;
//	enrolledStudentIDListSize++;
//	cout << "enrollStudent student size : " << enrolledStudentIDListSize << endl;
//
//	delete[] enrolledStudentIDList;
//	enrolledStudentIDList = tempArr;
//}
//
//void Course::printEnrolledStudents()
//{
//
//	cout << "Print enrolledStudentIDListSize. Course  student ID List size: " << enrolledStudentIDListSize << endl;
//
//	for (int i = 0; i < enrolledStudentIDListSize; i++) {
//
//		cout << enrolledStudentIDList[i] << endl;
//		cout << "***" << endl;
//	}
//
//}
