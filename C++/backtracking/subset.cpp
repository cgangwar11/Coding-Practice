#include <bits/stdc++.h>
using namespace std;
void print(vector<int>& A )
{   for(int i=0;i<A.size();i++)
        {cout << A[i] << " " ;}
    cout << endl;
}


void generatesets(std::vector<int>& A,int index,std::vector<int>& curr,vector<vector<int> >& ans)
{

    // if (index>=A.size())
    //     return
    // print(curr);
    ans.push_back(curr);
    // print(ans[index]);
    // print2d(ans);
    // print2d(ans);
    // print(curr);
    for (int i = index+1; i <A.size()+1; i++)
    {   //print(curr);
        // cout << curr.size()<< " " ;
        curr.push_back(A[i-1]);
        // print(curr);
        generatesets(A,i,curr,ans);
        curr.pop_back();        /* code */
    }

    // return;


}
int main()
{

    int A[4]={3,3,5,7};
    vector<int> B(A,A+4);
    list<int> C(A,A+3);
    vector<vector<int> > ans;
    vector<int> curr;
    sort(B.begin(), B.end());
    generatesets(B,0,curr,ans);

    // print2d(ans);
    // print(C);
    for (int i=0;i<ans.size();i++)
    {
        print(ans[i]);
    }
    return 0;
}



