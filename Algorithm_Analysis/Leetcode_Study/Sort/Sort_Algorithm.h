
namespace Sort_Algorithm{
	template<typename T>
	void Insertion_Sort(T arr[], int n){
		for(int i = 1; i < n; i++){
			for(int j = i; j > 0; j--){
				if(arr[j] < arr[j-1])
					std::swap(arr[j], arr[j-1]);
				else
					break;
			}
		}
	}

	template<typename T>
	void Insertion_Sort_Better(T arr[], int n){
		for(int i = 1; i < n; i++){
			T e = arr[i];
			int j = i;
			for(; arr[j-1] > e && j > 0; j-- )
				arr[j] = arr[j-1];
			arr[j] = e;
		}
	}

	template<typename T>
	void Selection_Sort(T arr[], int n){
		for(int i = 0; i < n; i++){
		// 寻找[i, n)中的最小值
		int minIndex = i;
		for(int j = i + 1; j < n; j++)
			if(arr[j] < arr[minIndex])
				minIndex = j;
		swap(arr[i], arr[minIndex]);
		}
	}
	template<typename T>
	void __merge(T arr[], int l, int mid, int r){
		T aux[r-l+1];
		for(int i = l; i <= r; i++)
			aux[i - l] = arr[i];
        
		int i = l, j = mid + 1;
		for(int k = l; k <= r; k++){
			if(i > mid){
				arr[k] = aux[j-l];
				j++;
			}else if(j > r){
				arr[k] = aux[i-l];
				i++;
			}else if(aux[i-l] < aux[j-l]){
				arr[k] = aux[i-l];
				i++;
			}else{
				arr[k] = aux[j-l];
				j++;
			}
		}
	}

	template<typename T>
	void __mergeSort(T arr[], int l, int r){
		if( l >= r)
			return;
    
		int mid = (l+r)/2;
		__mergeSort(arr, l, mid);
		__mergeSort(arr, mid+1, r);
		__merge(arr, l, mid, r);
	}

	template<typename T>
	void mergeSort(T arr[], int n){
		__mergeSort(arr, 0, n-1);
	}
}
