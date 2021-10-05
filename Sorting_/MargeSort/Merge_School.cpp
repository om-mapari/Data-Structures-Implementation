/* Merge sort in C */
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
// Function to Merge Arrays L and R into A. 
// lefCount = number of elements in L
// nr = number of elements in R. 
void Merge(int *a,int *L,int nl,int *R,int nr) {
	int i,j,k;
	i = j = k = 0;
	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)

	while(i<nl && j< nr) {
		if(L[i]  < R[j]) a[k++] = L[i++];
		else a[k++] = R[j++];
	}
	while(i < nl) a[k++] = L[i++];
	while(j < nr) a[k++] = R[j++];
}

// Recursive function to sort an array of integers. 
void MergeSort(int *a,int n) {
	int mid,i, *L, *R;
	if(n < 2) return; // base condition. If the array has less than two element, do nothing. 

	mid = n/2;  // find the mid index. 

	// create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array 
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = new int[mid];
    R = new int[n-mid];
	
	for(i = 0;i<mid;i++) L[i] = a[i]; // creating left subarray
	for(i = mid;i<n;i++) R[i-mid] = a[i]; // creating right subarray

	MergeSort(L,mid);  // sorting the left subarray
	MergeSort(R,n-mid);  // sorting the right subarray
	Merge(a,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
    delete (L);
    delete (R);
}

int main() {
	
	int a[] = {6,2,3,1,9,10,15,13,12,17}; // creating an array of integers. 
	int i,numberOfElements;

	// finding number of elements in array as size of complete array in bytes divided by size of integer in bytes. 
	// This won't work if array is passed to the function because array
	// is always passed by reference through a pointer. So sizeOf function will give size of pointer and not the array.

	numberOfElements = sizeof(a)/sizeof(a[0]); 

	// Calling merge sort to sort the array. 
	MergeSort(a,numberOfElements);

	//printing all elements in the array once its sorted.
	for (int atom : a)
    {
        cout << atom << " ";
    }
    return 0;
}