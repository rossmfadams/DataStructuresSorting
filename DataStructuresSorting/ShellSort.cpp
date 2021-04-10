/*  ShellSort.cpp--------------------------------------------------------------
	This file implements the Shell Sort algorithm
	@author Nancy Den - tutorialspoint.com
	contributed by Ross Adams
-----------------------------------------------------------------------------*/

#include<iostream>

using namespace std;

/*---------------------------------------------------------------------------*/

static void swapping(int& a, int& b) {        //swap the content of a and b
	int temp;
	temp = a;
	a = b;
	b = temp;
}

/*---------------------------------------------------------------------------*/

static void shellSort(int* arr, int n) {
	int gap, j, k;
	//initially gap = n/2,decreasing by gap / 2
	for (gap = n / 2; gap > 0; gap = gap / 2) { 
			for (j = gap; j < n; j++) {
				for (k = j - gap; k >= 0; k -= gap) {
					if (arr[k + gap] >= arr[k])
						break;
					else
						swapping(arr[k + gap], arr[k]);
				}
			}
	}
}
/*---------------------------------------------------------------------------*/