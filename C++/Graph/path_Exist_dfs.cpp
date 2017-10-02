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
typedef pair<int,int> pii;
typedef pair<int,pii> pipii;
void print(vi&);
void print2d(vii& );
bool isvalid(vii& vis,vii& board,pii pos)
{
    int x=pos.F;
    int y=pos.S;
    int n=vis.size();
    bool cond1=(x>=0 && x<n && y>=0 && y<n);
    if (!cond1)
    return false;
    
    bool cond2=(vis[x][y]==-1 && board[x][y]!=0);
    // cout << cond1 << " " << cond2 << endl;
    return (cond1 && cond2);
}

bool calc(vii& visited,vii& board,vector<pii>& moves,pii cur,pii des)
{
    if (cur.F==des.F && cur.S==des.S)
    {
      // print2d(visited);
      // print2d(board);
      // cout << "***************";
      return true;
    }
    
    FOR(i,moves.size())
    {
      int nextx=cur.F+moves[i].F;
      int nexty=cur.S+moves[i].S;
      if (isvalid(visited,board,mp(nextx,nexty)))
      {
      
        visited[nextx][nexty]=1;
        if (calc(visited,board,moves,mp(nextx,nexty),des))
            return true;
        // board[nextx][nexty]
      
        else
        {
          visited[nextx][nexty]=-1;
        }
        // return false;
      }
    }
    
    return false;
    
}
int main()
 {
	int te;
	cin >> te;
	FOR(i,te)
	{
	    int n;cin >> n;
	    vii vis(n,vi(n,-1));
	    vii board(n,vi(n,-1));
	    pii source,des;
	    vector<pii> moves;
	    moves.push_back(mp(1,0));moves.pb(mp(-1,0));moves.pb(mp(0,1));moves.pb(mp(0,-1));
	    FOR(j,n)
	    {
	      FOR(k,n)
	      {
	        cin >> board[j][k];
	        if (board[j][k]==1)
	        {source=mp(j,k);}
	        
	        
	        
	        if (board[j][k]==2)
	        des=mp(j,k);
	        
	        
	      }
	    }
	    vis[source.F][source.S]=1;
	    if (calc(vis,board,moves,source,des))
	    cout << 1 << endl;
	    else
	    {
	      cout << 0 << endl;
	    }
	   // print2d(vis);
	    
	    
	    
	}
	return 0;
}

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