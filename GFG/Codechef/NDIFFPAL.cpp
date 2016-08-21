#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int i=0, flag=1;
        while(flag)
        {
            char c='a';
            while(c<='z')
            {
                cout<<c;
                c++, i++;
                if(i==N)
                {
                    flag=0;
                    break;
                }
            }
        }
        cout<<endl;
    }
}
