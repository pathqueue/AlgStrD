#include "Heap.h"
#include "Iterator.h"

int main() 
{
	Heap* heap = new Heap();
	heap->insert(1);
	heap->insert(2);	//						   7(0)
	heap->insert(3);	// correct heap		  4(1)      6(2)								 
	heap->insert(4);	// after remove		1(3) 3(4) 2(5) 5(6)
	heap->insert(5);
	heap->insert(6);	//						   7(0)
	heap->insert(7);	// correct heap		  5(1)      6(2)
	heap->remove(1);	// after remove		4(3) 3(4) 2(5)
	int test = heap->at(1);
	Iterator* heap_iterator1 = heap->create_bft_iterator();
	heap->out(heap_iterator1);
	system("pause");
}