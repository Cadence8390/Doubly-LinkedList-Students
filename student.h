//*****************************************************************************************************
//
//		File:					student.h
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
//		This is the application header for overloaded operators.
//	
//		Other files required:
//			
//			
//*****************************************************************************************************

#ifndef STUDENT_H
#define STUDENT_H

#include <iomanip>

//*****************************************************************************************************

struct Student
{
	int id;
	char name[50];
	char citystate[50];
	char phone[12];
	char gender; 
	int year; 
	int credits; 
	float gpa;
	char major[6];

	Student();
	friend ostream& operator << (ostream& out, const Student& data);

	bool operator == (const Student& rhs) const;
	bool operator == (int value) const;
	bool operator != (const Student& rhs) const;
	bool operator != (int value) const;
	bool operator < (const Student& rhs) const;
	bool operator < (int value) const;
	bool operator > (const Student& rhs) const;
	bool operator > (int value) const;
	bool operator <= (const Student& rhs) const;
	bool operator <= (int value) const;
	bool operator >= (const Student& rhs) const;
	bool operator >= (int value) const;
};

//*****************************************************************************************************

Student::Student()
{
	id = 0;
}

ostream& operator << (ostream& out, const Student& data)
{
	out << left << setw(8) << data.id
		<< setw(32) << data.name
		<< setw(8) << data.major
		<< right << fixed << setprecision(2) << setw(6) << data.gpa;
	return out;
}

//*****************************************************************************************************

bool Student:: operator == (const Student& rhs) const
{
	return (this->id == rhs.id);
}

//*****************************************************************************************************

bool Student:: operator == (int value) const
{
	return (this->id == value);
}

//*****************************************************************************************************

bool Student:: operator != (const Student& rhs) const
{
	return (this->id != rhs.id);
}

//*****************************************************************************************************

bool Student:: operator != (int value) const
{
	return (this->id != value);
}

//*****************************************************************************************************

bool Student:: operator < (const Student& rhs) const
{
	return (this->id < rhs.id);
}

//*****************************************************************************************************

bool Student:: operator < (int value) const
{
	return (this->id < value);
}

//*****************************************************************************************************

bool Student:: operator > (const Student& rhs) const
{
	return (this->id > rhs.id);
}

//*****************************************************************************************************

bool Student:: operator > (int value) const
{
	return (this->id > value);
}

//*****************************************************************************************************

bool Student:: operator <= (const Student& rhs) const
{
	return (this->id <= rhs.id);
}

//*****************************************************************************************************

bool Student:: operator <= (int value) const
{
	return (this->id <= value);
}

//*****************************************************************************************************

bool Student:: operator >= (const Student& rhs) const
{
	return (this->id >= rhs.id);
}

//*****************************************************************************************************

bool Student:: operator >= (int value) const
{
	return (this->id >= value);
}

//*****************************************************************************************************
#endif