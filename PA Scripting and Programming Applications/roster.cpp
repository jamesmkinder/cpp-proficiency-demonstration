//Roster.cpp file.  Defines public functions for Roster object.
#pragma once
#include <iostream>
#include <string>
#include <array>
#include <sstream>
#include <cstring>
#include "roster.h"
using namespace std;

int lastElement = (sizeof(Roster::classRosterArray) / sizeof(Roster::classRosterArray[0])) - 1;
//Constructor and destructor functions.
Roster::Roster() {
	int i = 0;
	for (i = 0; i < 5; i++) {
		classRosterArray[i] = new Student();
	}
}

Roster::~Roster() {
	
}
//Add function as specified by the PA rubric.
void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int i = 0;
	for (i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetStudentId() == "Null") {
			classRosterArray[i]->SetStudentId(studentId);
			classRosterArray[i]->SetFirstName(firstName);
			classRosterArray[i]->SetLastName(lastName);
			classRosterArray[i]->SetEmail(emailAddress);
			classRosterArray[i]->SetAge(age);
			classRosterArray[i]->SetDaysToComplete(1, daysInCourse1);
			classRosterArray[i]->SetDaysToComplete(2, daysInCourse2);
			classRosterArray[i]->SetDaysToComplete(3, daysInCourse3);
			classRosterArray[i]->SetDegreeProgram(degreeProgram);
			break;
		}
	}
	

}
//Remove function as specified by the PA rubric.
void Roster::remove(string studentId) {
	int i = 0;	
	bool studentDeleted = false;
	for (i = 0; i < 5; i++) {
		if (studentId == classRosterArray[i]->GetStudentId()) {
			studentDeleted = true;
			classRosterArray[i] = classRosterArray[lastElement];
			lastElement -= 1;
		}
	}
	
	if (studentDeleted == false) {
		cout << "Error: student was not found.\n";
	}
}

//printAll function as specified by the PA rubric. Takes the pointer to each Student object in classRosterArray and calls the PrintStudentData function.
void Roster::printAll() {
	int i = 0;
	for (i = 0; i < lastElement + 1; i++) {
			classRosterArray[i]->PrintStudentData();
		}
}
//printAverageDaysInCourse function as specified by the PA rubric.
void Roster::printAverageDaysInCourse(string studentId) {
	int i = 0;
	for (i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetStudentId() == studentId) {
			int average = 0;
			average = (classRosterArray[i]->GetDaysToComplete(1) + classRosterArray[i]->GetDaysToComplete(2) + classRosterArray[i]->GetDaysToComplete(3)) / 3;
			cout << classRosterArray[i]->GetFirstName() << " " << classRosterArray[i]->GetLastName() << "'s Average Days in Course: " << average << endl << endl;
		}
	}
}
//printInvalidEmails function as specified by the PA rubric.
void Roster::printInvalidEmails() {
	cout << "Invalid Emails: ";
	int i = 0;
	for (i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetEmail().find(' ') != string::npos || classRosterArray[i]->GetEmail().find('.') == string::npos || classRosterArray[i]->GetEmail().find('@') == string::npos) {  //"If the GetEmail function from the student object pointed to by the classRosterArray contains a space OR does not contain a dot OR does not contain an @ symbol..."
			cout << i + 1 << ". " << classRosterArray[i]->GetEmail() << "\t";
		}
	}
	cout << endl << endl;
}
//printByDegreeProgram function as specified by the PA rubric. Calls the GetDegreeProgram function on each classRosterArray-pointed student object and then calls the PrintStudentData function if GetDegreeProgram matches the value passed to the function.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

	cout << "Students from the ";
	if (degreeProgram == DegreeProgram::SOFTWARE) {
		cout << "Software degree program:" << endl << endl;
	}
	else if (degreeProgram == DegreeProgram::NETWORK) {
		cout << "Network degree program:" << endl << endl;
	}
	else if (degreeProgram == DegreeProgram::SECURITY) {
		cout << "Security degree program:" << endl << endl;
	}
	else{}
	int i = 0;
	for (i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			classRosterArray[i]->PrintStudentData();
		}
	}
	cout << endl << endl;
}
