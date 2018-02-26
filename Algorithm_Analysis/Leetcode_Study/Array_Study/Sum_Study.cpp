// 1. Two Sum
// 这里主要采用的是hash map的方法, map的key对应的数组中的值,value对应的是数组中的位置
/*
class Solution{
	public:
		vector<int> twoSum(vector<int> &numbers, int target){
			unordered_map<int, int> m;
			vector<int> result;
			for(int i = 0; i < numbers.size(); i++){
				// not found the second one
				if(m.find(numbers[i]) == m.end())
					// store the first one position into the second one's key
					m[target - numbers[i]] = i;
				else{
					// found the second one
					result.push_back(m[numbers[i]] + 1);
					result.push_back(i+1);
					break;
				}	
			}
			return result;
		}
};
*/

// 3sum 
/*
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int> &num){
	vector<vector<int> > result;
	if(num.size() == 0 || num.size() == 1 || num.size() == 2) return result;

	// sort the array, this is the key
	sort(num.begin(), num.end());

	int n = num.size();

	for(int i = 0; i < n - 2; i++){
		// skip the duplication
		if(i > 0 && num[i-1] == num[i]) continue;
		int a = num[i];
		int low = i + 1;
		int high = n - 1;
		while(low < high){
			int b = num[low];
			int c = num[high];
			if(a+b+c == 0){
				// got the solution
				vector<int> v;
				v.push_back(a);
				v.push_back(b);
				v.push_back(c);
				result.push_back(v);
				// Continue search for all triplet combinations summing to zero.
				// skip the duplication
				while(low < n-1 && num[low] == num[low+1]) low++;
				while(high > 0 && num[high] == num[high-1]) high--;
				low++;
				high--;
			}else if(a+b+c > 0){
				// skip the duplication
				while(high > 0 && num[high] == num[high-1]) high--;
				high--;
			}else{
				// skip the duplication
				while(low < n-1 && num[low] == num[low+1]) low++;
				low++;
			}
		}
	}
	return result;
};

void printMatrix(vector<vector<int> > &matrix){
	for(int i = 0; i < matrix.size(); i++){
		printf("{");
		for(int j = 0; j < matrix[i].size(); j++)
			printf("%3d", matrix[i][j]);
		printf("}\n");
	}
	cout << endl;
}

int main()
{
	int a[] = {-1, 1, 1, 1, -1, -1, 0, 0, 0};
	vector<int> n(a, a+sizeof(a)/sizeof(int));
	vector<vector<int> > result = threeSum(n);
	printMatrix(result);
	return 0;
}*/


// 3SumClosest.cpp
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//#define INT_MAX 21474837=647

int threeSumCloset(vector<int> &num, int target){
	// sort the array
	sort(num.begin(), num.end());

	int n = num.size();
	int distance = INT_MAX;
	int result;

	for(int i = 0; i < n-2; i++){
		// skip the duplication
		if(i > 0 && num[i-1]==num[i]) continue;
		int a = num[i];
		int low = i+1;
		int high = n-1;
		// convert the 3sum to the 2sum problem
		while(low < high){
			int b = num[low];
			int c = num[high];
			int sum = a+b+c;
			if(sum - target == 0){
				// got the final solution
				return target;
			}else{
				// tracking the minmal distance
				if( abs(sum-target) < distance ){
					distance = abs(sum - target);
					result = sum;
				}

				if(sum - target > 0){
					// skip the duplication
					while(high > 0 && num[high] == num[high-1]) high--;
					//move the 'high' pointer
					high--;
				}else{
					// skip the duplication
					while(low < n && num[low] == num[low+1] ) low++;
					// move the 'low' pointer
					low++;
				}
			}
		}
	}

	return result;
}

int main()
{
	int a[] = {-1, 2, 1, -4};
	vector<int> n(a, a+sizeof(a)/sizeof(int));
	int target = 1;
	cout << threeSumCloset(n, target) << endl;
	return 0;
}
