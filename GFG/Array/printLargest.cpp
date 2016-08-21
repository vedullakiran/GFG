#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int myCompare(string X, string Y)
{
    string a=X.append(Y);
    string b=Y.append(X);

    return a.compare(b)>0?1:0;
}

void printLargest(vector<string> v)
{
    sort(v.begin(), v.end(), myCompare);

    vector<string>::iterator it;
    for(it=v.begin(); it!=v.end(); it++)
        cout<<*it;
    cout<<endl;
}

int main()
{
    vector<string> arr;

    //output should be 6054854654
    /*arr.push_back("54");
    arr.push_back("546");
    arr.push_back("548");
    arr.push_back("60");
    printLargest(arr);
    */
    // output should be 777776
    /*arr.push_back("7");
    arr.push_back("776");
    arr.push_back("7");
    arr.push_back("7");*/

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

   return 0;
}

