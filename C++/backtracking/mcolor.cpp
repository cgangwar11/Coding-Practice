#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
typedef vector<int> vv;


void print(vector<int>& A)
{
    FOR(i,A.size())
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void print2d(vector<vector<int> >& A)
{
	for(int i=0;i<A.size();i++)
		{
			for(int j=0;j<A[i].size();j++)
			{
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
}

int find_color(vector<int> al[],int N,vector<int>& color)
{




	for(int col=0;col<N;col++)
	{
		col[i]=
	}


}

int main()
{
	int te;
	FOR(i,te)
	{
		int V,color,E;
		cin >> V;
		cin >> color;
		cin >> E;

		vector<int> al[V+1];

		FOR(i,E)
		{
			int v,e;
			cin >> v;
			cin >> e;
			al[v]=e;
			al[e]=v;
		}


	}



	return 0;

}