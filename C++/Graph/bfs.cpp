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
void bfs_ite(std::vector<int> *S,std::vector<int>& visited,queue<int>& P,int root)
{
    // int curr=root;
    P.push(root);
    while (!P.empty())
    {
       int curr=P.front();
       P.pop();
       for(int i=0;i<S[curr].size();i++)
        {   int neigh=S[curr][i];
            if (visited[neigh]==0)
            {
                P.push(neigh);
                visited[neigh]=1;
            }
        } 
    }

}

int main()
{   int N,K;
    cin >> N >> K;

    vector<int> S[N+1];
    queue<int> P;
    vector<int> visited(N+1,0);

    adjacency_list_uni(S,K);

    int root;
    cin >> root;
    bfs_ite(S,visited,P,root);
    // cout << root;
    // P.push(root);
    // dfs_rec(S,visited,P);
    // print(visited);
    int count=0;
    for (int i=1;i<=N;i++) 
    {
        if (visited[i]==0) count++;
    }
    cout << count;

    return 0;
}