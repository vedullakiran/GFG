#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> mp;

/*bool PrintPairs(int A[], int sum, int n)
{
    sort(A, A+n);
    int l=0, r=n-1;
    while(l<r){
        if(A[l]+A[r]==sum)
            return true;
        else if(A[l]+A[r]>sum)
            r--;
        else l++;
    }
    return false;
}*/

int maxSumSubArray(int A[], int n){
    int max_so_far=0, max_now=0;
    for(int i=0; i<n; i++)
    {
        max_now+=A[i];
        if(max_so_far<max_now)
            max_so_far=max_now;
        if(max_now<0)
            max_now=0;
    }
    return max_so_far;
}

int main()
{
    int A[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int arr_size = sizeof(A)/sizeof(A[0]);

    cout<<maxSumSubArray(A, arr_size)<<endl;
}
