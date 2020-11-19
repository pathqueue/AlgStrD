#include <iostream>
#include <cstdlib>
#include <ctime>

void Generate(int arr[], int N)
{
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand();
	}
}

void Generate(char arr[], int N)
{
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 95 + 32;
	}
}

bool Check(int arr[], int N)
{
	for (int i = 1; i < N; i++)
	{
		if (arr[i] < arr[i - 1]) return 0;
	}
	return 1;
}

bool Check(char arr[], int N)
{
	for (int i = 1; i < N; i++)
	{
		if (arr[i] < arr[i - 1]) return 0;
	}
	return 1;
}

int BinarySearch(int arr[], int left, int right, int key)
{
	int mid = 0;
	while (1)
	{
		mid = (left + right) / 2;
		if (key < arr[mid]) right = mid - 1;      
		else if (key > arr[mid]) left = mid + 1;    
		else return mid;          
		if (left > right) return -1;
	}
}

int Partition(int Arr[], int left, int right)
{
	int pivot = Arr[right];
	int i = left - 1;
	for (int j = left; j <= right - 1; j++)
	{
		if (Arr[j] <= pivot)
		{
			i++;
			std::swap(Arr[i], Arr[j]);
		}
	}
	std::swap(Arr[i + 1], Arr[right]);
	return (i + 1);
}

void QuickSort(int Arr[], int left, int right)
{
	int pi;
	if (left < right)
	{
		pi = Partition(Arr, left, right);
		QuickSort(Arr, left, pi - 1);
		QuickSort(Arr, pi + 1, right);
	}
}

void BubbleSort(int Arr[], int N)
{ 
	int temp;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = temp;
			}
		}
	}
}

void BogoSort(int Arr[], int N)
{
	srand(time(NULL));
	while (!Check(Arr, N))
		for (int i = 0; i < N; i++)
			std::swap(Arr[i], Arr[rand() % N]);
}

int FindMax(char Arr[], int N)
{
	int Max = 0;
	for (int i = 0; i < N; i++)
	{
		if (Max < Arr [i]) Max = Arr [i];
	}
	return Max;
}

void CountingSort(char Arr[], int N) 
{
	int i;
	int Max = FindMax(Arr, N);
	int* tempArr = new int[Max];
	for (i = 0; i < Max + 1; i++)
	{
		tempArr[i] = 0;
	}
	for (i = 0; i < N; i++) 
	{
		tempArr[Arr[i]] = tempArr[Arr[i]] + 1;
	}
	i = 0;
	for (int j = 0; i < N; j++) {
		while (tempArr[j] != 0)
		{
			Arr[i] = j;
			tempArr[j]--;
			i++;
		}
	}
}

