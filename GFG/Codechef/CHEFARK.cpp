#include <iostream>
#include <stdio.h>
#include <algorithm>
#define ll long long
#define mod 1000000007

using namespace std;
ll A[100005];
int mod_inverse[100005];

inline int power(int a, int b, int MOD)
{
    ll y=1, x=a;
    while(b)
    {
        if(b%2)
        {
            y=(x*y)%MOD;
            b--;
        }
        else
        {
            b/=2;
            x=(x*x)%MOD;
        }
    }
    return y%MOD;
}

void find_modInverse()
{
    mod_inverse[1]=1;
    for(int i=2 ; i<100004; i++)
        mod_inverse[i]=power(i, mod-2, mod);
}

int main()
{
    int t;
    cin>>t;
    find_modInverse();
    while(t--)
    {
        int N, K;
        cin>>N>>K;
        int i, zero=0;
        for(i=0; i<N; i++)
        {
            cin>>A[i];
            if(A[i]==0)
                zero++;
        }
        if(zero>0)
            N-=zero;

        ll low=1, up=N;
        ll ADD=1;

        A[0]=1;

        for(i=1; i<=N && i<=K; i++)
        {
            if(zero>0)
                A[i]=A[i-1];
            else if(i>1) A[i]=A[i-2];
            else A[i]=0;
            ADD=(((ADD*up)%mod)*mod_inverse[low])%mod;
            up--;
            low++;
            A[i]=(A[i]+ADD)%mod;
        }

        ll ans=0;

        if(zero>0)
        {
            int mini=min(K,N);
            cout<<A[mini]<<endl;
        }
        else if(K<=N)
            cout<<A[K]<<endl;
        else
        {
            if(K%2)
            {
                if(N%2)
                    ans=A[N];
                else
                    ans=A[N-1];
            }
            else
            {
                if(N%2)
                    ans=A[N];
                else
                    ans=A[N-1];
            }
            cout<<ans<<endl;

        }
    }
}
