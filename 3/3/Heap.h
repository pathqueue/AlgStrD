#pragma once

class Heap {
private:
	static const int MaxSize = 100; 
	int* head;
	int HeapSize;
public:
	Heap();
	~Heap();
	void heapify(int);  // упорядочение кучи
	bool contains(int); // поиск элемента в дереве по ключу
	void insert(int); // добавление элемента в дерево по ключу. 
	void remove(int); // удаление элемента дерева по ключу
	//Iterator create_dft_iterator(); // создание итератора, реализующего один из методов обхода в глубину (depth-first traverse)
	//Iterator create_bft_iterator() // создание итератора, реализующего методы обхода в ширину (breadth-first traverse)	
};