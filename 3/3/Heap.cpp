#include "Heap.h"

Heap::Heap() {
	head = new int[MaxSize];
	HeapSize = 0;
}

Heap::~Heap() {
	delete head;
	HeapSize = 0;
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
			}
		}
	}
}