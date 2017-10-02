//http://www.geeksforgeeks.org/backtracking-set-1-the-knights-tour-problem/
//awesome ques works with this move only


#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define N 8
#define mp make_pair
#define pb push_back
vector<pair<int,int> > moves;
void print2d(const std::vector<std::vector<int> >& ans)
{
        for(int i=0;i<ans.size();i++)
        {
            for (int j = 0; j < ans[i].size(); ++j)
            {
                cout << ans[i][j] << " "  ;
                /* code */
            }
            // cout << ans[i].size() ;
            cout << endl;
        }
}
void print(vector<int>& A)
{
    FOR(i,A.size())
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

bool issafe(int x,int y,vector<vector<int> >& B)
{

	return (x>=0 && y>=0 && y<N && x<N && B[x][y]==-1);
}

bool foundKT(vector<vector<int> >& Board,int x,int y,int move)
{
	if (move==N*N)
	{
		// Board[x][y]=64;
		return true;
	}

	// print2d(Board);

	FOR(i,moves.size())
	{
		pair<int,int> move_cur = moves[i];
		int nextx=x+move_cur.first;
		int nexty=y+move_cur.second;
		if (issafe(nextx,nexty,Board))
		{
			
			Board[nextx][nexty]=move;
			// x+move_cur.first;
			// y+=move_cur.second;
			if (foundKT(Board,nextx,nexty,move+1)==true)
			{
				return true;
			}

			else
			{
				Board[nextx][nexty]=-1;
				// return false;
			}
		}
	}

	return false;
}


void solveKT()
{
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
    FOR(i,8)
    {
    	moves.pb(mp(xMove[i],yMove[i]));
    }
	// moves.pb(mp(2,1));
	// moves.pb(mp(2,-1));
	// moves.pb(mp(-2,-1));
	// moves.pb(mp(-2,1));
	// moves.pb(mp(1,-2));
	// moves.pb(mp(1,2));
	// moves.pb(mp(-1,-2));
	// moves.pb(mp(-1,2));
	std::vector<vector<int> > Board(N,std::vector<int>(N,-1));
	int x=0;
	int y=0;
	// FOR(i,N+1)
	// {
	// 	FOR(j,N+1)
	// 	{
	// 		cout << issafe(i,j,Board) << endl;
	// 	}
	// }
	Board[0][0]=0;
	if (foundKT(Board,0,0,1)==true)
	{
		print2d(Board);
	}

	else
	{
		cout << "Not FOund";
	}

}


int main()
{
    solveKT();
    return 0;
}