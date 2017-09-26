//http://practice.geeksforgeeks.org/problems/cutted-segments/0
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
int calc(int N,int x,int y,int z,vector<int>& MEMO)
{
    int k=min(x,min(y,z));
    if (N==0)
    {
        return 0;
    }
    // if (N==x || N==y || N==z )
    // {
    //     return 2;
    // }
    if (N<0 )
    {
        return INT_MIN;
    }
    
    // if (N<0)
    // {
    //     return 0;
    // }
    if (MEMO[N]!=-1) 
    {
        return MEMO[N];
    }
    
    int ans=1+max(calc(N-x,x,y,z,MEMO),max(calc(N-y,x,y,z,MEMO),calc(N-z,x,y,z,MEMO)));
    MEMO[N]=ans;
    return ans;
}
int main() {
	//cod
	int th;
	cin >> th;
	FOR(i,th)
	{
	    int temp;
	    cin >> temp;
	    int x,y,z;
	    cin >> x;
	    cin >> y;
	    cin >> z;
	    
	   // vector<int> A(temp);
	   // FOR(j,temp)
	   // {
	   //     cin >> A[j];
	   // }
	    vector<int> MEMO(temp+1,-1);
	    cout << calc(temp,x,y,z,MEMO) << endl;
	}
	return 0;
}