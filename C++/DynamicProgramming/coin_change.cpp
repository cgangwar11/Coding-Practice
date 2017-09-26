#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

vector<int> P;

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

void calc(int k,vector<int>& A,int* count,vector<int>& visited)
{
	if (k==0)
	{
		(*count)++ ;
		print(A);
		cout << "*******";
		print(P);
		return;

	}
	if (k<0)
	{
		return ;
	}

	// if (A.size()==0)
	// {
	// 	return;
	// }

	for(int i=0;i<A.size();i++)
	{
		P.push_back(A[i]);
		visited[i]=0;
		if (visited[i]==0)
		calc(k-A[i],A,count,visited);


		visited[i]=1;
		// (*index)++;

		// A.erase(A.begin(),A.begin()+1);
		// print(A);
		P.pop_back();
	}




}






int main()
{
	int te;
	cin >> te;
	FOR(i,te)
	{
		int n;
		cin >> n;
		vector<int> A(n);
		FOR(j,n)
		{
			cin >> A[j];
		}

		int coin;
		cin >> coin;
		vector<int> visited(n,0);
		// print(A);
		int count=0,index=0;
		calc(coin,A,&count,visited);
		cout << count << endl;
	}
	return 0;
}