#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void adjacency_list(vector<int> *S,int E)
{
    for(int i=0;i<E;i++)
        {   int A,Ed;
            cin >> A >> Ed;
            S[A].push_back(Ed);
        }
}
void adjacency_list_uni(vector<int> *S,int E)
{
    for(int i=0;i<E;i++)
        {   int A,Ed;
            cin >> A >> Ed;
            S[A].push_back(Ed);
            S[Ed].push_back(A);
        }
}

void print(vector<int>& A )
{   for(int i=0;i<A.size();i++)
        {cout << A[i] << " " ;}
    cout << endl;
}
void print2d(vector<int> *A ,int N)
{   for(int i=0;i<N;i++)
        {for(int j=0;j<A[i].size();j++)
        	{cout << A[i][j] << " " ;}
        	cout << endl;}
    cout << endl;
}

void dfs_imp(std::vector<int> *S,std::vector<int>& visited,stack<int>& P,int root)
{
	P.push(root);
	visited[root]=1;
	while(!P.empty())
	{
		int cr=P.top();
		P.pop();
		for (int i = 0; i < S[cr].size(); ++i)
		{	
			
			if (visited[S[cr][i]]==0)
			{	
				P.push(S[cr][i]);
				visited[S[cr][i]]=1;
			}
		}
	}
}
void dfs_rec(std::vector<int> *S,std::vector<int>& visited,stack<int>& P)
{
	if (P.empty())
		return ;
	int root=P.top();
	P.pop();
	if (visited[root]==0)
	{
		for(int i=0;i<S[root].size();i++) 
		{
			visited[root]=1;
			P.push(S[root][i]);
			dfs_rec(S,visited,P);
		}
	}


}
int main()
{   int N,K;
    cin >> N >> K;

    vector<int> S[N+1];
    stack<int> P;
    vector<int> visited(N+1,0);

    adjacency_list(S,K);
    // print2d(S,N);
    int root;
    cin >> root;
    // cout << root;
    P.push(root);
    dfs_rec(S,visited,P);
    // print(visited);
    int count=0;
    for (int i=1;i<=N;i++) 
    {
    	if (visited[i]==0) count++;
    }
    cout << count;

    return 0;
}
