#include <stdexcept>
#include "CppUnitTest.h"
#include "..\1\List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		LinkedList* list, *list2;
		TEST_METHOD_INITIALIZE(setUp)
		{
			list = new LinkedList();
			list2 = new LinkedList();
		}
		TEST_METHOD_CLEANUP(cleanUp)
		{
			delete list;
			delete list2;
		}
		TEST_METHOD(push_back)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			Assert::AreEqual(list->at(2), 3); // Is the third element equals 3?
		}
		TEST_METHOD(push_front)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_front(3);
			Assert::AreEqual(list->at(0), 3); // Is the first element equals 3?
		}
		TEST_METHOD(pop_back_eq)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list->pop_back();
			Assert::AreEqual(list->at(1), 2); // Is the second element equals 2?
		}
		TEST_METHOD(pop_back_size)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list->pop_back();
			Assert::AreEqual(int(list->get_size()), 2); // Is the size equals 2?
		}
		TEST_METHOD(pop_back_zero)
		{
			list->pop_back();
			Assert::AreEqual(int(list->get_size()), 0); // Is there empty list?
		}
		TEST_METHOD(pop_front_eq)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list->pop_front();
			Assert::AreEqual(list->at(0), 2); // Is the first element equals 2?
		}
		TEST_METHOD(pop_front_size)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list->pop_front();
			Assert::AreEqual(int(list->get_size()), 2); // Is the size equals 2?
		}
		TEST_METHOD(pop_front_zero)
		{
			list->pop_front();
			Assert::AreEqual(int(list->get_size()), 0); // Is there empty list?
		}
		TEST_METHOD(insert_index_0)
		{
			list->push_back(1);
			list->push_back(2);
			list->insert(3, 0);
			Assert::AreEqual(list->at(0), 3); // Is the first element equals 3?
		}
		TEST_METHOD(insert_index_0_size)
		{
			list->push_back(1);
			list->push_back(2);
			list->insert(3, 0);
			Assert::AreEqual(int(list->get_size()), 3); // Is the size equals 3?
		}
		TEST_METHOD(insert_index_1)
		{
			list->push_back(1);
			list->push_back(2);
			list->insert(3, 1);
			Assert::AreEqual(list->at(1), 3); // Is the second element equals 3?
		}
		TEST_METHOD(insert_incorrect_index)
		{
			try
			{
				list->insert(10, -1);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("Index is greater than list size", e.what()); // Is index greater than list size?
			}
		}
		TEST_METHOD(at_correct_index)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			Assert::AreEqual(list->at(1), 2); // Is the second element equals 2?
		}
		TEST_METHOD(at_incorrect_index)
		{
			try
			{
				list->at(-1);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("Index is greater than list size", e.what()); // Is index greater than list size?
			}
		}
		TEST_METHOD(remove_list_with_1_elem)
		{
			list->push_back(1);
			list->remove(0);
			Assert::AreEqual(int(list->get_size()), 0); // Is there empty list?
		}
		TEST_METHOD(remove_list_with_2_elem_1)
		{
			list->push_back(1);
			list->push_back(2);
			list->remove(0);
			Assert::AreEqual(list->at(0), 2); // Is the first element equals 2?
		}
		TEST_METHOD(remove_list_with_2_elem_2)
		{
			list->push_back(1);
			list->push_back(2);
			list->remove(1);
			Assert::AreEqual(list->at(0), 1); // Is the first element equals 1?
		}
		TEST_METHOD(remove_list_with_5_elem)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->remove(2);
			Assert::AreEqual(list->at(2), 4);  // Is the third element equals 4?
		}
		TEST_METHOD(remove_incorrect_index)
		{
			try
			{
				list->remove(-1);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("Index is greater than list size", e.what()); // Is index greater than list size?
			}
		}
		TEST_METHOD(get_size_full)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->push_back(6);
			list->push_back(7);
			list->push_back(8);
			list->push_back(9);
			list->push_back(10);
			Assert::AreEqual(int(list->get_size()), 10); // Is the size equals 10?
		}
		TEST_METHOD(get_size_empty)
		{
			Assert::AreEqual(int(list->get_size()), 0); // Is there empty list?
		}
		TEST_METHOD(clear)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list->push_back(4);
			list->push_back(5);
			list->clear();
			Assert::AreEqual(int(list->get_size()), 0); // Is there empty list?
		}
		TEST_METHOD(set_eq)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list->set(1, 10);
			Assert::AreEqual(list->at(1), 10); // Is the second element equals 10?
		}
		TEST_METHOD(set_size)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list->set(1, 10);
			Assert::AreEqual(int(list->get_size()), 3); // Is the size equals 3?
		}
		TEST_METHOD(set_incorrect_index)
		{
			try
			{
				list->set(-1, 10);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("Index is greater than list size", e.what()); // Is index greater than list size?
			}
		}
		TEST_METHOD(isEmpty_false)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			Assert::IsFalse(list->isEmpty()); //  Isn't there empty list?
		}
		TEST_METHOD(isEmpty_true)
		{
			Assert::IsTrue(list->isEmpty()); //  Is there empty list?
		}
		TEST_METHOD(find_last_1)
		{
			list->push_back(1);
			list->push_back(1);
			list->push_back(1);
			list->push_back(1);
			list->push_back(1);
			list2->push_back(1);
			int a = list->find_last(list2);
			Assert::AreEqual(a, 4); // Is the answer 4?
		}
		TEST_METHOD(find_last_2)
		{
			list->push_back(1);
			list->push_back(1);
			list->push_back(1);
			list->push_back(1);
			list->push_back(1);
			list2->push_back(1);
			list2->push_back(2);
			size_t a = -1;
			int b = list->find_last(list2);
			Assert::AreEqual(b, int(a)); // Is the answer -1?
		}
		TEST_METHOD(find_last_3)
		{
			list->push_back(1);
			list->push_back(1);
			list->push_back(1);
			list->push_back(2);
			list->push_back(1);
			list2->push_back(1);
			list2->push_back(2);
			int b = list->find_last(list2);
			Assert::AreEqual(b, 2); // Is the answer 2?
		}
		TEST_METHOD(find_last_4)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(1);
			list->push_back(1);
			list->push_back(1);
			list->push_back(2);
			list2->push_back(1);
			list2->push_back(2);
			int b = list->find_last(list2);
			Assert::AreEqual(b, 4);
		}
		TEST_METHOD(find_last_5)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list2->push_back(1);
			list2->push_back(2);
			list2->push_back(3);
			int a = list->find_last(list2);
			Assert::AreEqual(a, 6); // Is the answer 6?
		}
		TEST_METHOD(find_last_6)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			list2->push_back(1);
			list2->push_back(2);
			list2->push_back(4);
			size_t a = -1;
			int b = list->find_last(list2);
			Assert::AreEqual(b, int(a)); // Is the answer -1?
		}
		TEST_METHOD(find_last_7)
		{
			list->push_back(1);
			list->push_back(2);
			list->push_back(2);
			list->push_back(2);
			list->push_back(2);
			list->push_back(2);
			list->push_back(2);
			list->push_back(2);
			list->push_back(2);
			list2->push_back(1);
			int a = list->find_last(list2);
			Assert::AreEqual(a, 0); // Is the answer 0?
		}
		TEST_METHOD(find_last_incorrect_size)
		{
			list->push_back(1);
			list2->push_back(1);
			list2->push_back(2);
			size_t a = -1;
			int b = list->find_last(list2);
			Assert::AreEqual(b, int(a)); // Is the answer -1?
		}
	};
}