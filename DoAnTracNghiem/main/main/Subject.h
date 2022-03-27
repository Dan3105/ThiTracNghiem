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
	string id;	//max id contain 15 characters
	string name;
public:
	//Constructor & Destructor
	Subject() { };
	~Subject() { };

	//Copy constructor
	Subject(string id, string name);
	Subject(Subject* other);


	//Functions
	string GetID() { return this->id; }
	string GetName() { return this->name; }
	void SetID(string id) { this->id = id; }
	void SetName(string name) { this->name = name; }
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
	Subject* GetNode(int pos);

	bool SearchSubID(int position, string id);
	bool SearchSubName(int position, string name);
	Subject* SearchSubject(string s, bool(*cmp)(int, string));
	void ClearList();

	int AddSubject(Subject new_sub);	//Them mon hoc theo trinh tu id
	int AddSubjectAt(Subject new_sub, int pos);
	int DelSubjectAt(int position);

	int ChangeSubjectId(string id, int pos);
	int ChangeSubjectName(string name, int pos);
};