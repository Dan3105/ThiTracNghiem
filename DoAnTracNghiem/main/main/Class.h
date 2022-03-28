#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"
using namespace std;
#define MAX_LIST 10000

class Class
{
private:
	string id = "";
	string name = "";
	ListStudent list;	//Lop tro den danh sach sinh vien
public:
	//Constructor
	Class() { }
	~Class() { }

	void SetAll(string, string);
	void SetID(string s) { this->id = s; }
	void SetName(string s) { this->name = s; }
	string  GetID() { return id; }
	string GetName() { return name; }
};

class ListClass
{
private:
	Class nodes[MAX_LIST];	//Danh sach tuyen tinh
	int size = 0;
public:
	//Constructor & Destructor
	ListClass() { }
	~ListClass() { }

	Class* GetNode(int);

	bool SearchByID(int, string);
	bool SearchByName(int, string);
	Class* SearchClass(string, ListClass*, bool(ListClass::* cmp)(int, string));

	bool StringCompare(string, string);
	int AddClass(Class);	//Them theo trinh tu
	int DeleteClass(int);	//Xoa o vi tri
};