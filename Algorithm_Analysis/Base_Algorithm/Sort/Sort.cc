#include <iostream>
#include <vector>

typedef int Rank;
using namespace std;

template<typename T>
bool bubble(T num[], Rank lo, Rank hi){
	bool sorted = true;
	while(++lo < hi){
		if(num[lo-1] < num[lo]){
			sorted = false;
			T temp = num[lo-1];
			num[lo-1] = num[lo];
			num[lo] = temp;
		}
	}
	return sorted;
}

template<typename T>
void bubbleSort(T num[], Rank lo, Rank hi){
	while(!bubble(num, lo, hi));
}

int main()
{
	int num_int[] = {1, 3, 54, 23, 2, 4, 5, 6, 2, 5, 6, 2, 5, 76, 2};

	cout << "Before Sorted, the number array is: ";
	for(auto num : num_int){
		cout << num << ", ";
	}
	cout << endl;

	bubbleSort(num_int, 0, sizeof(num_int)/sizeof(num_int[0]));

	cout << "After Sort, the number array is: ";
	for(auto num : num_int){
		cout << num << ", ";
	}
	cout << endl;
}
