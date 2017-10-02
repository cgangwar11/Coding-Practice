//http://practice.geeksforgeeks.org/problems/special-matrix/0

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vvi vii;
#define FOR(i,n) for(int i=0;i<n;i++)
#define RFOR(ii,a,n) for(int ii=0;ii<n;ii++)
#define REV(i,n) for(int i=n-1;i>-1;i--)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007
typedef pair<int,int> pii;
typedef pair<int,pii> pipii;
void print(vector<long long int>&);
void print2d(vector<vector<long long int> >&);



int main()
 {
	int te;
	cin >> te;
	FOR(i,te)
	{
	    int n;cin >> n;
	    int m;cin >> m;
	    int k;cin >> k;
	    vector<vector<long long int> > A(n+1,vector<long long int>(m+1,0));
	    FOR(jj,2*k)
	    {
	        int r,c;
	        cin >> r;
	        cin >> c;

	        
	        
	        A[r-1][c-1]=-1;
	    }
	    
	    FOR(ii,n)
	    {
	        FOR(jj,m)
	        {
	            if (ii==0 && jj==0 && A[ii][jj]!=-1)
	            {
	                A[ii][jj]=1;
	            }
	            else if (ii==0 && jj>0)
	            {
	                if (A[ii][jj]!=-1)
	                A[ii][jj]=A[ii][jj-1];
	                else
	                A[ii][jj]=0;
	            }
	            else if (ii>0 && jj==0)
	            {
	                if (A[ii][jj]!=-1)
	                A[ii][jj]=A[ii-1][jj];
                   else
	                A[ii][jj]=0;
	            }
	            else
	            {
	                if (A[ii][jj]!=-1)
	                A[ii][jj]=A[ii-1][jj]+A[ii][jj-1];
	                else
	                A[ii][jj]=0;
	            }
	            
	            
	        }
	    }
	    
	    print2d(A);
	    
	    cout << A[n-1][m-1]%MOD << endl;
	    
	   // cout << findN
	}
	return 0;
}

void print(vector<long long int>& A)
{
    FOR(i,A.size())
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void print2d(vector<vector<long long int> >& A)
{
	for(int i=0;i<A.size();i++)
		{
            print(A[i]);
		}
}