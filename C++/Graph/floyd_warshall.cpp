#include <bits/stdc++.h>
using namespace std;
#define INF 500000
int print2dvec(vector<vector<int> >& A)
{
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
            {
                cout << A[i][j] << " " ;
            }
        cout << endl;
    }
}

void floydWarshall(int graph[][4])
{	
	int V=4;

	for(int k=0;k<V;k++)
	{
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				if (graph[i][j]>graph[i][k]+graph[k][j])
				{
					graph[i][j]=graph[i][k]+graph[k][j];
				}
			}
		}
	}
	for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				cout << graph[i][j] << " " ;
			}
			cout << endl;
		}

}



int main()
{
	int V=4;

    int graph[4][4] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };

    // Print the solution
    floydWarshall(graph);
    return 0;
}