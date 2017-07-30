#include <bits/stdc++.h>
using namespace std;

void print_graph(vector<vector<int> >& A)
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<A[0].size();j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
    }
}

//Adjacent Matrix
int main()
{
    int V=4;
    // cin >> V;
    vector<vector<int> > A(4,vector<int> (V,0));

    int E=5;
    for (int i=0;i<E;i++)
    {   int a,b;

        cout << "EDGE " << i ;
        cin >> a >> b;
        A[a-1][b-1]=1;
        A[b-1][a-1]=1;
    }
    print_graph(A);
    return 0;

}
