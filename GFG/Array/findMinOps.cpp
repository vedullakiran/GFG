#include <iostream>
#include <stdio.h>

using namespace std;

int findMinOps(int A[], int n)
{
	if(n==1)
		return 0;
	int ans=0;
	int start=0, end=n-1;
	
	while(start<end)
	{
		if(A[start]==A[end])
		{
			start++;
			end--;
		}
		else if(A[start]!=A[end] && start==end-1)
			return ans+1;
		else if(A[start]>A[end])
		{
			end--;
			A[end]+=A[end+1];
			ans++;
		}
		else
		{
			start++;
			A[start]+=A[start-1];
			ans++;
		}
	}
	return ans;
}

int main()
{
    int arr[] ={11, 14, 15, 99};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Count of minimum operations is "<<  findMinOps(arr, n) << endl;
    return 0;
}
