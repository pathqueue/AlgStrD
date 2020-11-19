#pragma once
class LinkedList
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
	size_t size;
public:
	LinkedList();
	~LinkedList();
	void push_back(int); // add to the end of the list
	void push_front(int); // add to the beginning of the list
	void pop_back(); // remove the last element
	void pop_front(); // remove the first element
	void insert(int, size_t); // adding an element by index
	int at(size_t); // get the element by index.
	void remove(size_t); // remove element by index
	size_t get_size(); // get the size of the list
	void print_to_console(); // output list elements to the console through a separator
	void clear(); // remove all list elements
	void set(size_t, int); // replace the element by index with the passed element
	bool isEmpty(); // check if the list is empty
	size_t find_last(LinkedList*); // find the last occurrence of another list in the other list
};


