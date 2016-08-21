#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int maxRepeating(int A[], int n, int k)
{
	int i;
	for(i=0; i<n; i++)
		A[A[i]%k]+=k;
	int maxi=-1;
	for(i=0; i<n;i++)
		maxi=max(maxi, A[i]/k);
	return maxi;
}


int main()
{
    int arr[] = {1, 2, 2, 2, 0, 2, 0, 2, 3, 8, 0, 9, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 8;
 
    cout << "The maximum repeating number is " <<maxRepeating(arr, n, k) << endl;
 
    return 0;
}
