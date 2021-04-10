/*  MergeSort.cpp--------------------------------------------------------------
	This file implements the merge sort algorithm
	@author Krantik Chavan
	contributed by Ross Adams v 1.1
-----------------------------------------------------------------------------*/

#include<iostream>

using namespace std;

static void merge(int* array, int l, int m, int r) {
	
	int i, j, k, nl, nr;
	
	//size of left and right sub-arrays
	nl = m - l + 1; 
	nr = r - m;
	
	int* larr = new int[nl];  // Modified to dynamically allocate memory
	int* rarr = new int[nr];  // Modified to dynamically allocate memory
	
	//fill left and right sub-arrays
	for (i = 0; i < nl; i++)
		larr[i] = array[l + i];
	for (j = 0; j < nr; j++)
		rarr[j] = array[m + 1 + j];
	i = 0; j = 0; k = l;
	
	//merge temp arrays to real array
	while (i < nl && j < nr) {
		if (larr[i] <= rarr[j]) {
			array[k] = larr[i];
			i++;
		}
		else {
			array[k] = rarr[j];
			j++;
		}
		k++;
	}
	while (i < nl) {       //extra element in left array
		array[k] = larr[i];
		i++; k++;
	}
	while (j < nr) {     //extra element in right array
		array[k] = rarr[j];
		j++; k++;
	}

	delete[] larr, rarr;
}
static void mergeSort(int* array, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		// Sort first and second array
		mergeSort(array, l, m);
		mergeSort(array, m + 1, r);
		merge(array, l, m, r);
	}
}