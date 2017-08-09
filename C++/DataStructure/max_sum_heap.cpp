#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define RFOR(i,n) for(int j=n;j>-1;j--)
#define mp make_pair


void printvec(vector<int>& A )
{   for(int i=0;i<A.size();i++)
        {cout << A[i] << " " ;}
    cout << endl;
}


vector<int> solve(vector<int> A, vector<int> B) {
    vector<int> Ans;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    priority_queue<pair<int,pair<int,int> > >ans;
    set<pair<int,int> > mapi;
    int N=A.size();
    ans.push(mp(A[N-1]+B[N-1],mp(N-1,N-1)));
    mapi.insert(mp(N-1,N-1));
    // for(int i=N;i>0;i++)
    while (N--)
    {
        pair<int,pair<int,int> > top=ans.top();
        ans.pop();
        int value=top.first;
        int left=top.second.first;
        int right=top.second.second;
        Ans.push_back(value);

        if (left>=0 && right>=0 && mapi.find(mp(left-1,right))==mapi.end())
        {
            ans.push(mp(A[left-1]+B[right],mp(left-1,right)));
            mapi.insert(mp(left-1,right));
        }
        if (left>=0 && right>=0 && mapi.find(mp(left,right-1))==mapi.end())
        {
            ans.push(mp(A[left]+B[right-1],mp(left,right-1)));
            mapi.insert(mp(left,right-1));
        }

        // pair<int,int> k;





        // ans.push_back()
    }
    return Ans;

}


int main()
{
    int A[4]={3,1,3,1};
    int B[4]={1,4,1,4};
    vector<int> P(A,A+4);
    vector<int> Q(B,B+4);
    std::vector<int> ans;
    ans=solve(P,Q);
    printvec(ans);
        // P.push_back(A[p]);Q.push_back(B[p]);
    // printvec(solve(P,Q));
    return 0;



}


