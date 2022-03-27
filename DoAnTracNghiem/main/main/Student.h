#pragma once
#include <iostream> 
#include "Mark.h"
#include "LinkedList.h"
using namespace std;
class Student
{
private:
	string idStudent;
	string lastName;
	string firstName;
	char gender;
	string password;
	ListMark* listMark;

public:
#pragma region Getter
	string getIdStudent() const;

	string getLastName() const;

	string getFirstName() const;

	char getGender() const;

	string getPassword() const;

	ListMark* getList() const;
#pragma endregion
	
#pragma region  Constructor/DeConstructor
	Student();
	Student(string, string, string, char, string);

	~Student();
#pragma endregion

	

};

class ListStudent
{
private:
	LinkedList<Student> listStudent;
public:
	ListStudent();
	~ListStudent();
	
	int AddStudent(Student);
	int DeleteStudentWith(bool (*)(const Student&), bool); // delete base on idStudent
	Node<Student>* FindStudent(bool (*)(const Student&));
	void SortListStudent(bool (*cmp)(Student, Student));
};

