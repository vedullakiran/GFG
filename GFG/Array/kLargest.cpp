#include<iostream>
#include<climits>
using namespace std;
 


void swap(int A[], int i, int j)
{
	int temp=A[i];
	A[i]=A[j];
	A[j]=temp;
}

int partition(int A[], int start, int end)
{
	int pivot=A[end], k=start;
	
	for(int i=start; i<end; i++)
	{
		if(A[i]<pivot)
		{
			swap(A, k, i);
			k++;
		}
	}
	
	swap(A, k, end);
	return k;
}

int quickSort(int A[], int start, int end, int k)
{
	int pi=partition(A, start, end);
	if(pi==k)
		return A[pi];
	if(pi<k)
		return quickSort(A, pi+1, end, k);
	else
		return quickSort(A, start, pi-1, k);
}


int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]), k = 5;
    cout << "K'th smallest element is " << quickSort(arr, 0, n-1, k);
    return 0;
}

