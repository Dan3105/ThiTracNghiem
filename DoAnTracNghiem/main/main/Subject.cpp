#include "Subject.h"

//Cau truc mon
//Copy constructor
Subject::Subject(string id, string name)
{
	this->id = id;
	this->name = name;
}
Subject::Subject(Subject* other) { *this = *other; }

string Subject::getId() const
{
	return id;
}

void Subject::setId(string id)
{
	this->id = id;
}

string Subject::getName() const
{
	return name;
}

void Subject::setName(string name)
{
	this->name = name;
}

//Cau truc danh sach mon
//Functions
Subject* ListSubject::GetNode(int pos)
{
	if (pos < 0 || pos >= size) return nullptr;
	return nodes[pos];
}



bool  ListSubject::SearchByID(int pos, string id) {
	return nodes[pos]->getId() == id;
}
bool  ListSubject::SearchByName(int pos, string name) {
	return nodes[pos]->getName() == name;
}
Subject* ListSubject::SearchSubject(string s, ListSubject* obj, bool(ListSubject::* cmp)(int, string))
{
	for (int i = 0; i < size; i++)
		if ((obj->*cmp)(i, s)) return nodes[i];

	return nullptr;
}

void ListSubject::ClearList()
{
	for (int i = 0; i < MAX_LIST; i++) delete nodes[i];
	size = 0;
}

bool ListSubject::StringCompare(string s1, string s2)
{
	int len1 = s1.size(), len2 = s2.size();
	for (int i = 0; i < len1 && i < len2; i++)
	{
		if (s1[i] < s2[i]) return true;
		else if (s1[i] > s2[i]) return false;
	}
	if (len1 < len2) return true;
	return false;
}
int ListSubject::AddSubject(Subject new_sub)
{
	if (size == MAX_LIST) return 0;
	int pos = size;
	string id = new_sub.getId();
	for (int i = 0; i < size; i++)
	{
		if (ListSubject::StringCompare(id, nodes[i]->getName()))
		{
			pos = i;
			break;
		}
	}
	for (int i = size; i > pos; i--)
	{
		nodes[i] = nodes[i - 1];
	}
	nodes[pos] = new Subject(new_sub);
	size++;
	return 1;	//Them thanh cong
}


int ListSubject::AddSubjectAt(Subject new_sub, int pos)
{
	//Khong the them mon hoc vi da day danh sach
	//Hoac do vi tri muon them nhap sai
	if (size == MAX_LIST || pos < 0) return 0;

	if (size == 0) pos = size; //Mang rong
	else if (pos > size) pos = size; //Neu pos > size thi them vao cuoi
	for (int i = size; i > pos; i--) nodes[i] = nodes[i - 1];
	nodes[pos] = new Subject(new_sub);
	size++;
	//Them thanh cong
	return 1;
}
int ListSubject::DelSubjectAt(int pos)
{
	//Khong the xoa vi danh sach rong
	//Hoac do vi tri muon xoa nhap sai
	if (size == 0 || pos < 0 || pos > size) return 0;

	for (int i = pos; i < size; i++) nodes[i] = nodes[i + 1];
	//nodes[size - 1] = nullptr;	//Khong can vi mang con tro tu dong lam
	size--;
	//Xoa thanh cong
	return 1;
}


int ListSubject::ChangeSubjectId(string id, int pos)
{
	if (size == 0 || pos < 0 || pos > size - 1) return 0;

	nodes[pos]->setId(id);
	//Thay doi thanh cong
	return 1;
}
int ListSubject::ChangeSubjectName(string name, int pos)
{
	if (size == 0 || pos < 0 || pos > size - 1) return 0;

	nodes[pos]->setName(name);
	//Thay doi thanh cong
	return 1;
}


