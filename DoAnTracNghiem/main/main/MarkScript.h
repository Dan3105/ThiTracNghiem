#pragma once
//#include "Subject.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;
class Mark
{
private:
	//Subject* idSubject;
	string idSub;
	float mark;
public:
	string getIdSub() const;

	float getMark() const;
	void setMark(float mark);

	Mark();
	//Mark(Subject*, float);
	Mark(string, float);
};



class ListMark
{
private:
	LinkedList<Mark> listMark;
public:
	ListMark();
	~ListMark();

	int AddMark(Mark);

	template <typename S>
	int DeleteMarkBase(S cmp, bool clearAll)
	{
		return listMark.DeleteBase(cmp, clearAll);
	}

	template <typename S>
	Node<Mark>* FindMark(S cmp)
	{
		return listMark.FindElement(cmp);
	}
	// only base on idSub(idSubject)

	void SortListStudent(bool (*cmp)(Mark, Mark));
};

