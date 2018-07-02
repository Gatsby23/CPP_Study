// LeetCode 238
#include <iostream>
#include <vector>

using namespace std;


class Solution{
	public:
		// 时间复杂度 O(n)
		// 空间复杂度 O(n)
		void moveZeros(vector<int> &nums){
			vector<int> nonZeroElements;
			for(auto number : nums)
				if(number)
					nonZeroElements.push_back(number);

			for(int i = 0; i < nonZeroElements.size(); i++)
				nums[i] = nonZeroElements[i];

			for(int i = nonZeroElements.size(); i < nums.size(); i++)
				nums[i] = 0;
		}

		void moveZerosBetter(vector<int> &nums){
			int k = 0;		// 在nums, [0 ... k) 的元素均为非0元素
			
			// 遍历到第i个元素， 保证[0 ... i]中所有的非0元素
			// 都按照顺序排列在[0 ... k) 中
			for(int i = 0; i < nums.size(); i++)
				if(nums[i])
					nums[k++] = nums[i];

			// 将nums 剩余的位置放置为0
			for(int i = k; i < nums.size(); i++)
				nums[i] = 0;
		}

		void moveZerosBetter2(vector<int> &nums){
			for(int index = 0, current = 0; current < nums.size(); current++)

				if(nums[current]){
					if(current != index)
						swap(nums[index++], nums[current]);
					else
						index++;
				}
		}
};

int main()
{
	int arr[] = {0, 1, 0, 3, 12};
	vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
	
	Solution().moveZeros( vec );
	
	vector<int> vec_back(arr, arr + sizeof(arr)/sizeof(int));
	Solution().moveZerosBetter2(vec_back);
	for(auto number : vec_back)
		std::cout << number << " ";
	std::cout << std::endl;
	
	return 0;
}
