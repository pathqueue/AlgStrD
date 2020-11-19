#include "CppUnitTest.h"
#include "../2/Sort.h"

const int N = 10;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:	
		int* arr;
		char* arrchar;
		TEST_METHOD_INITIALIZE(setUp)
		{
			arr = new int[N];
			Generate(arr, N);
		}
		TEST_METHOD_CLEANUP(cleanUp)
		{
			delete[] arr;
		}
		TEST_METHOD(Check_Arr_True)
		{
			int addarr[N];
			for (int i = 0; i < N; i++)
			{
				addarr[i] = i + 10;       // Array = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19}
			}
			Assert::IsTrue(Check(addarr, N)); // Check sorted array
		}
		TEST_METHOD(Check_Arr_False)
		{
			char addarr[N];
			for (int i = 0; i < N; i++)
			{
				addarr[i] = i + 10;       // Array = { !, ", #, $, %, &, ', (, ), *}
			}
			addarr[0] = 20; // First elem = 20, array = { 20, 11, 12, 13, 14, 15, 16, 17, 18, 19}
			Assert::IsFalse(Check(addarr, N)); // Check not sorted array
		}
		TEST_METHOD(Check_Arr_Same_Elem)
		{
			int addarr[N];
			for (int i = 0; i < N; i++)
			{
				addarr[i] = 5;			   // Array = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}
			}
			Assert::IsTrue(Check(addarr, N)); // Check sorted array
		}
		TEST_METHOD(Check_Char_Arr_True)
		{
			char addarr[N];
			for (int i = 0; i < N; i++)
			{
				addarr[i] = i + 10;       // Array = { !, ", #, $, %, &, ', (, ), *}
			}
			Assert::IsTrue(Check(addarr, N)); // Check sorted array
		}
		TEST_METHOD(Check_Char_Arr_False)
		{
			char addarr[N];
			for (int i = 0; i < N; i++)
			{
				addarr[i] = i + 33;       // Array = { !, ", #, $, %, &, ', (, ), *}
			}
			addarr[0] = 43; // First elem = +, array = { +, ", #, $, %, &, ', (, ), *}
			Assert::IsFalse(Check(addarr, N)); // Check not sorted array
		}
		TEST_METHOD(Check_Char_Arr_Same_Elem)
		{
			char addarr[N];
			for (int i = 0; i < N; i++)
			{
				addarr[i] = 33;       // Array = { !, !, !, !, !, !, !, !, !, !}
			}
			Assert::IsTrue(Check(addarr, N)); // Check sorted array
		}
		TEST_METHOD(Binary_Search)
		{
			int addarr[N];
			for (int i = 0; i < N; i++)
			{
				addarr[i] = i + 10;      // Array = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 }
			}
			int a = BinarySearch(addarr, 0, N, 15);
			Assert::AreEqual(a, 5); // Is the 6th elem equals 15? 
		}
		TEST_METHOD(Binary_Search_False)
		{
			int addarr[N];
			for (int i = 0; i < N; i++)
			{
				addarr[i] = i + 10;       // Array = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19}
			}
			int a = BinarySearch(addarr, 0, N, 20);
			Assert::AreEqual(a, -1); // Is there no 20 in array?
		}
		TEST_METHOD(Quick_Sort)
		{
			QuickSort(arr, 0, N - 1);
			Assert::IsTrue(Check(arr, N)); // Check sorted array
		}
		TEST_METHOD(Quick_Sort_Same_Elem)
		{
			int addarr[N];
			for (int i = 0; i < N; i++)
			{
				addarr[i] = 5;             // Array = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}
			}
			QuickSort(addarr, 0, N - 1);
			Assert::IsTrue(Check(addarr, N)); // Check sorted array
		}
		TEST_METHOD(Bubble_Sort)
		{
			BubbleSort(arr, N);
			Assert::IsTrue(Check(arr, N)); // Check sorted array
		}
		TEST_METHOD(Bubble_Sort_Same_Elem)
		{
			int addarr[N];
			for (int i = 0; i < N; i++)
			{
				addarr[i] = 5;        // Array = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}
			}
			BubbleSort(addarr, N);
			Assert::IsTrue(Check(addarr, N)); // Check sorted array
		}
		TEST_METHOD(Bogo_Sort)
		{
			BogoSort(arr, N);
			Assert::IsTrue(Check(arr, N)); // Check sorted array
		}
		TEST_METHOD(Counting_Sort)
		{
			arrchar = new char[N];
			Generate(arrchar, N);
			CountingSort(arrchar, N);
			Assert::IsTrue(Check(arrchar, N)); // Check sorted array
			delete[] arrchar;
		}
		TEST_METHOD(Counting_Sort_Same_Elem)
		{
			char addarr[N];
			for (int i = 0; i < N; i++)
			{
				addarr[i] = 33;             // Array = { !, !, !, !, !, !, !, !, !, !}
			}
			CountingSort(addarr, N);
			Assert::IsTrue(Check(addarr, N)); // Check sorted array
		}
	};
}
