#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
#define MAX_LIST 1000

//STRUCT MON HOC
class Subject
{
private:
	string id;	//max id contain 15 characters
	string name;
public:
	//Constructor & Destructor
	Subject();
	~Subject();

	//Copy constructor
	Subject(string id, string name);
	Subject(Subject* other);


	//Functions
	string getID();
	string getName();
	void setID(string id);
	void setName(string name);
};


//STRUCT DANH SACH MON HOC
class ListSubject
{
private:
	Subject* nodes[MAX_LIST]{ nullptr };
	int size;
public:
	//Constructor & Destructor
	ListSubject() { size = 0; }
	~ListSubject() { }

	//Functions
	int getSize();
	
	Subject* getNode(int pos);

	bool searchSubID(int position, string id);
	bool searchSubName(int position, string name);
	Subject* searchNode(string s, bool(*cmp)(int, string));
	void clearList();

	int add_sub_at(Subject new_sub, int pos);
	int del_sub_at(int position);

	int change_subject_id(string id, int pos);
	int change_subject_name(string name, int pos);
};