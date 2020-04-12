#include"sort.h"
#include<iostream>

// Defines Maximum size of the array. If you change this value, 
// please make sure that main.cpp has same constant and same value is reflected there.
const int MAX_SIZE = 1000;

using namespace std;

SORT::SORT()
{
}

void SORT::Swap(int &num1, int &num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int SORT::Partition(int aray[], int low, int high)
{
	int pivot = aray[high];
	int index = low-1;

	for (int i = low; i <= high; i++)
	{
		if (aray[i] < pivot)
		{
			++index;
			swap(aray[index], aray[i]);			
		}
	}
	swap(aray[index+1], aray[high]);

	return (++index);
}

void SORT::QuickSort(int aray[], int low, int high)
{
	if (low < high)
	{
		int pivot = Partition(aray, low, high);
		QuickSort(aray, low, pivot - 1);
		QuickSort(aray, pivot + 1, high);
	}
}

void SORT::Merge(int aray[], int low, int mid, int high)
{
	int tempLow, tempMid, tempAray[MAX_SIZE], count;
	tempLow = low;
	tempMid = mid + 1;
	count = low;

	for (int i = low; i <= high; i++)
	{
		if (tempLow > mid)
			tempAray[count++] = aray[tempMid++];
		else if (tempMid > high)
			tempAray[count++] = aray[tempLow++];
		else if (aray[tempMid] < aray[tempLow])
			tempAray[count++] = aray[tempMid++];
		else
			tempAray[count++] = aray[tempLow++];
	}

	for (int i = low; i <= high; i++)
		aray[i] = tempAray[i];
}

void SORT::MergeSort(int aray[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(aray, low, mid);
		MergeSort(aray, mid+1, high);
		Merge(aray, low, mid, high);
	}
}

void SORT::Print(int aray[], int araySize)
{
	for (int i = 0; i <= araySize; i++)
		cout << aray[i] << " ";
	cout << endl;
}
