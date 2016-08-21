#include <iostream>
#include <stdio.h>

using namespace std;

int findMissingPositive(int A[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(A[i]==i+1 || A[i]<0 || A[i]>n)


    }
}

int main()
{
    int A[]=;
    int n=sizeof(A)/sizeof(A[0]);
    cout<<findMissingPositive(A, n)<<endl;

}
