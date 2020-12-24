#pragma once
#include <iostream>

class Stack
{
private:
	class Node
	{
	public:
		int data;
		Node* next;
		Node* prev;
		Node(int, Node*, Node*);
		~Node();
	};
	Node* head;
	Node* tail;
public:
	size_t size;
	Stack();
	~Stack();
	bool isEmpty();
	void push(int);
	int pop();
	void clear();
};