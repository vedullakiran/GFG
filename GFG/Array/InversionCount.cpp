#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

int Merge(int A[], int s1, int e1, int s2, int e2)
{
    int inv=0, i=s1, j=s2;
    int temp[e2-s1+3], k=0;

    while(i<=e1 && j<=e2)
    {
        if(A[i]>A[j])
        {
            temp[k++]=A[j++];
            inv+=s2-i;
        }
        else
            temp[k++]=A[i++];
    }

    while(i<=e1)
        temp[k++]=A[i++];
    while(j<=e2)
        temp[k++]=A[j++];

    for(i=0; i<k; i++)
        A[s1++]=temp[i];
    return inv;
}

int _mergeSort(int A[], int l, int r)
{
    int inv=0;
    if(l<r)
    {
        int mid=(l+r)/2;
        inv=_mergeSort(A, l, mid);
        inv+=_mergeSort(A, mid+1, r);
        inv+=Merge(A, l, mid, mid+1, r);
    }
    return inv;
}



int main()
{
    int A[] = {1, 20, 6, 4, 5};
    int arr_size = sizeof(A)/sizeof(A[0]);

    cout<<_mergeSort(A, 0, arr_size-1)<<endl;
}
