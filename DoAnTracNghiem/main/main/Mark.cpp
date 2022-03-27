#include "Mark.h"
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

Mark::Mark() : idSubject(nullptr), idSub(""), mark(0) {};

Mark::Mark(Subject* _idSubject, float _mark)
{
    idSubject = _idSubject;
    idSub = idSubject->GetID();
    mark = _mark;
}

#pragma endregion

#pragma region ListMark
int ListMark::AddMark(Mark _data)
{
    return listMark.AddNode(_data);
}

int ListMark::DeleteMarkBase(bool(*cmp)(const Mark&), bool clearAll)
{
    return listMark.DeleteBase(cmp, clearAll);
}

Node<Mark>* ListMark::FindMark(bool(*cmp)(const Mark&))
{
    return listMark.FindElement(cmp);
}

void ListMark::SortListStudent(bool(*cmp)(Mark, Mark))
{
    listMark.Sort(cmp);
}


#pragma endregion


