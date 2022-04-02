#include <iostream>
#include "MarkScript.h"

using namespace std;

//Test chuong trinh
int main()
{
	ListMark* newList = new ListMark();
	Mark temp("haha", 2);
	Mark temp1("haha", 5);
	Mark temp2("haha", 12);
	Mark temp3("haha", 7);
	Mark temp4("haha", 5);

	newList->AddMark(temp);
	newList->AddMark(temp1);
	newList->AddMark(temp2);
	
	cout << newList->DeleteMarkBase([=](const Mark& temp) {return temp.getMark() == 2; }, false);

	cout << newList->FindMark([=](const Mark& temp) {return temp.getMark() == 9; });

	return 0;
}