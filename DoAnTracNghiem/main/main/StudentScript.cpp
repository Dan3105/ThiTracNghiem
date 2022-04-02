#include "StudentScript.h"

#pragma region Student
string Student::getIdStudent() const
{
    return idStudent;
}

string Student::getLastName() const
{
    return lastName;
}

string Student::getFirstName() const
{
    return firstName;
}

char Student::getGender() const
{
    return gender;
}

string Student::getPassword() const
{
    return password;
}

ListMark* Student::getList() const
{
    return listMark;
}


Student::Student() : idStudent(""), lastName(""), firstName(""), gender('M'), password(""), listMark(nullptr) {}

Student::Student(string _idStudent, string _lastName, string _firstName, char _gender, string _password)
{
    idStudent = _idStudent;
    lastName = _lastName;
    firstName = _firstName;
    gender = _gender;
    password = _password;
    listMark = new ListMark();
}

Student::~Student() {};
#pragma endregion

#pragma region ListStudent
ListStudent::ListStudent() {};
ListStudent::~ListStudent() {};

int ListStudent::AddStudent(Student _data)
{
    return listStudent.AddNode(_data);
}

void ListStudent::SortListStudent(bool (*cmp)(Student, Student))
{
    listStudent.Sort(cmp);
}
#pragma endregion


