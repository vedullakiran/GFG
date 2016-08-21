#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

void count(int A[], int n, int x)
{
    int S, E;
    int l=0, r=n-1;
    if(A[0]==x)
        S=0;
    else
    {   while(l<=r)
        {
            int mid=(l+r)/2;
            if(A[mid]==x)
            {
                if(A[mid-1]<x)
                {
                    S=mid;
                    break;
                }
                else r=mid-1;
            }
            if(A[mid]<x)
                l=mid+1;
            else r=mid-1;
            //cout<<l<<" "<<r<<endl;
        }
    }
    cout<<S<<endl;
    //return n;
}

int main()
{
    int A[]= {1, 2, 2, 3, 3, 3, 3};
    int arr_size=sizeof(A)/sizeof(A[0]);
    count(A, arr_size, 3);
}
