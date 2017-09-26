
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

int knapsack(vector<int>& v,vector<int>& w,vector<vector<int> >& M)
{
	int N=M.size();
	int W=M[0].size()-1;
	FOR(i,N)
	{
		FOR(j,W+1)
	{
		if (j==0)
			M[i][j]=0;
		if (i==0 && w[i]<=j) M[i][j]=v[i];

		else
		{
			if (j<w[i])
				M[i][j]=M[i-1][j];
			else if (j>=w[i])
			{
				M[i][j]=max(M[i-1][j],v[i]+M[i-1][j-w[i]]);
			}
		}

	}
}
	return M[N-1][W];

}







int main()
{
	int te;
	cin >> te;
	FOR(i,te)
	{
		int N,W;
		cin >> N;
		cin >> W;
		vector<vector<int> > M(N,vector<int>(W+1,0));
		// FOR(p,W+1)
		vector<int> ve(N);
		FOR(j,N)
		{
			cin >> ve[j];
		}
		vector<int> we(N);
		FOR(k,N)
		{
			cin >> we[k];
		}

		cout << knapsack(ve,we,M);
	}
	return 0;
}