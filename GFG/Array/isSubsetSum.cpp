#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

bool isSubsetSum(int A[], int n, int sum)
{
    if(sum==0)
        return true;
    if(n<0 || sum<0)
        return false;
    return isSubsetSum(A, n-1, sum-A[n]) || isSubsetSum(A, n-1, sum);
}

int main()
{
    int A[]={3, 3, 5, 9};
    int n=sizeof(A)/sizeof(A[0]);
    int sum=0;
    for(int i=0; i<n; i++)
        sum+=A[i];
    if(!(sum%2) && isSubsetSum(A, n-1, sum/2))
        cout<<"Possible\n";
    else
        cout<<"Not Possible\n";
}

