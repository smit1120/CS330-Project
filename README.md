# CS330-Assignment5
 **Name:**          Smit .J. Patel
 **Student No.:**   200415740
 **Course:**        CS330-Introduction To Operating Systems

## Topic
  This is a small project on sorting using multiple threads. It implements Merge Sort and Quick Sort algorithms, both with O(nlogn) time complexity. However, Merge Sort algorithm tends to perform slightly better than the Quick Sort if array is very large. 

  This project does not integrate multi-threading in the sorting algorithms, rather it uses a simple approach of dividing the list and sorting them seperaterly by assigning each of divided part to the individual threads. Suppose there are n threads available, then the list of numbers is divided into n equal parts (so that each thread gets equal amount of work to perform) and assinged to n available threads seperately. These threads then performs sorting on assigned part of the list with prefered algorithm. Once every thread has finished sorting, the parent thread is used to Merge the seperated list. This program creates two threads to perform the multi-threaded sorting.

### Input & Output
  The program asks user for the size of array and number of runs to perform. 

  It initialises the array randomly and creates 3 identical copies of the array for 3 sorting methods (Merge Sort, Quick Sort and Sorting using multiple threads) to keep reasults fair. 

  This program will produce output of amount of time taken by all 3 methods to perfrom the sorting. 

### sort.h and sort.cpp
  This files contains defination and implementation of Merge Sort and Quick Sort algorithms. 

### main.cpp
  Main function does all the work of assigning arrays, creating multiple threads and calculating time taken to perform the sorting.