#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

void sap(int i, int j, int A[])
{
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}

void segregate012(int A[], int n)
{
    int i=0, left=0, right=n-1;
    while(i<=right)
    {
        if(A[i]==0)
        {
            sap(i, left, A);
            left++;
            i++;
        }
        else if(A[i]==2)
        {
            sap(i, right, A);
            right--;
        }
        else i++;
    }
}

int main()
{
    int A[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int arr_size = sizeof(A)/sizeof(A[0]);
    segregate012(A, arr_size);
    for(int i=0; i<arr_size; i++)
        cout<<A[i]<<" ";
}


