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

	void SetAll(string id, string name);
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

	Class* GetNode(int pos);

	bool SearchByID(int pos, string s);
	bool SearchByName(int pos, string s);
	Class* SearchClass(string id, ListClass* obj, bool(ListClass::* cmp)(int, string));

	bool StringCompare(string s1, string s2);
	int AddClass(Class c);	//Them theo trinh tu
	int DeleteClass(int position);	//Xoa o vi tri
};