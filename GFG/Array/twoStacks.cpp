#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int bitonic(int A[], int n)
{
    int i, inc[n], dec[n];
    for(i=0; i<n; i++)
        inc[i]=dec[i]=1;

    for(i=1; i<n; i++)
        if(A[i]>=A[i-1])
            inc[i]+=inc[i-1];

    for(i=n-2; i>=0; i--)
        if(A[i]>=A[i+1])
            dec[i]+=dec[i+1];
    int maxi=-1;
    for(i=0; i<n; i++)
        maxi=max(inc[i]+dec[i]-1, maxi);
    return maxi;
}

int main()
{
    int A[]=  {40, 30, 20, 10};
    int arr_size=sizeof(A)/sizeof(A[0]);
    cout<<bitonic(A, arr_size)<<endl;
}
