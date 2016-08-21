#include <iostream>
#include <algorithm>

using namespace std;

void segregate0and1(int A[], int n)
{
    int i=0, l=n-1;
    while(i<l)
    {
        if(A[i]==1)
        {
            int temp=A[i];
            A[i]=A[l];
            A[l]=1;
            l--;
        }
        else i++;
    }
}

int main()
{
    int arr[] = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
    int i, arr_size = sizeof(arr)/sizeof(arr[0]);

    segregate0and1(arr, arr_size);

    cout<<"array after segregation \n";
    for (i = 0; i < arr_size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
