#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
#define FOR(i,n) for(int i=0;i<n;i++)
#define RFOR(i,a,n) for(int i=0;i<n;i++)
#define REV(i,n) for(int i=n-1;i>-1;i--)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define INF INT_MAX
typedef pair<int,int> pii;
typedef pair<int,pii> pipii;
void print(vi&);
void print2d(vii& );
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
            print(A[i]);
		}
}

vector<int> shortestPath(vector<pii> adj[], int V, int src) 
{ 

    priority_queue< pii, vector <pii> , greater<pii> > pq; 
  
    vector<int> dist(V, INF); 
  

    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    /* Looping till priority queue becomes empty (or all 
    distances are not finalized) */
    while (!pq.empty()) 
    { 

        int u = pq.top().second; 
        pq.pop(); 
  
        // Get all adjacent of u.  
        for (auto x : adj[u]) 
        { 
 
            int v = x.first; 
            int weight = x.second; 

            if (dist[v] > dist[u] + weight) 
            { 

                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    }
    
    return dist;
  

} 

int main(){
    
    //vector<int> graph;
    
    int T,N;
    int Q;
    cin >> T;
    
    while(T--)
    {   cin >> Q;
        vector<int> ladder;
        FOR(i,Q)
        {
            int temp; 
            cin >> temp;
            ladder.pb(temp);
        }
        cin >> N;
        
        vector<pii> graph[Q+1];
        for(int i=0;i<ladder.size();i++)
        {
            for(int j=1;j<=ladder[i];j++)
            {
                graph[i].pb(make_pair(i+j,1));
            }
        }
        
        vector<int> distance = shortestPath(graph,Q+1,0);
        
        int query;
        while(N--)
        {   cin >> query;
            cout << distance[query] << " ";
        }
    
    }
    
    
    
}
