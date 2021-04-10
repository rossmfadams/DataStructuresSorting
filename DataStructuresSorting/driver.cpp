/*--driver.cpp-----------------------------------------------------------------
	This program sorts a data set of 5000 unique integers from an input file
	using 5 different sorting algorithms and tracks the time taken for each
	algorithm for comparison.
	
	@authors Ross Adams, Caitlyn Phan, and Justin Krikorian
-----------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <Bits.h>
#include "SelectionSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"
#include "ShellSort.cpp"
#include "insertionSort.cpp"

using namespace std;
using namespace std::chrono;

bool compareTo(int* a, int* b, int size) {
	bool result = true;
	int i = 0;
	for (i = 0; i < size && result == true; i++) {
		if (a[i] != b[i]) {
			result = false;
		}
	}

	return result;
}

int main()
{
	// Declare and instatiate variables
	const int CAPACITY = 5000;
	int* sorted = new int[CAPACITY];
	int* unsorted = new int[CAPACITY];
	int* toSelectionSort = new int[CAPACITY];
	int* toInsertionSort = new int[CAPACITY];
	int* toMergeSort = new int[CAPACITY];
	int* toQuickSort = new int[CAPACITY];
	int* toShellSort = new int[CAPACITY];
	int i = 0;
	bool res = false;
	fstream in_file("dataSet.txt", ios::in);

	//Test for file opening
	if (!in_file)
	{
		cout << "Cannot open words1.txt for reading" << endl;
		return 0;
	}

	// Read data from file into an array
	for (i = 0; i < CAPACITY; i++) {
		in_file >> unsorted[i];
	}

	in_file.close();

	// Copy unsorted array
	for (i = 0; i < CAPACITY; i++) {
		toSelectionSort[i] = unsorted[i];
		toInsertionSort[i] = unsorted[i];
		toMergeSort[i] = unsorted[i];
		toQuickSort[i] = unsorted[i];
		toShellSort[i] = unsorted[i];
	}

	// Create Sorted array
	for (i = 0; i < CAPACITY; i++) {
		sorted[i] = i + 1;
	}

	/*---------------Selection Sort---------------*/

	// Get starting timepoint 
	auto start = chrono::high_resolution_clock::now();
	
	ios_base::sync_with_stdio(false);

	selectionSort(toSelectionSort, CAPACITY);

	// Get ending timepoint 
	auto stop = chrono::high_resolution_clock::now();

	// Get duration.
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

	// Test if sorted
	res = compareTo(sorted, toSelectionSort, CAPACITY);

	if (res == true) {
		cout << "Selection Sort was successful!" << endl;
	}
	else if (res == false) {
		cerr << "Selection Sort failed." << endl;
	}

	cout << "Time taken by Selection Sort: "
		<< duration.count() << " microseconds" << endl;
	
	/*---------------Insertion Sort---------------*/

	// Get starting timepoint 
	start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);

	insertionSort(toInsertionSort,CAPACITY);

	// Get ending timepoint 
	stop = chrono::high_resolution_clock::now();

	// Get duration.
	duration = chrono::duration_cast<chrono::microseconds>(stop - start);

	// Test if sorted
	res = compareTo(sorted, toInsertionSort, CAPACITY);

	if (res == true) {
		cout << "Insertion Sort was successful!" << endl;
	}
	else if (res == false) {
		cerr << "Insertion Sort failed." << endl;
	}

	cout << "Time taken by Insertion Sort: "
		<< duration.count() << " microseconds" << endl;
	
	/*---------------Merge Sort---------------*/

	// Get starting timepoint 
	start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	
	// Parameters: array pointer, left index, right index
	mergeSort(toMergeSort,0,CAPACITY-1);

	// Get ending timepoint 
	stop = chrono::high_resolution_clock::now();

	// Get duration.
	duration = chrono::duration_cast<chrono::microseconds>(stop - start);

	// Test if sorted
	res = compareTo(sorted, toMergeSort, CAPACITY);

	if (res == true) {
		cout << "Merge Sort was successful!" << endl;
	}
	else if (res == false) {
		cerr << "Merge Sort failed." << endl;
	}
	cout << "Time taken by Merge Sort: "
		<< duration.count() << " microseconds" << endl;
	
	/*---------------Quick Sort---------------*/
	// Get starting timepoint 
	start = chrono::high_resolution_clock::now();
	
	ios_base::sync_with_stdio(false);

	// Parameters: array pointer, left index, right index
	quickSort(toQuickSort,0,CAPACITY-1);

	// Get ending timepoint 
	stop = chrono::high_resolution_clock::now();

	// Get duration.
	duration = chrono::duration_cast<chrono::microseconds>(stop - start);

	// Test if sorted
	res = compareTo(sorted, toQuickSort, CAPACITY);

	if (res == true) {
		cout << "Quick Sort was successful!" << endl;
	}
	else if (res == false) {
		cerr << "Quick Sort failed." << endl;
	}
	cout << "Time taken by Quick Sort: "
		<< duration.count() << " microseconds" << endl;
	
	/*---------------Shell Sort---------------*/
	// Get starting timepoint 
	start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);

	shellSort(toShellSort,CAPACITY);

	// Get ending timepoint 
	stop = chrono::high_resolution_clock::now();

	// Get duration.
	duration = chrono::duration_cast<chrono::microseconds>(stop - start);

	// Test if sorted
	res = compareTo(sorted, toShellSort, CAPACITY);

	if (res == true) {
		cout << "Shell Sort was successful!" << endl;
	}
	else if (res == false) {
		cerr << "Shell Sort failed." << endl;
	}
	cout << "Time taken by Shell Sort: "
		<< duration.count() << " microseconds" << endl;
	
	// Clean up memory
	delete[] sorted, unsorted, toSelectionSort, toInsertionSort,
		toMergeSort, toQuickSort, toShellSort;

	return 0;
}