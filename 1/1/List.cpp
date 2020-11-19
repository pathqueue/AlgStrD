#include "List.h"
#include <stdexcept>
#include <iostream>

using namespace std;

LinkedList::Node::Node(int data, Node* next = nullptr, Node* prev = nullptr)
{
	this->data = data;
	this->next = next;
	this->prev = prev;
};

LinkedList::Node::~Node()
{
	next = nullptr;
	prev = nullptr;
};

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
};
LinkedList::~LinkedList()
{
	clear();
};
void LinkedList::push_back(int newElem)
{
	if (size == 0)
	{
		head = new Node(newElem);
		tail = head;
	}
	else
	{
		tail->next = new Node(newElem);
		tail->next->prev = tail;
		tail = tail->next;
	}
	size++;
};
void LinkedList::push_front(int newElem)
{
	if (size == 0)
	{
		tail = new Node(newElem);
		head = tail;
	}
	else
	{
		head->prev = new Node(newElem);
		head->prev->next = head;
		head = head->prev;
	}
	size++;
};
void LinkedList::pop_back()
{
	if (size == 0) { return; }
	else
	{
		if (size == 1)
		{
			delete tail;
			head = nullptr;
			tail = nullptr;
			size--;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
			size--;
		}
	}
};
void LinkedList::pop_front()
{
	if (size == 0) { return; }
	else
	{
		if (size == 1)
		{
			delete tail;
			head = nullptr;
			tail = nullptr;
			size--;
		}
		else
		{
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
			size--;
		}
	}
};
void LinkedList::insert(int newElem, size_t index)
{
	if (index >= size) 
	{
		throw out_of_range("Index is greater than list size");
	}
	else 
	{
		Node* cur = head;
		for (int i = 0; i < index; i++)
		{
			cur = cur->next;
		}
		Node* temp1 = cur;
		Node* temp2 = cur->prev;
		cur->prev = new Node(newElem);
		cur = cur->prev;
		cur->next = temp1;
		cur->prev = temp2;
		if (temp2 != nullptr) temp2->next = cur;
		if (index == 0) head = head->prev;
		size++;
		cur = nullptr;
	}
};
int LinkedList::at(size_t index)
{
	if (index >= size)
	{
		throw out_of_range("Index is greater than list size");
	}
	else
	{
		int data;
		Node* cur = head;
		for (int i = 0; i < index; i++)
		{
			cur = cur->next;
		}
		data = cur->data;
		cur = nullptr;
		return data;
	}
};
void LinkedList::remove(size_t index)
{
	if (index >= size)
	{
		throw out_of_range("Index is greater than list size");
	}
	else
	{
		Node* cur = head;
		for (int i = 0; i < index; i++)
		{
			cur = cur->next;
		}
		if (size == 1)
		{
			delete cur;
			head = nullptr;
			tail = nullptr;
			size--;
		}
		else
		{
			if (index == 0) 
			{ 
				head = head->next; 
				delete cur; 
				head->prev = nullptr;
			}
			else if (index == size - 1)
			{
				tail = tail->prev;
				delete cur;
				tail->next = nullptr;
			}
			else
			{
				cur->next->prev = cur->prev;
				cur->prev->next = cur->next;	
				delete cur;
			}
			cur = nullptr;
			size--;
		}
	}
};
size_t LinkedList::get_size()
{
	return size;
};
void LinkedList::print_to_console()
{
	if (size == 0) cout << "The list is empty\n";
	else 
	{
		Node* cur = head;
		for (int i = 0; i < size; i++)
		{
			cout << cur->data << ' ';
			cur = cur->next;
		}
		cout << '\n';
		cur = nullptr;
	}
};
void LinkedList::clear()
{
	while (size > 0)
	{
		pop_front();
	}
};
void LinkedList::set(size_t index, int newData) 
{
	if (index >= size)
	{
		throw out_of_range("Index is greater than list size");
	}
	else
	{
		Node* cur = head;
		for (int i = 0; i < index; i++)
		{
			cur = cur->next;
		}
		cur->data = newData;
		cur = nullptr;
	}
};
bool LinkedList::isEmpty()
{
	if (size == 0) return 1;
	else return 0;
};
size_t LinkedList::find_last(LinkedList* list_2)
{
	size_t start = -1;
	if (list_2->size > size)
	{
		return start;
	}
	else
	{
		Node* cur = head;
		Node* cur2;
		for (int i = 0; i < size; i++)
		{
			bool done = false;
			bool inter = false;
			bool error = false;
			cur2 = list_2->head;
			for (int j = 0; j < list_2->size && i < size; j++)
			{	
				if (cur2->data == cur->data)
				{
					if (j != list_2->size - 1)
					{
						cur = cur->next;
						i++;
						cur2 = cur2->next;
						inter = true;
					}
					if (j == list_2->size - 1) done = true;
				}
				else { error = true; break; }
				if (j != list_2->size - 1 && i == size) error = true;
			}
			if (done && list_2->size == 1) { start = i; cur = cur->next; }
			if (done && list_2->size > 1) { start = i - list_2->size + 1; cur = cur->next; }
			if (error && !inter) cur = cur->next;
			if (error && inter) i--;
		}
		cur = nullptr;
		cur2 = nullptr;
		return start;
	}
};