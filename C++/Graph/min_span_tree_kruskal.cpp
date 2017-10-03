
int Find(vector<int>& parent,int p)
{
    if (parent[p]==-1)
    {
        return p;
    }
    
    Find(parent,parent[p]);
}
struct graph
{
    int u;
    int v;
    int w;
    graph(int au=0,int av=0,int aw=0)
    {
        u=au;v=av;w=aw;
    };
};
void Union(vector<int>& parent,int p,int q)
{
    int p1=Find(parent,p);
    int p2=Find(parent,q);
    if (p1!=p2)
    {
        parent[p1]=p2;
    }
}
bool comp(graph &A,graph &B)
{
    return A.w < B.w ;
}
int spanningTree(vector <pair<int,int> > g[], int MAX)
{
    vector<graph> W;
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            if (i<=g[i][j].second)
          {  
              graph temp(i-1,g[i][j].second-1,g[i][j].first);
              W.push_back(temp);
            }
        }
    }
    sort(W.begin(),W.end(),comp);  //edges in sorted order
    for(int i=0;i<MAX;i++)
    {
        g[i].clear();
    }
    vector<int> parent(MAX,-1);
    int ans=0;
    for(int i=0;i<W.size();i++)
    {
        int u,v;
        u=W[i].u;
        v=W[i].v;
        
        if (Find(parent,u)!=Find(parent,v))
        {
            Union(parent,u,v);
            ans+=W[i].w;
        }
        
        
    }
    
    // for (int i=0;i<W.size();i++)
    // {
    //     cout << W[i].u << " " << W[i].v << " " << W[i].w << endl;
    // }
    
    return ans;
}

