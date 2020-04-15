//CS201 HW1 
//Author Tuna Dalbeler

#include "RegistrationSystem.h"


using namespace std;


RegistrationSystem::RegistrationSystem()
{
	//Initilize the first student array

	studentSize = 0;
	sizePtr = &studentSize;
	studentArray = new Student[*sizePtr];
	

	//initilize the course array

	courseSize = 0;
	courseSizePtr = &courseSize;
	courseArray = new Course[courseSize];

}

RegistrationSystem::~RegistrationSystem()
{
	delete[] courseArray;
	delete[] studentArray;
}

void RegistrationSystem::addStudent(int id, string name, string surname)
{
	
	if ( name.length() != 0) {
		if (surname.length() !=  0) {

			if (studentSize == 0) { //If this is the first student

				Student* tempStudentArr = new Student[1];
				tempStudentArr[0].setID(id);
				tempStudentArr[0].setName(name);
				tempStudentArr[0].setSurname(surname);
				(*sizePtr)++;

				cout << "Student " << id << " has been added" << endl;

				delete[] studentArray;
				studentArray = tempStudentArr;

			}
			else
			{
				// Check if there is a student with same ID

				bool idFlag = false;
				for (int i = 0; i < studentSize; i++)
				{
					if (((&studentArray[i])->studentID) == id)
					{
						idFlag = true;
						break;
					}
				}

				//If there is student with given id
				if (idFlag) {

					cout << "Student " << id << " already exists" << endl;
				}


				//If there is no student with given id
				else
				{
					//Create temporary array with size+1
					int tempSize = *sizePtr + 1;
					Student* tempArr = new Student[tempSize];

					//find index

					int index = studentSize;

					for (int i = 0; i < studentSize; i++) {

						if (studentArray[i].getID() > id) {
							index = i;
							break;
						}
					}

					// copy until index (excluded)
					for (int i = 0; i < index; i++) {
						tempArr[i] = studentArray[i];
					}

					// insert new student to index
					tempArr[index].setID(id);
					tempArr[index].setName(name);
					tempArr[index].setSurname(surname);
					(*sizePtr)++;

					// copy after index
					for (int i = index; i < tempSize - 1; i++) {
						tempArr[i + 1] = studentArray[i];
					}


					cout << "Student " << id << " has been added" << endl;

					delete[] studentArray;
					studentArray = tempArr;
					
				}
			}
		}
		else {
			cout << "Surname cannot be empty" << endl;
		}
	}
	else {
		cout << "Name cannot be empty" << endl;
	}
}

void RegistrationSystem::deleteStudent(const int studentId)
{
	// find the index
	int index = findStudentByID(studentId);

	// decrease array size by 1

	if (index == -1) { //student not found
		cout << "Student " << studentId << " does not exist" << endl;
	}
	else { //student found at index "index"

		Student* tempStudentArray = new Student[ studentSize - 1 ];

		//copy until index
		for (int i = 0; i < index; i++) {
			tempStudentArray[i] = studentArray[i];
		}
		//copy after index
		for (int i = index + 1; i < studentSize; i++) {
			tempStudentArray[i-1] = studentArray[i];
		}

		(*sizePtr)--;
		delete[] studentArray;
		studentArray = tempStudentArray;

		cout << "Student " << studentId << " has been deleted" << endl;
	}
	
}

void RegistrationSystem::addCourse(const int studentId, const int courseId, const string courseName)
{
	
	
	//Check all students id to conferm student exists
	int tempStudentIndex = findStudentByID(studentId);

	if (tempStudentIndex >= 0) {
		if (courseSize == 0)
		{

			Course* tempCourseArray = new Course[courseSize + 1];
			tempCourseArray[0].setCourseID(courseId);
			tempCourseArray[0].setCourseName(courseName);
			delete[] courseArray;
			courseArray = tempCourseArray;
			(*courseSizePtr)++;

			// TODO add to student's courses list
			(&studentArray[tempStudentIndex])->enrollCourse(courseId);

			Course* tempCrsArrPtr = &courseArray[courseSize - 1];
			//cout << "new course : " << courseSize << endl;
			//cout << "course id  : " << tempCrsArrPtr->getCourseID() << endl;
			//cout << "course name: " << tempCrsArrPtr->getCourseName() << endl;

		}
		else //courseSize > 0
		{

			//Check if id of the course matches with other course ids
			bool courseExistFlag = false;

			for (int i = 0; i < courseSize; i++)
			{
				if (((&courseArray[i])->getCourseID()) == courseId)
				{
					courseExistFlag = true;
					Course* tempCrsArrPtr = &courseArray[i];

					//if student have this course already
					if ((&studentArray[tempStudentIndex])->hasCourse(courseId)) {
						std::cout << "Student " << studentId << " is already enrolled in course " << courseId << endl;
					}
					//else student dont have this course
					else {
						(&studentArray[tempStudentIndex])->enrollCourse(courseId);}
				}
			}


			if (!courseExistFlag) {										//If course with given id does not exist. Create one.

				//Create temporary array with size+1
				int tempSize = courseSize + 1;
				Course* tempArr = new Course[tempSize];

				// copying old array elements to new array 
				for (int i = 0; i < tempSize - 1; i++) {
					tempArr[i] = courseArray[i];
				}

				// insert new student
				tempArr[tempSize - 1].setCourseID(courseId);
				tempArr[tempSize - 1].setCourseName(courseName);
				(*courseSizePtr)++;

				delete[] courseArray;
				courseArray = tempArr;

				(&studentArray[tempStudentIndex])->enrollCourse(courseId);

				Course* tempCrsArrPtr = &courseArray[courseSize - 1];
				//cout << "new course : " << courseSize << endl;
				//cout << "course id  : " << tempCrsArrPtr->getCourseID() << endl;
				//cout << "course name: " << tempCrsArrPtr->getCourseName() << endl;
			}


		}
	}
	else 
	{
		cout << "student does not exist with id: " << studentId << endl;
	}

}

void RegistrationSystem::withdrawCourse(const int studentId, const int courseId)
{
	int tempStudentIdIndex = findStudentByID(studentId);
	int tempCourseIdIndex =  findCourseByID(courseId);

	if (tempStudentIdIndex >= 0) {
		if (tempCourseIdIndex >= 0) {
			studentArray[tempStudentIdIndex].withdrawCourse(courseId);
			cout << "Student " << studentId << " has been withdrawn from course " << courseId << endl;
		}
		else {
			cout << "Student " << studentId << " is not enrolled in course " << courseId << endl;
		}
	}
	else {
		cout << "Student " << studentId << " does not exist " << endl;
	}
}

void RegistrationSystem::cancelCourse(const int courseId)
{
	int tempCourseIDIndex = findCourseByID(courseId);

	if (tempCourseIDIndex != -1) {

		//withdraw the course from all students

		for (int i = 0; i < courseSize; i++) {
			studentArray[i].withdrawCourse(courseId);
		}

		//delete from course array



		Course* tempNewCourseArray = new Course[courseSize - 1];

		for (int i = 0; i < tempCourseIDIndex; i++) {

			tempNewCourseArray[i] = courseArray[i];

		}

		for (int i = tempCourseIDIndex; i < courseSize - 1; i++) {

			tempNewCourseArray[i] = courseArray[i + 1];

		}

		delete[] courseArray;
		courseArray = tempNewCourseArray; // potential memory leak delete tempNewCourseIdList ?

		courseSize = courseSize - 1;

		cout << "Course " << courseId << " has been cancelled" << endl;

	}
	else {
		cout << "Course " << courseId << " does not exist" << endl;
	}
}

void RegistrationSystem::showAllStudents() {

	

	if (studentSize == 0)
	{
		cout << "There are no students in the system" << endl;
	}
	else 
	{
		
		printf("%-15s %-15s %-15s \n", "Student id", "Student Name", "Student Surname");
		
		for (int i = 0; i < studentSize; i++)
		{
			printf("%-15d %-15s %-15s \n", (&studentArray[i])->studentID, ((&studentArray[i])->studentName).c_str() , ((&studentArray[i])->studentSurname).c_str() );
			

			if (studentArray[i].getCourseCount() != 0) {

				int* tempCourseArr = (studentArray[i]).returnCourseList();
				int  tempCourseArrSize = (studentArray[i]).returnCourseListSize();
				int  tempCourseIndex = -1;
				int tempCourseID = 0;
				string tempCourseName = "null";

				printf("%-15s %-15s %-15s \n", "", "Course ID", "Course Name");	//TODO if there is no course do bnot pritnt this

				for (int i = 0; i < tempCourseArrSize ; i++) {

					tempCourseIndex = findCourseByID(tempCourseArr[i]);
					tempCourseID = (courseArray[tempCourseIndex]).getCourseID();
					tempCourseName = (courseArray[tempCourseIndex]).getCourseName();

					printf("%-15s %-15d %-15s \n", "", tempCourseID, tempCourseName.c_str());


					//cout << "Course ID: " << (courseArray[tempCourseIndex]).getCourseID() << endl;
					//cout << "Course Name: " << (courseArray[tempCourseIndex]).getCourseName() << endl;
				}
			}
		}
	}
}

void RegistrationSystem::showStudent(const int studentID)
{
	int tempStudentIndex = findStudentByID(studentID);

	if (tempStudentIndex != -1) {
		//cout << "the Student with number: " << studentID << " has " << endl;

		

		printf("%-15s %-15s %-15s \n" , "Student id", "Student Name", "Student Surname" );
		printf("%-15d %-15s %-15s \n" , studentID, (studentArray[tempStudentIndex]).getName().c_str() , (studentArray[tempStudentIndex]).getSurname().c_str()  );

		if (studentArray[tempStudentIndex].getCourseCount() != 0) {

			int* tempCourseArr = (studentArray[tempStudentIndex]).returnCourseList();
			int  tempCourseArrSize = (studentArray[tempStudentIndex]).returnCourseListSize();
			int  tempCourseIndex = -1;
			int tempCourseID = 0;
			string tempCourseName = "null";

			printf("%-15s %-15s %-15s \n", "", "Course ID", "Course Name");	//TODO if there is no course do bnot pritnt this

			for (int i = 0; i < tempCourseArrSize - 1; i++) {

				tempCourseIndex = findCourseByID(tempCourseArr[i]);
				tempCourseID = (courseArray[tempCourseIndex]).getCourseID();
				tempCourseName = (courseArray[tempCourseIndex]).getCourseName();

				printf("%-15s %-15d %-15s \n", "", tempCourseID, tempCourseName.c_str());


				//cout << "Course ID: " << (courseArray[tempCourseIndex]).getCourseID() << endl;
				//cout << "Course Name: " << (courseArray[tempCourseIndex]).getCourseName() << endl;
			}
		}
	}
	else {
		cout << "Student "<< studentID << " does not exist" << endl;
	}
}

void RegistrationSystem::showCourse(const int courseID)
{
	// id yi kontrol et
	int courseIDindex = findCourseByID(courseID);
	if (courseIDindex != -1) {
		
		printf("%-15s %-15s \n", "Course ID", "Course Name");
		printf("%-15d %-15s \n", courseID , courseArray[courseIDindex].getCourseName().c_str() );
		printf("%-15s %-15s %-15s %-15s \n", "", "Student ID", "Student Name", "Student Last Name");
		for (int i = 0; i < studentSize; i++) 
		{
			if(studentArray[i].hasCourse(courseID)){
				printf("%-15s %-15d %-15s %-15s \n", "" , studentArray[i].getID() , studentArray[i].getName().c_str() , studentArray[i].getSurname().c_str());
			}
		}
	}
	else {
		cout << "Course " << courseID << " does not exist" << endl;
	}
}

int RegistrationSystem::findStudentByID(const int id)
{

	int returnValue = -1;

	for (int i = 0; i < studentSize; i++) 
	{

		if ( (&studentArray[i])->studentID == id ) 
		{
			returnValue = i;
			break;
		}

	}


	return returnValue;
}

int RegistrationSystem::findCourseByID(const int id)
{
	int returnValue = -1;
	for (int i = 0; i < courseSize; i++)
	{
		if ((&courseArray[i])->getCourseID() == id)
		{
			returnValue = i;
			break;
		}
	}
	return returnValue;
}



