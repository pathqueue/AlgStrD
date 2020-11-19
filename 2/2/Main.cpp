#include <iostream>
#include <ctime>
#include "Sort.h"

using namespace std;

int main()
{
	int N = 10;
	int* arr, *arr2;
	clock_t start_time, end_time;
	double search_time1, search_time_mid1 = 0, search_time2, search_time_mid2 = 0;
	for (int i = 0; i < 5; i++)
	{
		cout << "N = " << N << '\n';
		cout << "               QS      BS\n";
		arr = new int[N];
		arr2 = new int[N];
		search_time_mid1 = 0;
		search_time_mid2 = 0;
		for (int j = 0; j < 10; j++)
		{
			cout << j + 1 << " lunch: ";
			if (j != 9) cout << ' ';
			Generate(arr, N);
			start_time = clock();
			QuickSort(arr, 0, N - 1);
			end_time = clock();
			search_time1 = double(end_time - start_time) * 1000 / double(CLOCKS_PER_SEC) ;
			cout.width(7);
			cout << search_time1 << ' ';
			search_time_mid1 += search_time1;
			Generate(arr2, N);
			start_time = clock();
			BubbleSort(arr2, N);
			end_time = clock();
			search_time2 = double(end_time - start_time) * 1000 / double(CLOCKS_PER_SEC);
			cout.width(7);
			cout << search_time2  << '\n';
			search_time_mid2 += search_time2;
		}
		search_time_mid1 /= 10;
		search_time_mid2 /= 10;
		
		cout << "Average   ";
		cout.width(7);
		cout << search_time_mid1 << ' ';
		cout.width(7);
		cout <<  search_time_mid2 << "\n\n";
		N *= 10;
		delete[] arr;
		delete[] arr2;
	}
	system("pause");
	return 0;
}