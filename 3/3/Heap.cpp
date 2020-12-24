#include "Heap.h"

Heap::Heap() {
	HeapSize = 0;
	head = (int*)malloc(HeapSize * sizeof(int));
}

Heap::~Heap() {
	delete head;
	HeapSize = 0;
}

int Heap::heapsize()
{
	return HeapSize;
}

int Heap::at(int index)
{
	return head[index];
}

void Heap::heapify(int i) {
	int temp;
	int iparent;
	if (i % 2 == 0) {
		iparent = (i - 2) / 2;
		if (iparent >= 0) {
			if (head[i] > head[iparent]) {
				temp = head[i];
				head[i] = head[iparent];
				head[iparent] = temp;
				heapify(iparent);
			}
		}
	}
	else {
		iparent = (i - 1) / 2;
		if (iparent >= 0) {
			if (head[i] > head[iparent]) {
				temp = head[i];
				head[i] = head[iparent];
				head[iparent] = temp;
				heapify(iparent);
			}
		}
	}
}

void Heap::insert(int newElem)
{
	HeapSize++;
	head = (int*)realloc(head, HeapSize * sizeof(int));
	head[HeapSize - 1] = newElem;
	heapify(HeapSize - 1);
}

bool Heap::contains(int Elem)
{
	for (int i = 0; i < HeapSize; i++)
		if (head[i] == Elem) return true;
	return false;
}

void Heap::remove(int delElem)
{
	int temp = 0, i = 0;
	if (contains(delElem))
	{
		while (head[i] != delElem)  i++;
		if (i < HeapSize - 1)
		{
			temp = head[i];
			head[i] = head[HeapSize - 1];
			head[HeapSize - 1] = temp;
			heapify(i);
		}
		HeapSize--;
		head = (int*)realloc(head, HeapSize * sizeof(int));
	}
	else throw std::out_of_range("No element");
}

Heap::dft_iterator::dft_iterator(int* head, int HeapSize, int icorrent)
{
	this->head = head;
	this->HeapSize = HeapSize;
	this->icurrent = icorrent;
}

Heap::dft_iterator::~dft_iterator()
{
	delete head;
}

int Heap::dft_iterator::next()
{
	if (!has_next())
		throw std::out_of_range("No more elements");
	int temp = head[icurrent];
	int left = icurrent * 2 + 1;
	int right = icurrent * 2 + 2;
	if (icurrent == 0) stack.push(0);
	if (right < HeapSize)
	{
		stack.push(right);
		icurrent = left;
	}
	else if (left < HeapSize) icurrent = left;
	else
	{
		icurrent = stack.pop();
		if (stack.isEmpty()) stack.size = -1;
	}
	return temp;
}

bool Heap::dft_iterator::has_next()
{
	if (stack.size == -1) return false;
	if (HeapSize == 0) return false;
	if (icurrent == 0) return true;
	if (stack.isEmpty()) return false;
	else return true;
}

Iterator* Heap::create_dft_iterator()
{
	return new dft_iterator(head, HeapSize, 0);
}

Heap::bft_iterator::bft_iterator(int* head, int HeapSize, int icorrent) 
{
	this->head = head;
	this->HeapSize = HeapSize;
	this->icurrent = icorrent;
}

Heap::bft_iterator::~bft_iterator() 
{
	delete head;
}

int Heap::bft_iterator::next()
{
	int temp = head[icurrent];
	if (!has_next()) 
		throw std::out_of_range("No more elements");
	icurrent++;
	return temp;
}

bool Heap::bft_iterator::has_next()
{
	if (icurrent < HeapSize) return true;
	else return false;
}

Iterator* Heap::create_bft_iterator()
{
	return new bft_iterator(head, HeapSize, 0);
}

void Heap::out(Iterator* heap_iterator) 
{
	while (heap_iterator->has_next()) cout << heap_iterator->next() << " ";
	cout << endl;
}