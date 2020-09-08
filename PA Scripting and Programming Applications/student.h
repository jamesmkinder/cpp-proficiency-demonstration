//Student.h header file. Declares Student object.

#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "degree.h"
using std::string;

class Student {
private:
//Data fields as specified by PA rubric.
	string studentId;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysToComplete[3];
	DegreeProgram degreeProgram;

public:
	//Constructor and destructor functions.
	Student();
	Student(string initStudentId, string initFirstName, string initLastName, string initEmail, int initAge, int initDaysToComplete[3], DegreeProgram initDegreeProgram);
	//Accessor functions.
	string GetStudentId() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmail() const;
	int GetAge() const;
	int GetDaysToComplete(int classNum) const;
	DegreeProgram GetDegreeProgram() const;
	//Mutator functions.
	void SetStudentId(string studentId);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmail(string email);
	void SetAge(int age);
	void SetDaysToComplete(int whichClass, int daysToComplete);
	void SetDegreeProgram(DegreeProgram degreeProgram);
	//Print function.
	void PrintStudentData() const;
};
#endif