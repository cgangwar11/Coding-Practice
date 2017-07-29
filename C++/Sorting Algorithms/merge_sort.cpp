#include <bits/stdc++.h>
using namespace std;
void printvec(std::vector<int>);
std::vector<int> Merge(std::vector<int> A,std::vector<int> B)
{
    int i=0,j=0;
    // printvec(A);
    // printvec(B);
    std::vector<int> ans;
    while (i<A.size() && j<B.size())
        {
            if (A[i]>B[j])
            {
                ans.push_back(B[j]);
                // cout << " A ";
                j++;
            }
            else
            {
                ans.push_back(A[i]);
                // cout <<" B ";
                i++;
            }
        }
    if (j<B.size())

    {
        for(int k=j;k<B.size();k++)
            {
                ans.push_back(B[k]);
            }
    }
    else if (i<A.size())

    {
        for(int k=i;k<A.size();k++)
            {
                ans.push_back(A[k]);
            }
    }
    return ans;

}




std::vector<int> MergeSort(std::vector<int>& A)
{
    if (A.size()==1)
        return A;
    std::vector<int> a(A.begin(),A.begin()+A.size()/2);
    std::vector<int> b(A.begin()+A.size()/2,A.end());

    return Merge(MergeSort(a),MergeSort(b));

}


void printvec(std::vector<int> A)
{
        for (int i=0;i<A.size();i++)
        cout << A[i] << " " ;
        cout << endl;
}






int main()
{
    vector<int> A;
    for (int i=10;i>1;i-=1)
    {
        A.push_back(i);
    }

 // vector<int> A(7,{1,2,0,1,5,4,2});
    A=MergeSort(A);
    for (int i=0;i<A.size();i++)
        cout << A[i] << " " ;
    return 0;
}
void test_merge()
{
    vector<int> A,B;
    for (int i=1;i<10;i+=2)
    {
        A.push_back(i);
    }
    for (int i=0;i<-1;i+=2)
    {
        B.push_back(i);
    }

 // vector<int> A(7,{1,2,0,1,5,4,2});
    A=Merge(A,B);
    for (int i=0;i<A.size();i++)
        cout << A[i] << " " ;
}
