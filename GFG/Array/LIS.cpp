#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <math.h>

#define MAX(a, b) (a)>(b)?(a):(b)
using namespace std;

int LIS(int A[], int n)
{
	int maxLIS[100], i, j;
	
	for(i=0; i<n; i++)
		maxLIS[i]=1;
		
	for(i=0; i<n; i++)
	{
		for(j=0; j<i; j++)
			if(A[i]>A[j])
				maxLIS[i]=max(maxLIS[i], maxLIS[j]+1);
			
	}
	
	int ans=0;
	
	for(i=0; i<n; i++)
		ans=max(ans, maxLIS[i]);
	
	return ans;
}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of lis is %d\n", LIS( arr, n ) );
    return 0;
}
