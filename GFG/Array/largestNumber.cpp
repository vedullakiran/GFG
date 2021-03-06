#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

bool isCompare(string s1, string s2)
{
	string XY=s1.append(s2);
	string YX=s2.append(s1);
	int k=XY.compare(YX);
	if(k<=0)
		return false;
	return true;
}

void printLargest(vector<string> &vs)
{
	sort(vs.begin(), vs.end(), isCompare);
	for(int i=0; i<vs.size(); i++)
		cout<<vs[i];
	cout<<endl;
}



int main()
{
    vector<string> arr;
 
    //output should be 6054854654
    arr.push_back("54");
    arr.push_back("546");
    arr.push_back("548");
    arr.push_back("60");
    printLargest(arr);
    cout<<endl;
    arr.clear();
    
    // output should be 777776
    arr.push_back("7");
    arr.push_back("776");
    arr.push_back("7");
    arr.push_back("7");
    printLargest(arr);
    cout<<endl;
    arr.clear();
    
    //output should be 998764543431
    arr.push_back("1");
    arr.push_back("34");
    arr.push_back("3");
    arr.push_back("98");
    arr.push_back("9");
    arr.push_back("76");
    arr.push_back("45");
    arr.push_back("4");
    printLargest(arr);
    cout<<endl;
    
   return 0;
}
