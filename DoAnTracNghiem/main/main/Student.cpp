#include "Student.h"

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
#pragma endregion

#pragma region ListStudent
int ListStudent::AddStudent(Student _data)
{
    return listStudent.AddNode(_data);
}



int ListStudent::DeleteStudentWith(bool (*cmp)(const Student& st), bool clearAll)
{
    return listStudent.DeleteBase(cmp, clearAll);
}

Node<Student>* ListStudent::FindStudent(bool (*cmp)(const Student& st))
{
    return listStudent.FindElement(cmp);
}

void ListStudent::SortListStudent(bool (*cmp)(Student, Student))
{
    listStudent.Sort(cmp);
}
#pragma endregion


