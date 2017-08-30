#include <bits/stdc++.h>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define AFOR(i,n) for(auto i:n)
#define mp make_pair
void print_vec(vector<pair<int,int> >& A)
{
    FOR(i,A.size()) cout << " (" << A[i].first << " " << A[i].second << ") ";
    cout << endl;
}

void print_graph(vector<pair<int,int> > *S,int M)
{
    FOR(i,M)
    {
        cout << i << " NODE  ";
        print_vec(S[i]); 
        
    }
}


void make_weighted_graph(vector<pair<int,int> > *S,int M)
{
    FOR(i,M)
    {
        int vert1,vert2,weight;
        cin >> vert1 >> vert2 >> weight;
        S[vert1].push_back(mp(vert2,weight));
    }
}
int find_min_not_visited(std::vector<int>& distance , std::vector<bool> visited)
{
	int min=INT_MAX;
	FOR(i,distance.size())
	{
		if (distance[i] < min && visited[i]==false)
		{
			return i;
		}
	}
	return -1;
}
vector<int> cost_traverse(vector<pair<int,int> > *S,int source,int N,int M)
{
    vector<bool> visited(N,false);
    vector<int> distance(N,INT_MAX);
    // int cur=source;
    // visited[1]=true;
    distance[source]=0;
    int cur=source;
    for (int i=1;i<N+1;i++)
    {
        for (int j=0;j<S[cur].size();j++)
            {
                int possible_len=distance[cur] + S[cur][j].second;
                int vertex=S[cur][j].first;
                if (distance[vertex] > possible_len && vertex!=cur)
                    {
                        distance[vertex]=distance[cur] + S[cur][j].second;
                    }
                
                
            }
        cur=find_min_not_visited(distance,visited); 
        // cout << cur  << endl;
        if (cur<0)
            break;
        visited[cur]=true;
    }
    return distance;    

}

vector<int> cost_traverse_priority_queue(vector<pair<int,int> > *S,int N)
{
    vector<bool> visited(N,false);
    vector<int> distance(N,INT_MAX);
    multiset<pair<int,int> > set;
    set.insert(mp(0,1));
    while(!set.empty())
    {
        pair<int,int> PP=*set.begin();
        int weight=PP.first,vertex=PP.second;
        set.erase(set.begin());
        if (visited[vertex])
            continue;
        visited[vertex]=true;
        for (int i=0;i<S[vertex].size();i++)
        {
            int to_vert=S[vertex][i].first,cur_weight=S[vertex][i].second;
            int possible_len = cur_weight+weight;
            if (possible_len<distance[to_vert])
                distance[to_vert]=possible_len; set.insert(mp(cur_weight,to_vert));

        }
    }
    return distance;

}
int main()
{
    int a,b;
    cin >> a >> b; 
    vector<pair<int,int> > graph[a+2];
    make_weighted_graph(graph,b);
    // print_graph(graph,b);
    std::vector<int> ans;
    // ans=cost_traverse(graph,1,a+1,b+1);
    ans=cost_traverse_priority_queue(graph,a+1);
    FOR(i,ans.size()) if (i>1) cout << ans[i] << " ";
    return 0;
}
