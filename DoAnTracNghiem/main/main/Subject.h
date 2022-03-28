#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define MAX_LIST 10000

//STRUCT MON HOC
class Subject
{
private:
	string id = "";	//max id contain 15 characters
	string name = "";
public:
	//Constructor & Destructor
	Subject() { };
	~Subject() { };

	//Copy constructor
	Subject(string, string);
	Subject(Subject*);

	//Functions
	string getId() const;
	void setId(string id);

	string getName() const;
	void setName(string name);

};


//STRUCT DANH SACH MON HOC
class ListSubject
{
private:
	Subject* nodes[MAX_LIST]{ nullptr };
	int size = 0;
public:
	//Constructor & Destructor
	ListSubject() { }
	~ListSubject() { }

	//Functions
	int GetSize() { return this->size; }
	Subject* GetNode(int);

	bool SearchByID(int, string);
	bool SearchByName(int, string);
	Subject* SearchSubject(string, ListSubject*, bool(ListSubject::* cmp)(int, string));
	void ClearList();

	//Them mon hoc theo trinh tu id
	bool StringCompare(string, string);
	int AddSubject(Subject);

	//Them mon hoc theo vi tri
	int AddSubjectAt(Subject, int);
	int DelSubjectAt(int);

	int ChangeSubjectId(string, int);
	int ChangeSubjectName(string, int);
};