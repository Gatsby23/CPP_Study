/*
 * Procedure Insertion-Sort(A, n)
 * Inputs and Result: Same as Selection-Sort
 *
 * 1. For i = 2 to n:
 *	  A. Set key to A[i], and set j to i - 1.
 *	  B. While j > 0 and A[j] > key, do the following:
 *		I. Set A[j+1] to A[j]
 *	   II. Decrement j(i.e., set j to j - 1).
 *	  C. Set A[j+1] to key.
 * */

template<typename BidrectionalIterator>
void insertion_sort(BidrectionIterator _first, BidirectionalIterator _last){
	if(_first == _last) return;

	BidirectionalIterator _it = _first;

	while(++_it != _last){

		// the value need to be inserted to the sorted subarray.
		typename iterator_traits<BidirectionalIterator>::value_type _val = *_it;
		
		// The _middle means and the _right means 
		BidrectionalIterator _middle = _it, _right = _it;
		
		while(_val < * --_middle){
			*_right-- = *_middle;
			if(_middle == _first) break;
		}
		
		*_right = _val;
	}
}
