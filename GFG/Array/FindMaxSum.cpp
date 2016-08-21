#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> mp;

int findMaxSum(int A[], int n)
{
    int m1, m2, exec, i;
    m1=A[0];
    if(n==1)
        return m1;
    m2=A[1];
    exec=m1;

    for(i=2; i<n; i++)
    {
        int temp=exec+A[i];
        exec=max(m1, m2);
        m1=m2;
        m2=temp;
    }
    return max(m1, m2);
}

int main()
{
    int A[] = {5, 5, 10, 100, 10, 5};
    int arr_size = sizeof(A)/sizeof(A[0]);
    cout<<findMaxSum(A, arr_size)<<endl;
}
