#include <iostream>
#include <sstream>
#include "roster.h"
using namespace std;
const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,James,Kinder,jkind21@wgu.edu,27,1,10,5,SOFTWARE" };

int main(){
	//1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
	cout << "Scripting and Programming - Applications - C867\nC++\nStudent ID: #001481730\nJames Kinder\n\n";
	//2.  Create an instance of the Roster class called classRoster.
	Roster classRoster;
	//3.  Add each student to classRoster.
	int i = 0, j = 0;  //Initialized variables for loops.
	string studentDataArray[5][9];  //Initialized two-dimensional array of size 5X9 to receive the CSV list of student data.
	for (i = 0; i < 5; i++) {  //For loop to add data to istringstream variable.
		istringstream StudentDataSS(studentData[i]);  //istringstream variable receives the student data array given.
		for (j = 0; j < 9; j++) {  //Embedded loop to iterate through studentDataArray matrix.
			getline(StudentDataSS, studentDataArray[i][j], ',');  //Used getline to move the istringstream data into the studentDataArray matrix using the comma as a delimeter. As the loop iterates through studentDataArray[i][j], the array will be populated in the form of studentDataArray[student][data part].
		}
	}
	for (i = 0; i < 5; i++) {  //For loop to call the add function for the five students in the classRoster.
		DegreeProgram tempDegreeProgram = DegreeProgram::EMPTY;  //tempDegreeProgram variable created to handle the conversion of data type string to DegreeProgram.
		if (studentDataArray[i][8] == "SOFTWARE") {  //if/else statement to populate the tempDegreeProgram variable
			tempDegreeProgram = DegreeProgram::SOFTWARE;
		}
		else if (studentDataArray[i][8] == "NETWORK") {
			tempDegreeProgram = DegreeProgram::NETWORK;
		}
		else if (studentDataArray[i][8] == "SECURITY") {
			tempDegreeProgram = DegreeProgram::SECURITY;
		}
		else {}
		//add function below iterates through studentDataArray matrix and populates each argument with the corresponding data type.  Stoi is used to easily convert string data into integers, and the enumerated DegreeProgram variable was handled above.
		classRoster.add(studentDataArray[i][0], studentDataArray[i][1], studentDataArray[i][2], studentDataArray[i][3], stoi(studentDataArray[i][4]), stoi(studentDataArray[i][5]), stoi(studentDataArray[i][6]), stoi(studentDataArray[i][7]), tempDegreeProgram);
	}


/*
	Convert the following pseudo code to complete the rest of the  main() function:
	classRoster.printAll();
	classRoster.printInvalidEmails();
*/
	classRoster.printAll();
	classRoster.printInvalidEmails();
/*
	loop through classRosterArray and for each element:
	classRoster.printAverageDaysInCourse(current_object's student id);
*/
	for (i = 0; i < 5; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentId());
	}
/*
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");

*/
	
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
	
//expected: the above line should print a message saying such a student with this ID was not found.

//5.  Implement the destructor to release the memory that was allocated dynamically in Roster.
	classRoster.~Roster();
	
}
