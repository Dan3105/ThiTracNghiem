#include "Class.h"

//Cau truc lop
void Class::SetAll(string id, string name)
{
	this->id = id;
	this->name = name;
}

//Cau truc danh sach lop
Class* ListClass::GetNode(int pos)
{
	if (pos < 0 || pos >= size) return nullptr;
	return &nodes[pos];
}

bool ListClass::SearchByID(int pos, string s) {
	return nodes[pos].GetID() == s;
}
bool ListClass::SearchByName(int pos, string s) {
	return nodes[pos].GetName() == s;
}
Class* ListClass::SearchClass(string s, ListClass* obj, bool(ListClass::* cmp)(int, string))
{
	//Tim kiem tuyen tinh (O(n))
	for (int i = 0; i < size; i++)
		if ((obj->*cmp)(i, s)) { return &nodes[i]; }
	return nullptr;
}

bool ListClass::StringCompare(string s1, string s2)
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
int ListClass::AddClass(Class c)
{
	//Neu danh sach day => khong the them
	if (size == MAX_LIST) return 0;
	//Tim vi tri thich hop de them vao
	int pos = size;
	string id = c.GetID();
	for (int i = 0; i < size; i++)
	{
		if (ListClass::StringCompare(id, nodes[i].GetID()))
		{
			pos = i;
			break;
		}
	}
	for (int i = size; i > pos; i--)
	{
		nodes[i] = nodes[i - 1];
	}
	nodes[pos] = c;
	size++;
	return 1;	//Them thanh cong
}
//Xoa o vi tri
int ListClass::DeleteClass(int pos)
{
	//Cac truong hop khong the xoa
	if (size == 0 || pos < 0 || pos > size) return 0;

	for (int i = pos; i < size - 1; i++)
	{
		nodes[i] = nodes[i + 1];
	}
	nodes[size - 1].SetAll("", "");
	size--;
	return 1;	//Them thanh cong
}