#include "MarkScript.h"

#pragma region Mark
string Mark::getIdSub() const
{
    return idSub;
}

float Mark::getMark() const
{
    return mark;
}

void Mark::setMark(float mark)
{
    this->mark = mark;
}

//Mark::Mark() : idSubject(nullptr), idSub(""), mark(0) {};
Mark::Mark() : idSub(""), mark(0) {};

//Mark::Mark(Subject* _idSubject, float _mark)
//{
//    idSubject = _idSubject;
//    idSub = idSubject->getId();
//    mark = _mark;
//}

Mark::Mark(string _idSubject, float _mark)
{
    idSub = _idSubject;
    mark = _mark;
}

#pragma endregion

#pragma region ListMark
ListMark::ListMark() {};
ListMark::~ListMark() {};
int ListMark::AddMark(Mark _data)
{
    return listMark.AddNode(_data);
}

void ListMark::SortListStudent(bool(*cmp)(Mark, Mark))
{
    listMark.Sort(cmp);
}


#pragma endregion


