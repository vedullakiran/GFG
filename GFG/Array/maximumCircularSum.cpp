#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int maxCircularSum(int A[], int n)
{
	int max_sum=0, sum_till_now=0, idx1=1000, idx2=1;
	int i=0;
	bool flag=false;
	int first, second, k;
	
	for(i=0; i<n; i++)
	{
		sum_till_now+=A[i];
		if(max_sum<sum_till_now)
		{	
			max_sum=sum_till_now;
			k=i;
		}
		if(sum_till_now<=0)
		{
			sum_till_now=0;
			if(!flag)
			{
				first=max_sum;
				idx1=k;
				flag=true;
			}
		}
	}
	
	int max_sum1=0, sum_till_now1=0;
	flag=false;
	for(i=n-1; i>-1; i--)
	{
		sum_till_now1+=A[i];
		if(max_sum1<sum_till_now1)
		{
			max_sum1=sum_till_now1;
			k=i;
		}
		else if(max_sum>)
		if(sum_till_now1<=0)
		{
			sum_till_now1=0;
			if(!flag)
			{
				second=max_sum1;
				idx2=k;
				flag=true;
			}
		}
	}
	cout<<idx1<<" "<<idx2<<endl;
	if(idx1<idx2)
		return max(second+first, max_sum);
	else return max_sum;
}

int main()
{
    int a[] =  {12, -5, 4, -8, 11};
    int n = sizeof(a)/sizeof(a[0]);
    printf("Maximum circular sum is %d\n", maxCircularSum(a, n));
    return 0;
}
