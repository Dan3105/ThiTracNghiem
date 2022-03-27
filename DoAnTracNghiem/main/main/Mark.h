#include "Subject.h"
#include "LinkedList.h"
class Mark
{
private:
	Subject* idSubject;
	string idSub;
	float mark;
public:
    string getIdSub() const;

    float getMark() const;
    void setMark(float mark);

	Mark();
	Mark(Subject*, float);
};

class ListMark
{
private:
	LinkedList<Mark> listMark;
public:
	ListMark();
	~ListMark();

	int AddMark(Mark);
	int DeleteMarkBase(bool (*)(const Mark&), bool);
	Node<Mark>* FindMark(bool (*)(const Mark&));// only base on idSub(idSubject)

	void SortListStudent(bool (*cmp)(Mark, Mark));
};

