#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>

namespace MyUtil{
	int *generateOrderedArray(int n){
			assert(n > 0);
			int *arr = new int[n];

			for(int i = 0; i < n; i++)
				arr[i] = i;
			return arr;
		}
}

template<typename T>
int binarySearch(T arr[], int n, T target){
	int l = 0, r = n - 1;			// 在[l ... r]的范围内寻找target
	
	while(l <= r){					// 当 l == r 时, 区间[l ... r]依然是有效的
		int mid = l + (r - l) / 2;
		if(target == arr[mid])
			return mid;

		if(target > arr[mid])		
			l = mid + 1;			// target 在[mid+1 ... r]中
		else
			r = mid - 1;			// target 在[l ... mid-1]中
	}
	return -1;
}

int main()
{
	int n = 1000000;
	int *data = MyUtil::generateOrderedArray(n);
	clock_t startTime = clock();
	for(int i = 0; i < n; i++)
		assert(i == binarySearch(data, n, i));
	clock_t endTime = clock();

	std::cout << "binarySearch test Complete " << std::endl;
	std::cout << "Time Cost: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << std::endl;
	return 0;
}
