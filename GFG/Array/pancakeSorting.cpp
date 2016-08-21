#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void swap(int i, int j, int A[])
{
	int temp=A[i];
	A[i]=A[j];
	A[j]=temp;
}

void flip(int A[], int end)
{
	for(int i=0; i<end/2; i++)
		swap(i, end-i, A);
}

int findLargest(int A[], int end)
{
	int maxIdx=0;
	for(int i=1; i<=end; i++)
		if(A[maxIdx]<A[i])	
			maxIdx=i;
	return maxIdx;
}

void pancakeSorting(int A[], int n)
{
	n--;
	while(n!=0)
	{
		int i=findLargest(A, n);
		flip(A, i);
		flip(A, n);
		n--;
	}
}

void printArray(int arr[], int n)
{
    	for (int i = 0; i < n; ++i)
        	printf("%d ", arr[i]);
}

int main()
{
    	int arr[] = {23, 10, 20, 11, 12, 6, 7};
    	int n = sizeof(arr)/sizeof(arr[0]);
 
    	pancakeSorting(arr, n);
 
    	puts("Sorted Array ");
    	printArray(arr, n);
 
    	return 0;
}
