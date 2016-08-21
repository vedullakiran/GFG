#include <iostream>
#include <stdio.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll K;
        cin>>K;
        if(K==1)
        {
            cout<<"0\n";
            continue;
        }

        K--;
        int s[100];
        int len=0;

        while(K)
        {
            int last=K%5;
            K/=5;
            s[len++]=last*2;
        }

        while(len)
            cout<<s[--len];
        cout<<endl;
    }
}
