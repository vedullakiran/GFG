#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int findFirstMissing(int A[], int n)
{
    int x=0;
    int l=0, r=n-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(A[l]>l)
            return l;
        if(A[mid]==mid)
            l=mid+1;
        else r=mid-1;
        //cout<<l<<" "<<r<<endl;
    }
    return n;
}

int main()
{
    int A[]= {0, 1, 2, 6, 9};
    int arr_size=sizeof(A)/sizeof(A[0]);
    cout<<findFirstMissing(A, arr_size);
}
