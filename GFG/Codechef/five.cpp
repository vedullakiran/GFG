#include <iostream>
#include <stdio.h>
#include <algorithm>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
    int t;
    ll C[100][100];

    int i, j;
    for(i=0; i<100; i++)
        C[i][0]=1;

    for(i=0; i<100; i++)
        C[i][i]=1;

    for(i=2; i<100; i++)
        for(j=1; j<i; j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    cin>>t;
    while(t--)
    {
        int N, K;
        cin>>N>>K;
        ll A[100003];

        A[0]=1;
        A[1]=N;
        for(i=2; i<=N && i<=K; i++)
            A[i]=(A[i-2]+C[N][i])%MOD;
        int ff=N%2;
        if(K<=N)
            cout<<A[K]<<endl;
        else
        {
            if(K%2)
            {
                if(ff)
                    cout<<A[N]<<endl;
                else cout<<A[N-1]<<endl;

            }
            else
            {
                if(ff==0)
                    cout<<A[N]<<endl;
                else cout<<A[N-1]<<endl;

            }
        }
    }
}
