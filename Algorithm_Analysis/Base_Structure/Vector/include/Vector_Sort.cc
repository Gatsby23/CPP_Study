#include <iostream>
#include <vector>

using namespace std;

typedef int Rank;

template<typename T>
void bubbleSort(T a[], Rank lo, Rank hi){
	while(!bubble(lo, hi--));
}

template<typename T> 
bool bubble(Rank lo, Rank hi){	// 扫描交换
	bool sorted = true;
	while(++lo < hi){
		if(_elem[lo - 1] > _elem[lo]){
			sorted = false;
			swap(_elem[lo-1], _elem[lo]);
		}
	}
	return sorted;
}

int main()
{
	int num_a[] = {1, 2, 3, 4, 5, 6, 7};
	for (auto num : num_a)
		cout << num << "\t";
	cout << endl;

	bubbleSort(num_a, 0, 6);

	for(auto num: num_a)
		cout << num << "\t";
	cout << endl;
}
