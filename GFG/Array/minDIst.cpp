#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int minDist(int A[], int n, int x, int y)
{
    int index=-1;
    int t, mini=100;
    for(int i=0; i<n; i++)
    {
        if(index==-1 && (A[i]==x || A[i]==y))
        {
            index=i;
            if(A[i]==x)
                t=x;
            else t=y;
        }
        else if(A[i]==x && A[i]!=t)
        {
            mini=min(mini, i-index);
            index=i;
            t=x;
        }
        else if(A[i]==y && A[i]!=t)
        {
            mini=min(mini, i-index);
            index=i;
            t=y;
        }
    }
    return mini;
}

int main()
{
    int A[]=  {1, 2};
    int arr_size=sizeof(A)/sizeof(A[0]);
    cout<<minDist(A, arr_size, 1, 2);
}
