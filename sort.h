#ifndef SORT_H
#define SORT_H

using namespace std;

class SORT
{
private:
	/*
	Purpose: Swap two integers
	Parameter(s): 
		<1> num1: First integer
		<2> num2: Second integer
	Returns: void
	*/
	void Swap(int &num1, int &num2);

	/*
	Helper function for QuickSort

	Purpose: Partition the array for QuickSort
	Parameter(s):
		<1> aray: Original Array
		<2> low: Starting index of the array
		<3> high: Ending index of the array
	Returns: integer- Index of the Pivot of the array
	*/
	int Partition(int aray[], int low, int high);
	

public:
	/*
	Default Constructor

	Purpose: Create object of the class SORT
	Parameter(s): N/A
	Returns: N/A
	*/
	SORT();

	
	/*
	Purpose: Sorts the given array using MergeSort Algorithm
	Parameter(s):
		<1> aray: Original Array
		<2> low: Starting index of the array
		<3> high: Ending index of the array
	Returns: N/A
	*/
	void MergeSort(int aray[], int low, int high);

	
	/*
	Purpose: Sorts the given array using QuickSort Algorithm
	Parameter(s):
		<1> aray: Original Array
		<2> low: Starting index of the array
		<3> high: Ending index of the array
	Returns: N/A
	*/
	void QuickSort(int aray[], int low, int high);

	/*
	Helper function for Merge

	Purpose: Sort and Merge the divided array 
	Parameter(s):
		<1> aray: Original Array
		<2> low: Starting index of the array
		<3> mid: Index from which the array was divided
		<4> high: Ending index of the array
	Returns: N/A
	*/
	void Merge(int aray[], int low, int mid, int high);

	/*
	Purpose: Prints the given array
	Parameter(s):
		<1> aray: Original Array
		<2> araySize: last index of the array
	Returns: N/A
	*/
	void Print(int aray[], int araySize);
};
#endif