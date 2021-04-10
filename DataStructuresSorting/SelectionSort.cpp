/*--SectionSort.cpp------------------------------------------------------------
	This file implements the Selection sort algorithm
	@author Krantik Chavan on tutorialspoint.com
	contributed by Ross Adams
-----------------------------------------------------------------------------*/
#include<iostream>

using namespace std;

/*---------------------------------------------------------------------------*/

static void swap(int& a, int& b) {         //swap the content of a and b
	int temp;
	temp = a;
	a = b;
	b = temp;
}

/*---------------------------------------------------------------------------*/

static void selectionSort(int* array, int size) {
	int i, j, imin;
	for (i = 0; i < size - 1; i++) {
		imin = i;   //get index of minimum data
		for (j = i + 1; j < size; j++)
			if (array[j] < array[imin])
				imin = j;
		//placing in correct position
		swap(array[i], array[imin]);
	}
}
/*---------------------------------------------------------------------------*/
