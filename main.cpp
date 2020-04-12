/*
	This program compares Quick Sort and Merge Sort algorithms.
	Also, implement Multi-threading on those algorithms
	and check the time difference.

	*[This program requires compiler that supports C++11 or later. 
	  For windows PC, you may use Visual Studio to run it or other similar applications.
	  For linux PC, a Makefile is provided which will compile and create executable named "demo".]
*/

#include<iostream>
#include<cstdlib>
#include<chrono>
#include<iomanip>
#include<thread>
#include"sort.h"

using namespace std;

// Defines Maximum size of the array. If you change this value, 
// please make sure that sort.cpp has same constant and same value is reflected there.
const int MAX_SIZE = 1000;

// Shared Global array variable used for Multithreaded Sorting 
int multithreadAray[MAX_SIZE];

/*
	Purpose: Sorts the given array using Multiple threads
	Parameter(s):
		<1> low: Starting index of the array
		<2> high: Ending index of the array
	Returns: N/A
*/
void Multithread(int low, int high);

int main()
{
	/*
		size: Defines size of the array
		runs: Number of times all sorting algorithms should run
		aray[], aray1[]: This are copies used by Merge Sort and Quick Sort Algorithm
	*/
	int size, runs, aray[MAX_SIZE], aray1[MAX_SIZE];
	cout << "Please Enter the size of array (MAX 1000): ";
	cin >> size;
	cout << "\nPlease Enter the number of runs: ";
	cin >> runs;
	cout << endl;

	int tempRuns = runs;
	
	// Three objects that calculates total time taken by each algorithms
	std::chrono::duration<double> totalTime(0.0), totalTime1(0.0), totalTime2(0.0);

	// instance of SORT class
	SORT obj;
	
	while (tempRuns--)
	{
		srand(time(0));

		// All copies of array are identical and intialized by random positive integers 
		for (int i = 0; i < size; i++)
		{
			aray[i] = rand() % 1000;
			aray1[i] = aray[i];
			multithreadAray[i] = aray[i];
		}

		auto start = chrono::high_resolution_clock::now();
		obj.MergeSort(aray, 0, size - 1);
		auto stop = chrono::high_resolution_clock::now();
		totalTime += (stop - start);

		start = chrono::high_resolution_clock::now();
		obj.QuickSort(aray1, 0, size - 1);
		stop = chrono::high_resolution_clock::now();
		totalTime1 += (stop - start);

		start = chrono::high_resolution_clock::now();
		Multithread(0, size - 1);
		stop = chrono::high_resolution_clock::now();
		totalTime2 += (stop - start);
	
	}

	cout << fixed <<setprecision(7);
	cout << endl << setw(21) << left << "| Method" <<  "| Time taken for         " << "| Avgerage             |" << endl;
	cout << setw(21) << "|" << setw(6) << "|   " << setw(7) << runs <<" run(s)     " << "| time taken           |" << endl;
	cout << "|____________________|________________________|______________________|" << endl;
	cout << "| Merge Sort         |" << setw(22) << totalTime.count() << "s |" << setw(20) << static_cast<double>(totalTime.count() / runs) << "s |" << endl;
	cout << "| Quick Sort         |" << setw(22) << totalTime1.count() << "s |" << setw(20) << static_cast<double>(totalTime1.count() / runs) << "s |" << endl;
	cout << "| Multithreaded Sort |" << setw(22) << totalTime2.count() << "s |" << setw(20) << static_cast<double>(totalTime2.count() / runs) << "s |" << endl;
	cout << endl;
	return 0;
}

void Multithread(int low, int high)
{
	/*
		Sorting Using two threads.
		Divided array into two equal parts,	assign each part to each thread. 
		Sort the divided array individually using Quick Sort or Merge Sort. 
		Wait for threads to finish and ask parent thread to run Merge function to Merge the divided array.
	*/

	int mid = low + ((high - low) / 2);
	SORT *objPtr = new SORT();

	//These threads use Quick sort to sort their list, If you want to use
	//Merge sort, change the first parameter to "&SORT::MergeSort".
	thread t1(&SORT::QuickSort, objPtr, multithreadAray, low, mid);
	thread t2(&SORT::MergeSort, objPtr, multithreadAray, mid+1, high);

	t1.join();
	t2.join();

	objPtr->Merge(multithreadAray, low, mid, high);
}