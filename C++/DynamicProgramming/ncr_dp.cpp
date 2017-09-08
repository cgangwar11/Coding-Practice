#include <bits/stdc++.h>
using namespace std;
int print2dvec(vector<vector<int> >& A)
{
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
            {
                cout << A[i][j] << " " ;
            }
        cout << endl;
    }
}
int calculate(int ans,int k,vector<vector<int> > K)
{   
    
    if (ans<=0) return 0;
    
    if (k==0) return 1;

    if (k==1) return ans;
    

    
    // int ansi;
    // cout << ansi;
    // print2dvec(K);
    // cout << "*********************************" << endl;
    int pp=-1,qq=-1;
    if (K[ans-1][k-1]>=0)
    {
        pp=K[ans-1][k-1];
    }
    
    else
    {
        pp=calculate(ans-1,k-1,K);
        K[ans-1][k-1]=pp;
    }
    if (K[ans-1][k]>=0)
    {
        qq=K[ans-1][k];
        K[ans-1][k]=qq;
    }
    else
    {
        qq=calculate(ans-1,k,K);
    }
    // if (pp==-1 && qq!=-1)  return calculate(ans-1,k-1)+qq;
    
    
    // if (pp!=-1 && qq!=-1)  return pp+qq;
    // ansi=calculate(ans-1,k-1)+calculate(ans-1,k);
    K[ans][k]=pp+qq;
    return pp+qq;
}

int main() {
	int n,k,N;
    // N=1;

	cin >> N ;
// 	cout << N;
	while(N--)
	{
	   // n=10;
       // k=3;    
	    cin >> n >> k ;
	   cout << n << k;
	    vector<vector<int> > A(n+1,vector<int>(k+1,-1));
	    // print2dvec(A);
	   // for(int i=0;i<A.size();i++)
	    cout << calculate(n,k,A);
	}
	return 0;
}