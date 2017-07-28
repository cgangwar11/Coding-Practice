#include <bits/stdc++.h>
using namespace std;
vector<int> selection_sort(vector<int>& A)
{
    for (int i=0;i<A.size();i++)
        {   int cur_min=i;
            for (int j=i;j<A.size();j++)
            {
                if (A[j]<A[cur_min])
                    {cur_min=j;}
            }
            int temp=A[i];
            A[i]=A[cur_min];
            A[cur_min]=temp;
        }
    return A;

}



int main()
{
    vector<int> A;
    for (int i=10000;i>1;i--)
    {
        A.push_back(i);
    }
 // vector<int> A(7,{1,2,0,1,5,4,2});
    A=selection_sort(A);
    for (int i=0;i<A.size();i++)
        cout << A[i] << " " ;
    return 0;
}
