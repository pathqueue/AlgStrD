#include "CppUnitTest.h"
#include "../3/Heap.h"
#include "../3/Iterator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:
		Heap* heap;
		TEST_METHOD_INITIALIZE(Set_up)
		{
			heap = new Heap();
		}
		TEST_METHOD_CLEANUP(Clean_up)
		{
			delete heap;
		}
		TEST_METHOD(Insert)
		{
			heap->insert(1);
			heap->insert(2);	//						  5(0)
			heap->insert(3);	// correct heap		  4(1)    2(2)								 
			heap->insert(4);	//					1(3) 3(4)
			heap->insert(5);
			Assert::AreEqual(heap->at(1), 4); // Is there 4 at index 1?
		}
		TEST_METHOD(Contains_true)
		{
			heap->insert(1);
			heap->insert(2);	//						  5(0)
			heap->insert(3);	// correct heap		  4(1)    2(2)								 
			heap->insert(4);	//					1(3) 3(4)
			heap->insert(5);
			Assert::IsTrue(heap->contains(4)); // Is there 4 in heap?
		}
		TEST_METHOD(Contains_false)
		{
			heap->insert(1);
			heap->insert(2);	//						  5(0)
			heap->insert(3);	// correct heap		  4(1)    2(2)								 
			heap->insert(4);	//					1(3) 3(4)
			heap->insert(5);
			Assert::IsFalse(heap->contains(6)); // Is there 6 in heap?
		}
		TEST_METHOD(Remove)
		{
			heap->insert(1);
			heap->insert(2);	//						   7(0)
			heap->insert(3);	// correct heap		  4(1)      6(2)								 
			heap->insert(4);	// after remove		1(3) 3(4) 2(5) 5(6)
			heap->insert(5);
			heap->insert(6);	//						   7(0)
			heap->insert(7);	// correct heap		  5(1)      6(2)
			heap->remove(1);	// after remove		4(3) 3(4) 2(5)
			Assert::AreEqual(heap->at(1), 5); // Is there 5 at index 1?
		}
		TEST_METHOD(Remove_no_element)
		{
			try
			{
				heap->insert(1);
				heap->insert(2);	//						   7(0)
				heap->insert(3);	// correct heap		  4(1)      6(2)								 
				heap->insert(4);	// after remove		1(3) 3(4) 2(5) 5(6)
				heap->insert(5);
				heap->insert(6);	//						   7(0)
				heap->insert(7);	// correct heap		  5(1)      6(2)
				heap->remove(8);	// after remove		1(3) 3(4) 2(5) 5(6)
			}
			catch (std::out_of_range err)
			{
				Assert::AreEqual("No element", err.what());
			}
		}
		TEST_METHOD(Remove_empty_heap)
		{
			try
			{
				heap->remove(1);
			}
			catch (std::out_of_range err)
			{
				Assert::AreEqual("No element", err.what());
			}
		}
		TEST_METHOD(Dft_iterator_has_next)
		{
			heap->insert(1);
			heap->insert(2);
			heap->insert(3);
			heap->insert(4);
			heap->insert(5);
			Iterator* dft_iterator = heap->create_dft_iterator();
			int test_int = 0, temp;
			while (dft_iterator->has_next()) { temp = dft_iterator->next(); test_int++; }
			Assert::AreEqual(test_int, heap->heapsize());
		}
		TEST_METHOD(Dft_iterator_next)
		{
			heap->insert(1);
			heap->insert(2);
			heap->insert(3);
			heap->insert(4);
			heap->insert(5);
			Iterator* dft_iterator = heap->create_dft_iterator();
												 //										  5
			int test_arr[5] = { 5, 4, 1, 3, 2 }; // correct heap					  4       2
												 // depth-first traverse			1   3
			bool test_bool = true;
			for (int i = 0; i < 5; i++)
				if (dft_iterator->next() != test_arr[i]) test_bool = false;
			Assert::IsTrue(test_bool);
		}
		TEST_METHOD(Bft_iterator_has_next)
		{
			heap->insert(1);
			heap->insert(2);
			heap->insert(3);
			heap->insert(4);
			heap->insert(5);
			Iterator* bft_iterator = heap->create_bft_iterator();
			int test_int = 0, temp;
			while (bft_iterator->has_next()) { temp = bft_iterator->next(); test_int++; }
			Assert::AreEqual(test_int, heap->heapsize());
		}
		TEST_METHOD(Bft_iterator_next)
		{							
			heap->insert(1);
			heap->insert(2);
			heap->insert(3);
			heap->insert(4);
			heap->insert(5);
			Iterator* bft_iterator = heap->create_bft_iterator();
												 //										  5
			int test_arr[5] = { 5, 4, 2, 1, 3 }; // correct heap					  4       2
												 //	breadth-first traverse			1   3
			bool test_bool = true;
			for (int i = 0; i < 5; i++)
				if (bft_iterator->next() != test_arr[i]) test_bool = false;
			Assert::IsTrue(test_bool);
		}
	};
}
