#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A, B;
        cin>>A>>B;
        int one=0, zero=0, yes1=0, yes0=0;
        for(int i=0; i<A.length(); i++)
        {
            if(A[i]=='0')
                yes0=1;
            else
                yes1=1;

            if(A[i]!=B[i])
            {
                if(A[i]=='1')
                    one++;
                else
                    zero++;
            }

        }
        //cout<<one<<" "<<zero<<endl;
        if((one!=0 && yes0==0) || (zero!=0 && yes1==0))
            printf("Unlucky Chef\n");
        else
            cout<<"Lucky Chef\n"<<max(one, zero)<<endl;

    }
}
