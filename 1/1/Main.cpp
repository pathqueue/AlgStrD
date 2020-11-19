#include <iostream>
#include "List.h"


int main()
{
	LinkedList* list, *list2;
	list = new LinkedList();
	list2 = new LinkedList();
	list->push_back(1);
	list->push_back(2);
	list->push_back(3);
	list->push_back(4);
	list->push_back(5);
	list2->push_back(3);
	list2->push_back(4);
	size_t a = list->find_last(list2);
	delete list;
	delete list2;
	system("pause");
	return 0;
}