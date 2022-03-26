#include "Class.h"

bool ListClass::SearchByID(int pos, string s) {
	return nodes[pos].GetID() == s;
}

bool ListClass::SearchByName(int pos, string s) {
	return nodes[pos].GetName() == s;
}

Class ListClass::SearchClass(string s, bool(*cmp)(int, string))
{
	for (int i = 0; i < size; i++)
	{
		if (cmp(i, s)) return nodes[i];
	}
}

int ListClass::AddClass(Class c)
{
	//Neu danh sach day => khong the them
	if (size == MAX_LIST) return 0;

	nodes[size++] = c;
	return 1;	//Them thanh cong
}