/*
 * Procedure Selection-Sort(A, n)
 * Inputs:
 *	A: an array.
 *	n: the number of elements in A to sort
 * Result: The elements of A are sorted into nondecreasing order
 * 1. For i = 1 to n-1:
 *	A. Set smallest to the index of the smallest element in the subarray A[1..n];
 *	B. Swap A[i] with A[smallest]
 * 
 * Refined Procedure:
 * 1. For i = 1 to n-1:
 *	A. set smallest to i
 *	B. For j = i+1 to n:
 *		if A[j] < A[smallest], then set smallest to j.
 *	C. Swap A[i] with A[smallest]
 * */
