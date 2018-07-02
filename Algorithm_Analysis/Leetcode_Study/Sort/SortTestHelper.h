#ifndef SELECTIONSORT_SORTTESTHELPER_H
#define SELECTIONSORT_SORTTESTHELPER_H
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper{
	// 生成n个元素的随机数组,每个数组的随机范围为[rangeL, rangeR]
	int *generateRandomArray(int n, int rangeL, int rangeR){
		int * arr = new int[n];

		srand(time(NULL));
		for(int i = 0; i < n; i++)
			arr[i] = rand() % ( rangeR - rangeL + 1 ) + rangeL; // 标准随机数生成方式
		return arr;
	}

	int *generateNearlyOrderedArray(int n, int swapTimes){
		int *arr = new int[n];
		for(int i = 0; i < n; i++)
			arr[i] = i;

		srand(time(NULL));
		for(int i = 0; i < swapTimes; i++){
			int posx = rand()%n;
			int posy = rand()%n;
			swap(arr[posx], arr[posy]);
		}
		return arr;
	}

	template<typename T>
	bool isSorted(T arr[], int n ){
		for(int i = 0; i < n - 1; i++){
			if(arr[i] > arr[i+1])
				return false;
		}
		return true;
	}

	template<typename T>
	void testSort(string sortName, void(*sort)(T[], int), T arr[], int n){
		
		// 性能计算
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		
		// 运行时间计算
		assert( isSorted(arr, n) );
		std::cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << std::endl;
	}
}
#endif
