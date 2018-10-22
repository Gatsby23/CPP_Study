template<typename T>
void binarySearch(T arr[], int n, T target){
	int left = 0, right = n-1;
	while(left <= right){
		int mid = left + (right-left) / 2;
		
		if(arr[mid] == target)
			return mid;
		
		if(arr[mid] > target)
			right = mid-1;
		else
			left = mid+1;
	}
	return -1;
}

template<typename T>
int __binarySearch2(T arr[], int l, int r, T target){
	if(l > r)
		return -1;

	int mid = l + (r - l)/2;
	if(arr[mid] == target)
		return mid;
	else if(arr[mid] > target)
		return __binarySearch2(arr, l, mid-1, target);
	else
		return __binarySearch2(arr, mid+1, r, target);
}

void binarySearch2(T arr[], int n, T target){
	return __binarySearch2(arr, 0, n-1, target);
}
