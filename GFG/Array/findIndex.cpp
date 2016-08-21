#include<iostream>
using namespace std;
 
int maxOnesIndex(bool A[], int n)
{
	int i, prev=0, curr=0, maxi=0, count, idx=-1, k;
	
	for(i=0; i<n; i++)
	{
		if(A[i])
		{
			curr++;
			count=1;
		}
		else if(count)
		{
			count=0;
			if(maxi<prev+curr)
			{
				maxi=prev+curr;
				idx=k;
			}
			prev=curr;
			k=i;
			curr=0; 
		}
		else if(!count)
			prev=0;
	}
	
	if(prev+curr>maxi)
		return k;
	return idx;
}
 
int main()
{
    bool arr[] = {1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Index of 0 to be replaced is "<< maxOnesIndex(arr, n)<<endl;
    return 0;
}
