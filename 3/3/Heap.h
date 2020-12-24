#pragma once
#include "Iterator.h"
#include "Stack.h"
#include <cstdlib>
#include <iostream>
using namespace std;

class Heap 
{
private:
	int* head;
	int HeapSize;
public:
	Heap();
	~Heap();
	int heapsize(); // размер массива
	int at(int); // значение элемента по индексу
	void heapify(int);  // упорядочение кучи
	void insert(int); // добавление элемента в дерево по ключу. 
	bool contains(int); // поиск элемента в дереве по ключу	
	void remove(int); // удаление элемента дерева по ключу
	Iterator* create_dft_iterator(); // создание итератора, реализующего один из методов обхода в глубину (depth-first traverse)
	Iterator* create_bft_iterator(); // создание итератора, реализующего методы обхода в ширину (breadth-first traverse)
	void out(Iterator*); // вывод массива итератором

	class dft_iterator : public Iterator
	{
	private:
		int* head;
		int HeapSize;
		int icurrent;
		Stack stack;
	public:
		dft_iterator(int*, int, int);
		~dft_iterator();
		int next() override;
		bool has_next() override;
	};
	class bft_iterator : public Iterator
	{
	private:
		int* head;
		int HeapSize;
		int icurrent;
	public:
		bft_iterator(int*, int, int);
		~bft_iterator();
		int next() override;
		bool has_next() override;
	};
};