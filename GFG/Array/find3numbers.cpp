#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

void find3numbers(int A[], int n)
{
    int smaller[n], i;
    int greater[n];
    for(i=0; i<n; i++)
        smaller[i]=greater[i]=-1;

    int minI=0;
    for(i=1; i<n; i++)
        if(A[minI]<A[i])
            smaller[i]=minI;
        else minI=i;

    int maxI=n-1;
    for(i=n-2; i>=0; i--)
        if(A[maxI]>A[i])
            greater[i]=maxI;
        else
            maxI=i;

    for(i=0; i<n; i++)
        if(smaller[i]!=-1 && greater[i]!=-1)
            cout<<A[smaller[i]]<<" "<<A[i]<<" "<<A[greater[i]]<<endl;

}


int main()
{
    int A[]={4, 3, 2 , 1};
    int arr_size=sizeof(A)/sizeof(A[0]);
    int sum=22;
    find3numbers(A, arr_size);
}
