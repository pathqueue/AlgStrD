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
	int heapsize(); // ������ �������
	int at(int); // �������� �������� �� �������
	void heapify(int);  // ������������ ����
	void insert(int); // ���������� �������� � ������ �� �����. 
	bool contains(int); // ����� �������� � ������ �� �����	
	void remove(int); // �������� �������� ������ �� �����
	Iterator* create_dft_iterator(); // �������� ���������, ������������ ���� �� ������� ������ � ������� (depth-first traverse)
	Iterator* create_bft_iterator(); // �������� ���������, ������������ ������ ������ � ������ (breadth-first traverse)
	void out(Iterator*); // ����� ������� ����������

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