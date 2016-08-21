#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> mp;

int findPivot(int a[], int n)
{
    int l, r, mid;
    l=0, r=n-1;
    while(l+1<r)
    {
        mid=(l+r)/2;
        if(a[l]<a[mid])
            l=mid;
        else r=mid;
    }
    if(a[l]>a[r])
        return l;
    else return -1;
}

bool binarySearch(int l, int A[], int r, int key)
{
    if(r>=l)
    {
        int mid=(l+r)/2;
        if(A[mid]==key)
            return mid;
        else if(A[mid]>key)
            return binarySearch(l, A, mid-1, key);
        else return binarySearch(mid+1, A, r, key);
    }
    return -1;
}

int main()
{
    int A[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int arr_size = sizeof(A)/sizeof(A[0]);
    int l=findPivot(A, arr_size);
    int k=-1;
    if(l==-1)
        k=binarySearch(0, A, arr_size-1, 3);
    else
    {
        k=binarySearch(0, A, l, 3);
        if(k==-1)
        k=binarySearch(l+1, A, arr_size-1, 3);
    }
    cout<<A[k]<<endl;
}
