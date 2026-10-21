//*****************************************************************************************************
//
//		File:					studentlist.cpp
//
//		Student:				Cadence Seim
//
//		Assignment:				Program #12
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-Z1
//
//		Due:					4/31/2025
//
//
//		This displays and alters a linked list of students. 
//	
//		Other files required:
//		1. node.h
//		2. list.h
//		3. student.h
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>

using namespace std;

#include "student.h"
#include "DLList.h"

//*****************************************************************************************************

char getChoice();
void process(LList<Student>&);
void buildList(LList<Student>&);
void displayStudents(LList<Student>&);
void displayReversedStudents(LList<Student>&);
void countStudents(LList<Student>&);
void addNewStudent(LList<Student>&);
void removeStudent(LList<Student>&);
void findStudent(LList<Student>&);

//*****************************************************************************************************

int main()
{
	LList<Student> studentList;

	buildList(studentList);
	process(studentList);

	return 0;
}

//*****************************************************************************************************

char getChoice()
{
	char choice; 
	bool valid; 

	cout << "======== MENU ======== \n"
		 << "A: Add a new student \n"
		 << "F: Find a student record \n"
		 << "R: Remove a student\n"
		 << "C: Count students\n"
		 << "D: Display students\n"
		 << "E: Display Reversed students\n"
		 << "Q: Quit\n"
		 << "Enter your choice: ";

	do
	{
		cin >> choice;
		choice = toupper(choice);

		switch (choice)
		{
		case 'A':
		case 'F':
		case 'R':
		case 'C':
		case 'D':
		case 'E':
		case 'Q':
			valid = true;
			break;
		default:
			valid = false;
			cout << "Invalid choice. Please try again.\n";
		}
	} while (!valid);
	
	return choice;
}

//*****************************************************************************************************

void process(LList<Student>& studentList)
{
	char choice;
	do
	{
		choice = getChoice();

		switch (choice)
		{
		case 'A':
			addNewStudent(studentList);
			break;
		case 'F':
			findStudent(studentList);
			break;
		case 'R':
			removeStudent(studentList);
			break;
		case 'C':
			countStudents(studentList);
			break;
		case 'D':
			displayStudents(studentList);
			break;
		case 'E':
			displayReversedStudents(studentList);
		case 'Q':
			break;
		default:
			cout << "Invalid choice. Try again.\n";
		}
	} while (choice != 'Q');
}

//*****************************************************************************************************

void buildList(LList<Student>& studentList)
{
	Student student;
	ifstream studentData;

	studentData.open("studentFile.txt");

	while (studentData >> student.id)
	{
		studentData.ignore();
		studentData.getline(student.name, 50);
		studentData.getline(student.citystate, 50);
		studentData >> student.phone
					>> student.gender
					>> student.year
					>> student.credits
					>> student.gpa
					>> student.major;

		studentList.insert(student);
	}

	studentData.close();
}

//*****************************************************************************************************

void displayStudents(LList<Student>& studentList)
{
	cout << endl << " \t \t STUDENT LIST" << endl;
	cout << "=======================================================" << endl;
	cout << left << setw(8) << "ID" << setw(32) << "NAME" << setw(8) << "MAJOR" 
		 << right << setw(6) << "GPA" << endl;
	cout << "=======================================================" << endl;
	studentList.display();
	cout << endl;
}

//*****************************************************************************************************

void displayReversedStudents(LList<Student>& studentList)
{
	cout << endl << " \t \t STUDENT LIST" << endl;
	cout << "=======================================================" << endl;
	cout << left << setw(8) << "ID" << setw(32) << "NAME" << setw(8) << "MAJOR"
		<< right << setw(6) << "GPA" << endl;
	cout << "=======================================================" << endl;
	studentList.displayReverse();
	cout << endl;

}

//*****************************************************************************************************

void countStudents(LList<Student>& studentList)
{
	cout << "\nThere are " << studentList.getNumValues() << " students in the list.\n";
}

//*****************************************************************************************************

void addNewStudent(LList<Student>& studentList)
{
	Student student;

	cout << "\nEnter student ID: ";
	cin >> student.id;
	cin.ignore();

	cout << "Enter name: ";
	cin.getline(student.name, 50);

	cout << "Enter city/state: ";
	cin.getline(student.citystate, 50);

	cout << "Enter phone number: ";
	cin >> student.phone;

	cout << "Enter gender (M/F): ";
	cin >> student.gender;

	cout << "Enter year: ";
	cin >> student.year;

	cout << "Enter credits: ";
	cin >> student.credits;

	cout << "Enter GPA: ";
	cin >> student.gpa;

	cout << "Enter major: ";
	cin >> student.major;

	if (studentList.insert(student))
	{
		cout << "\nStudent inserted successfully:\n" << student << endl;
	}
	else
	{
		cout << "\nFailed to insert student. Possibly duplicate ID.\n";
	}
}

//*****************************************************************************************************

void removeStudent(LList<Student>& studentList)
{
	Student student;
	cout << "\nEnter student ID to remove: ";
	cin >> student.id;

	if (studentList.remove(student))
	{
		cout << "\nStudent removed:\n" << student << endl;
	}
	else
	{
		cout << "\nStudent not found.\n";
	}
}

//*****************************************************************************************************

void findStudent(LList<Student>& studentList)
{
	Student student;
	cout << "\nEnter student ID to search for: ";
	cin >> student.id;

	if (studentList.retrieve(student))
	{
		cout << "\nStudent found:\n" << student << endl;
	}
	else
	{
		cout << "\nStudent not found.\n";
	}
}

//*****************************************************************************************************

/*

======== MENU ========
A: Add a new student
F: Find a student record
R: Remove a student
C: Count students
D: Display students
E: Display Reversed students
Q: Quit
Enter your choice: E

				 STUDENT LIST
=======================================================
ID      NAME                            MAJOR      GPA
=======================================================
32631   Freud, JR, Fred E               PSYC      1.85
32598   Xerxes, Art I                   GREE      3.25
31631   Aristotle, Alice A              PHIL      3.10
30878   Lewis, Clark N                  GEOG      3.37
30749   Mendelssohn, Mozart W           MUSC      2.87
30655   Angelo, Mike L                  ART       3.74
30381   Elba, Able M                    SPEE      3.40
30280   Dewey, Johanna A                EDUC      3.83
30268   Newmann, Alfred E               EDUC      0.99
29583   Yewliss, Cal C                  MATH      2.99
28658   Cicero, Marsha                  LATI      2.87
27503   Fahrenheit, Felicia O           CHEM      3.85
26316   Custer, General G               HIST      1.95
25831   Santamaria, Nina P              HIST      1.77
25377   Porgy, Bess N                   MUSI      2.78
24237   Euler, Lennie L                 MATH      3.83
23750   Vespucci, Vera D                GEOG      2.29
23544   Gestalt, Gloria G               PSYC      2.48
23497   Fault, Paige D                  CPSC      2.95
23314   Macdonald, Ronald B             CPSC      2.99
22447   Zylstra, Zelda A                ENGL      1.95
22277   Principal, Pamela P             EDUC      1.75
21144   Pasteur, Louise A               BIOL      3.10
20991   Augusta, Ada B                  CPSC      3.83
20454   Chicita, Juanita A              BIOL      2.66
19918   Virus, Vera W                   CPSC      3.25
19077   Medes, Archie L                 ENGR      3.10
18264   Lucky, Lucy L                   HIST      2.29
18213   Marx, Karl Z                    ECON      2.75
17424   Nakamura, Toky O                SOCI      1.95
17376   Scrooge, Ebenezer T             SOCI      3.25
16622   Issacson, Esau B                RELI      2.98
16540   Weerd, Dewey L                  PHIL      2.99
16183   Kuts, Cole                      FOOD      3.98
15889   Gazelle, Gwendolyn D            PE        2.78
15802   Pascal, Blaze R                 CPSC      1.98
15755   VandenVander, Vanessa V         HIST      3.74
15671   Rembrandt, Roberta E            ART       2.20
15052   Einstein, Alfred M              ENGR      2.78
14815   Tchaikovsky, Wolfgang A         MUSC      2.75
14674   Rockne, Newton K                PE        1.98
13511   Pitt, Stew                      GNED      0.21
11951   Mouse, Michael E                EDUC      1.99
11749   Issacson, Jacob A               RELI      2.99
11688   Kronecker, Leo P                MATH      2.75
10304   Deutsch, Sprechen Z             GERM      3.05
10236   Andrews, Peter J                CPSC      2.78
9743    Johnson, James L                ENGR      3.15
9463    Hochschule, Hortense C          EDUC      2.70
7885    Fibonacci, Leonard O            MATH      3.25
7844    Aardvark, Anthony A             ENGR      2.79
7448    Roosevelt, Rose Y               POLS      2.95
7107    Shoemaker, Imelda M             POLS      3.15
5873    Psycho, II,  Prunella E         PSYC      2.99
5710    Busch, Arch E                   ENGR      2.75
5430    Nightingale, Florence K         NURS      3.15
5316    GotoDijkstra, Edgar G           CPSC      4.00
4777    Gauss, Carl F                   MATH      4.00
4559    Shyster, Samuel D               SOCI      1.95
4454    Atanasoff, Eniac C              CPSC      1.88
3930    Leibniz, Gottfried W            MATH      1.95

*/