#include "Subject.h"

//Cau truc mon
//Constructor
Subject::Subject() { }
Subject::~Subject() { }

//Copy constructor
Subject::Subject(string id, string name)
{
	this->id = id;
	this->name = name;
}
Subject::Subject(Subject* other) { *this = *other; }


//Functions
string Subject::getID() { return id; }
string Subject::getName() { return name; }


void Subject::setID(string id) { this->id = id; }
void Subject::setName(string name) { this->name = name; }




//Cau truc sanh sach mon

//Functions
int ListSubject::getSize() { return this->size; }


Subject* ListSubject::getNode(int pos)
{
	if (pos < 0 || pos >= size) return NULL;
	return this->nodes[pos];
}


bool  ListSubject::searchSubID(int pos, string id) {
	return nodes[pos]->getID() == id;
}
bool  ListSubject::searchSubName(int pos, string name) {
	return nodes[pos]->getName() == name;
}
Subject* ListSubject::searchNode(string s, bool(*cmp)(int, string))
{
	for (int i = 0; i < size; i++)
		if (cmp(i, s)) return nodes[i];

	return nullptr;
}


void ListSubject::clearList()
{
	for (int i = 0; i < size; i++) delete nodes[i];
	size = 0;
}


int ListSubject::add_sub_at(Subject new_sub, int pos)
{
	//Khong the them mon hoc vi da day danh sach
	//Hoac do vi tri muon them nhap sai
	if (size == MAX_LIST || pos < 0) return 0;

	if (size == 0) pos = size;
	if (pos > size) pos = size;
	for (int i = size; i > pos; i--) nodes[i] = nodes[i - 1];
	nodes[pos] = new Subject(new_sub);
	size++;
	//Them thanh cong
	return 1;
}
int ListSubject::del_sub_at(int pos)
{
	//Khong the xoa vi danh sach rong
	//Hoac do vi tri muon xoa nhap sai
	if (size == 0 || pos < 0 || pos > size) return 0;

	for (int i = pos; i < size; i++) nodes[i] = nodes[i + 1];
	delete nodes[size - 1];
	size--;
	//Xoa thanh cong
	return 1;
}
int ListSubject::change_subject_id(string id, int pos)
{
	if (size == 0 || pos < 0 || pos > size - 1) return 0;

	nodes[pos]->setID(id);
	//Thay doi thanh cong
	return 1;
}
int ListSubject::change_subject_name(string name, int pos)
{
	if (size == 0 || pos < 0 || pos > size - 1) return 0;

	nodes[pos]->setName(name);
	//Thay doi thanh cong
	return 1;
}