#include "Heap.h"
#include "Iterator.h"

int main() 
{
	Heap* heap = new Heap();
	heap->insert(10);
	heap->insert(6);
	heap->insert(8);								 
	heap->insert(3);
	heap->insert(2);
	heap->insert(4);
	heap->insert(1);
	heap->remove(6);
	Iterator* heap_iterator1 = heap->create_bft_iterator();

	heap->out(heap_iterator1);
	system("pause");
}