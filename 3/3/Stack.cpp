#include "Stack.h"

Stack::Node::Node(int data, Node* next = nullptr, Node* prev = nullptr)
{
	this->data = data;
	this->next = next;
	this->prev = prev;
}

Stack::Node::~Node()
{
	next = nullptr;
	prev = nullptr;
}

Stack::Stack()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}
Stack::~Stack()
{
	clear();
}

bool Stack::isEmpty()
{
	if (size == 0) return true;
	else return false;
};

void Stack::push(int index_newElem)
{
	if (isEmpty())
	{
		tail = new Node(index_newElem);
		head = tail;
	}
	else
	{
		head->prev = new Node(index_newElem);
		head->prev->next = head;
		head = head->prev;
	}
	size++;
}

int Stack::pop()
{
	int temp;
	if (isEmpty()) { return 0; }
	else
	{
		if (size == 1)
		{
			temp = tail->data;
			delete tail;
			head = nullptr;
			tail = nullptr;
			size--;
		}
		else
		{
			temp = head->data;
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
			size--;
		}
	}
	return temp;
};

void Stack::clear()
{
	while (size > 0)
		pop();
}