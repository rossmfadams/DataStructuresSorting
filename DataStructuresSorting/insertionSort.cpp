/*--insertionSort.cpp------------------------------------------------------------
    This file implements the Insertion sort algorithm
    @author Nancy Den on tutorialspoint.com
    contributed by Caitlyn Phan
-----------------------------------------------------------------------------*/

#include<iostream>

using namespace std;

static void insertionSort(int *array, int size) {
   int key, j;
   for(int i = 1; i<size; i++) {
      key = array[i];//take value
      j = i;
      while(j > 0 && array[j-1]>key) {
         array[j] = array[j-1];
         j--;
      }
      array[j] = key;   //insert in right place
   }
}

