#include <iostream>
#include <stdio.h>
#include <algorithm>
#define INFI 100000

using namespace std;

int minJumps(int A[], int n)
{
    int i, j;
    int jumps[n];

    for(i=0; i<n; i++)
        jumps[i]=INFI;

    for(i=n-2; i>=0; i--)
    {
        if(i+A[i]>=n-1)
            jumps[i]=1;
        else
            for(j=1; j<=A[i] && i+j<n; j++)
                jumps[i]=min(jumps[j+i]+1, jumps[i]);
    }
    return jumps[0];
}

int main()
{
    int A[]= {1, 3, 6, 1, 0, 9};
    int arr_size=sizeof(A)/sizeof(A[0]);

    printf("Number of minimum Jumps is: %d\n", minJumps(A, arr_size));

    return 0;
}
