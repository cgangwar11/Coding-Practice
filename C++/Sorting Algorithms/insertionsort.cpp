#include <bits/stdc++.h>
using namespace std;
insert(std::vector<int>* A,int k,int value)
{
    return
}
int main()
{
    vector<int> A;
    for (int i=10;i>1;i-=1)
    {
        A.push_back(i);
    }
    insert(A.begin()+2,10000);
 // vector<int> A(7,{1,2,0,1,5,4,2});
    // A=insertsort(A,B);
    for (int i=0;i<A.size();i++)
        cout << A[i] << " " ;
    return 0;
}
