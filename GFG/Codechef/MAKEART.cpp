#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int i;
        int C[100005];
        for(i=0; i<N; i++)
            cin>>C[i];

        int flag=0;

        for(i=1; i<N-1;i++)
            if(C[i]==C[i-1] && C[i]==C[i+1])
            {
                cout<<"Yes\n";
                flag=1;
                break;
            }
        if(flag==0)
            cout<<"No\n";
    }
}
