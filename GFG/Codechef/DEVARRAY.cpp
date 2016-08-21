#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int N, Q, k, i;
    cin>>N>>Q;
    int mini=1000000010;
    int maxi=-1;
    for(i=0; i<N; i++)
    {
        cin>>k;
        if(k<mini)
            mini=k;
        if(k>maxi)
            maxi=k;
    }
    while(Q--)
    {
        cin>>k;
        if(k>=mini && k<=maxi)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
