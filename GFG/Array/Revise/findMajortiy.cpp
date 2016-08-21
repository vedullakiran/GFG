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

int findMajority(int A[], int n){
    int i, count=0;
    int maj_ind=0;
    for(i=1; i<n; i++){
        if(A[maj_ind]==A[i])
            count++;
        else count--;
        if(count==0){
            maj_ind=i, count=1;
        }
    }
    if(count>0)
        return A[maj_ind];
    else return -1;
}

int main()
{
    int A[] = {1, 10, 4, 45, 8, 8};
    int arr_size = sizeof(A)/sizeof(A[0]);

    cout<<findMajority(A, arr_size)<<endl;
}
