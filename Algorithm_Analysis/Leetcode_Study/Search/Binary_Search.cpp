/* class Solution{
	public:
		// The While Loop Form
		vector<int>::iterator Binary_Search(vector<int> Sorted_Vector, int target){
			vector<int> iterator left = Sorted_Vector.begin();
			vector<int> iterator right = Sorted_Vector.end();
			
			int ret = -1;
			int mid;

			// set lower_bound
			while(left < right){
				mid = left + (right - left) / 2;
				if(*mid < x){
					left = mid + 1;
				}
				else if(*mid > x){
					right = mid - 1;
				}
				else{
					ret = mid;
					break;
				}
			}
		return ret;
		}

		// The Recursive Form
		
		int binary_Search(const int arr[], int start, int end, int khey){
			if(start > end)
				return -1;
			
			int mid = start + (end - start) / 2;
			if(arr[mid] > khey)
				return binary_Search(arr, start, mid - 1, khey);
			else if(arr[mid] < khey)
				return binary_Search(arr, mid + 1, end, khey); 
			else
				return mid;
		}
};*/

/*
Class Solution{
	public:
		
		 * @param nums: The integer array.
		 * @param targets: Target number to find.
		 * @return: The first position of target. Position starts from 0.
		 * 

		int Binary_Search(vector<int> &nums, int target){
			if(nums.size() == 0) return -1;

			int lo = 0, hi = nums.size();
			while(lo < hi){
				int mi = lo + (hi - lo) / 2;
				if(nums[mi] < target)
					lo = mi + 1;
				else
					hi = mi;
			}
			
			if(nums[lo] == target) return lo;
			return -1;
		}
};*/

class Soultion{
	public:
		vector<int> searchRange(vector<int>&nums, int target){
			vector<int> result{-1, -1};
			// 考虑数组中只有零个或一个元素
			if(nums.size() == 0) return result;
			if(nums.size() == 1){
				if(nums[0] == target){
					result.clear();
					result.push_back(0);
					return result;
				}
				else{
					return result;
				}
			}

			// 考虑不止零或一个的情况
			int left = 0, right = nums.size() - 1;
			int mid = left + (right - left) / 2;
			while(left > right){
				mid = left + (right - left) / 2;
				
				// low bound module:
				if(nums[mid] > target)
					right = mid - 1;
				else if (nums[mid] < target)
					left = mid;
				else{
					result.clear();
					result.push_back(mid);
					break;
				}
			}

			while(nums[mid] == target){
				mid++;
			}
			result.push_back(mid);
			return result;
		}
};
