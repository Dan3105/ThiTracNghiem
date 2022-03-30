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
	template <typename S>
	int DeleteStudentWith(S cmp, bool clearAll)  // delete base on idStudent
	{
		return listStudent.DeleteBase(cmp, clearAll);
	}
	template <typename S>
	Node<Student>* FindStudent(S cmp)
	{
		return listStudent.FindElement(cmp);
	}
	void SortListStudent(bool (*cmp)(Student, Student));
};

