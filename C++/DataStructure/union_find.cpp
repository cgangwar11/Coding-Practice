/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of the class is as follows 
which contains an integer V denoting the no 
of vertices and a list of adjacency vertices.
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};*/
/*You are required to complete this method*/
int Find(vector<int>& parent,int n)
{
    if (parent[n]==-1)  return n;
    
    return Find(parent,parent[n]);
}

void Union(vector<int>& parent,int x,int y)
{
    int parentx=Find(parent,x);
    int parenty=Find(parent,y);
    if (parentx!=parenty)
    {
        parent[parentx]=parenty;
    }
    
}
bool Graph :: isCyclic()
{
    
    vector<int> parent(V,-1);
    list<int>::iterator it;
    for (int i=0;i<V;i++)
    {
        for(it=adj[i].begin();it!=adj[i].end();it++)
            {   if (i<*it)
                // cout << "EDGE" << i << "--->" << *it << endl;
                {
                    if (Find(parent,i)==Find(parent,*it))
                        {
                            return true;    
                        }
                Union(parent,i,*it);
                    
                }
                else if(i==*it)
                {
                    return true;
                }
            }
    }
    
    return false;
}