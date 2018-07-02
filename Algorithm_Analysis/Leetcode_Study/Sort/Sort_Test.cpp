#include <iostream>
#include "SortTestHelper.h"
#include "Sort_Algorithm.h"

using namespace Sort_Algorithm;

int main()
{
	int n = 10000;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n-1);
	SortTestHelper::testSort("Insertion Sort", Insertion_Sort,arr, n);
	SortTestHelper::testSort("The better way of insertion sort", Insertion_Sort_Better, arr, n);
	SortTestHelper::testSort("Selection Sort", Selection_Sort, arr, n);
	
	SortTestHelper::testSort("Merge Sort", mergeSort, arr, n);
}
