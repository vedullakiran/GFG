#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <math.h>
#include <vector>

#define MAX(a, b) (a)>(b)?(a):(b)
using namespace std;

int LISChain(vector< pair<int, int> > &v)
{
	int maxLIS[100], i, j;
	
	for(i=0; i<v.size(); i++)
		maxLIS[i]=1;
		
	for(i=0; i<v.size(); i++)
	{
		for(j=0; j<i; j++)
			if(v[i].first>v[j].second)
				maxLIS[i]=max(maxLIS[i], maxLIS[j]+1);
			
	}
	
	int ans=0;
	
	for(i=0; i<v.size(); i++)
		ans=max(ans, maxLIS[i]);
	
	return ans;
}

int main()
{
	vector<pair<int, int> > v;
	
    	for(int i=0; i<1; i++)
    	{
    		int a;
    		int b;
    		cin>>a>>b;
    		v.push_back(make_pair(a, b));
    	}
    	printf("Length of lis is %d\n", LISChain( v) );
    	return 0;
}
