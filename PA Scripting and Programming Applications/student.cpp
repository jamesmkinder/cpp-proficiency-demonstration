//Student.cpp file.  Defines public functions for object Student.

#pragma once
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

//Constructor and destructors.
Student::Student() {
	studentId = "Null";
	firstName = "Null";
	lastName = "Null";
	email = "Null";
	age = 0;
	daysToComplete[0] = -1;
	daysToComplete[1] = -1;
	daysToComplete[2] = -1;
	degreeProgram = DegreeProgram::EMPTY;
}
Student::Student(string initStudentId, string initFirstName, string initLastName, string initEmail, int initAge, int initDaysToComplete[3], DegreeProgram initDegreeProgram) {
	studentId = initStudentId;
	firstName = initFirstName;
	lastName = initLastName;
	email = initEmail;
	age = initAge;
	daysToComplete[0] = initDaysToComplete[0];
	daysToComplete[1] = initDaysToComplete[1];
	daysToComplete[2] = initDaysToComplete[2];
	degreeProgram = initDegreeProgram;
}
//Get functions.
string Student::GetStudentId() const {
	return studentId;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmail() const {
	return email;
}

int Student::GetAge() const {
	return age;
}

int Student::GetDaysToComplete(int classNum) const {
	return daysToComplete[classNum - 1];
}

DegreeProgram Student::GetDegreeProgram() const {
	return degreeProgram;
}

//Set functions.
void Student::SetStudentId(string studentId) {
	this->studentId = studentId;
}

void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}

void Student::SetEmail(string email) {
	this->email = email;
}

void Student::SetAge(int age) {
	this->age = age;
}

void Student::SetDaysToComplete(int whichClass, int daysToComplete) {
	this->daysToComplete[whichClass - 1] = daysToComplete;
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

//Print function.
void Student::PrintStudentData() const {

	cout << studentId << "\tFirst Name: " << firstName << "\tLast Name: " << lastName << "\tAge: " << age << "\t\tdaysInCourse: {" <<
		daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "} \t";

	if (degreeProgram == DegreeProgram::SOFTWARE) {
		cout << "Degree Program: " << "Software." << endl << endl;
	}
	else if (degreeProgram == DegreeProgram::NETWORK) {
		cout << "Degree Program: " << "Network." << endl << endl;
	}
	else if (degreeProgram == DegreeProgram::SECURITY) {
		cout << "Degree Program: " << "Security." << endl << endl;
	}
	else {
		cout << "Degree Program: " << "Empty" << endl << endl;
	}
}