#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

void floorCeilSearch(int A[], int n, int * f, int *c, int x)
{
    int l=0, r=n-1;

    if(A[0]>x)
    {
        *c=A[0];
        *f=-1;
        return;
    }

    if(A[n-1]<x)
    {
        *f=A[n-1];
        *c=-1;
        return;
    }

    while(l<=r)
    {
        int mid=(l+r)/2;
        if(A[mid]==x)
        {
            *f=*c=x;
            return;
        }

        if(A[mid]<x)
        {
            if(mid+1==n)
            {
                *c=-1;
                *f=A[mid];
            }

            else if(A[mid+1]>x)
            {
                *f=A[mid];
                *c=A[mid+1];
                return;
            }
            else l=mid+1;
        }
        else
            r=mid-1;
    }
}

int main()
{
    int A[] = {1, 2, 8, 10, 10, 12, 19};
    int arr_size = sizeof(A)/sizeof(A[0]);
    int floor=-1, ceil=-1;
    floorCeilSearch(A, arr_size, &floor, &ceil,3);
    cout<<floor<<" "<<ceil<<endl;
}

