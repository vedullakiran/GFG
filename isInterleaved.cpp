#include <iostream>
#include <string>

using namespace std;

bool isInterleaved(string A, string B, string C, int n, int m, int i)
{
	if(A.length()==n && B.length()==m)
		return true;
	
	bool l=false, mid=false;
	if(A.length()!=n && A[n]==C[i])
		l=isInterleaved(A, B, C, n+1, m, i+1);
	if(!l && B.length()!=m && B[m]==C[i])
		l=isInterleaved(A, B, C, n, m+1, i+1);
	
	return l || mid;  
}

int main()
{
	string A("ABCD");
	string B("xyk");
	string C("ABxyCzD");
	if(   (A.length() + B.length())==C.length()  && isInterleaved(A, B, C, 0, 0, 0))
		cout<<"yes"<<endl;
	else cout<<"No"<<endl;
}
