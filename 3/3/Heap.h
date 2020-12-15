#pragma once

class Heap {
private:
	static const int MaxSize = 100; 
	int* head;
	int HeapSize;
public:
	Heap();
	~Heap();
	void heapify(int);  // ������������ ����
	bool contains(int); // ����� �������� � ������ �� �����
	void insert(int); // ���������� �������� � ������ �� �����. 
	void remove(int); // �������� �������� ������ �� �����
	//Iterator create_dft_iterator(); // �������� ���������, ������������ ���� �� ������� ������ � ������� (depth-first traverse)
	//Iterator create_bft_iterator() // �������� ���������, ������������ ������ ������ � ������ (breadth-first traverse)	
};