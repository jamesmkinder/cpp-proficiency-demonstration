//Roster.h header file.  Declares Roster object.

#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include <string>
#include "student.h"


class Roster {
public:
	//Array of pointers to student objects.
	Student *classRosterArray[5];
	Roster();
	~Roster();
	//Public functions specified by the PA rubric.
	void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
};

#endif