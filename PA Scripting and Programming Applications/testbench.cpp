#include <iostream>
#include <string>
using namespace std;
#include "student.h"
#include "degree.h"
//Testbench for the student object
int main() {
	Student student1;
	string userInputString;
	int userInputInt;
	char userInputChar = 'z';
	student1.PrintStudentData();
	while (userInputChar != 'y') {

		cout << "Give me your student ID ";
		cin >> userInputString;
		student1.SetStudentId(userInputString);
		cout << "Your input was: " << student1.GetStudentId() << endl;

		cout << "\nGive me your first name ";
		cin >> userInputString;
		student1.SetFirstName(userInputString);
		cout << "Your input was: " << student1.GetFirstName() << endl;

		cout << "\nGive me your last name ";
		cin >> userInputString;
		student1.SetLastName(userInputString);
		cout << "Your input was: " << student1.GetLastName() << endl;

		cout << "\nGive me your email address ";
		cin >> userInputString;
		student1.SetEmail(userInputString);
		cout << "Your input was: " << student1.GetEmail() << endl;

		cout << "\nHow old are you? ";
		cin >> userInputInt;
		student1.SetAge(userInputInt);
		cout << "Your input was: " << student1.GetAge() << endl;

		cout << "\nHow many days until your next class ends? ";
		cin >> userInputInt;
		student1.SetDaysToComplete(1, userInputInt);
		cout << "Your input was: " << student1.GetDaysToComplete(1) << endl;

		cout << "\nWhat about the next class? ";
		cin >> userInputInt;
		student1.SetDaysToComplete(2, userInputInt);
		cout << "Your input was: " << student1.GetDaysToComplete(2) << endl;

		cout << "\nAnd the class after that? ";
		cin >> userInputInt;
		student1.SetDaysToComplete(3, userInputInt);
		cout << "Your input was: " << student1.GetDaysToComplete(3) << endl;

		cout << "What is your major? ";
		cin.ignore();
		cin >> userInputString;
		if (userInputString == "SOFTWARE") {
			student1.SetDegreeProgram(SOFTWARE);
		}
		else if (userInputString == "SECURITY") {
			student1.SetDegreeProgram(SECURITY);
		}
		else if (userInputString == "NETWORK") {
			student1.SetDegreeProgram(NETWORK);
		}
		else {
			student1.SetDegreeProgram(EMPTY);
		}
		cout << "Your input was: " << student1.GetDegreeProgram() << endl << endl;

		student1.PrintStudentData();
		cout << "\nIs the information above accurate? (y/n)\n";
		cin >> userInputChar;
		if (userInputChar == 'y') {
			cout << "Student info submitted, thank you!\n";
		}
		else if (userInputChar == 'n') {
			cout << "Student info not submitted, please start over.\n";
		}
		else {
			cout << "Invalid key entered, now you have to start all over again!\n";
		}
	}
	return 0;
}