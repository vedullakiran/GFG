#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#define abs(a) (a)<0?-a:a
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll A, B, C, D;
        cin>>A>>B>>C>>D;
        ll diff=A-B;
        diff=abs(diff);
        ll gcf=__gcd(C,D);
        cout<<min(diff%gcf, gcf-(diff%gcf))<<endl;
    }
}
