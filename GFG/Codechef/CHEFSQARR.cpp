#include <iostream>
#include <stdio.h>
#include <algorithm>
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
using namespace std;

int  A[1005][1005];

int main()
{
    int N, M, Q, a, b;
    cin>>N>>M;
    int i, j, x, y;

    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
            cin>>A[i][j];

    cin>>Q;
    while(Q--)
    {
        cin>>a>>b;
        int mini=1000000010;
        if(a==1 && b==1)
        {
            cout<<"0\n";
            continue;
        }

        for(i=0; i<=N-a; i++)
        {
            for(j=0; j<=M-b; j++)
            {
                int maxi=-1;

                for(x=i; x<i+a; x++)
                    for(y=j; y<j+b; y++)
                        maxi=MAX(maxi,A[x][y]);
                int ans=0;
                for(x=i; x<i+a; x++)
                    for(y=j; y<j+b; y++)
                        ans+=maxi-A[x][y];
                mini=MIN(mini, ans);
            }
        }
        cout<<mini<<endl;
    }

}
