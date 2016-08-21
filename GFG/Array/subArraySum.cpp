#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> subArraySum(int A[], int n, int sum)
{
    int i, j=0, curr_sum=0;
    for(i=0; i<n; i++)
    {
        while(curr_sum<=sum && j<n)
        {
            curr_sum+=A[j];
            cout<<curr_sum<<" ";
            if(curr_sum==sum)
                return make_pair(i, j);
            j++;
        }

        curr_sum-=A[i];
        if(curr_sum==sum)
                return make_pair(i+1, j-1);
    }
    return make_pair(-1, -1);
}

int main()
{
    int A[]= {1, 4, 20, 3, 10, 5};
    int arr_size=sizeof(A)/sizeof(A[0]);

    pair<int, int> p;
    int sum=0;
    p=subArraySum(A, arr_size, sum);
    cout<<endl<<p.first<<" "<<p.second<<endl;
}
