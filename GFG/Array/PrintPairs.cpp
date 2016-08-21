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

bool PrintPairs(int A[], int sum, int n){

    for(int i=0; i<n; i++)
        if(mp[A[i]])
            return true;
        else mp[sum-A[i]]=1;
    return false;
}

int main()
{
    int A[] = {1, 10, 4, 45, 8};
    int n = 16;
    int arr_size = sizeof(A)/sizeof(A[0]);

    if(PrintPairs(A, n, arr_size))
        cout<<"Yes\n";
    else
        cout<<"No\n";
}
