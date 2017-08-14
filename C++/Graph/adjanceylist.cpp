#include <bits/stdc++.h>
using namespace std;

#define pb push_back


int main()
{   int vertex=4,edge=5;
    vector<int> A[10];
    for (int i=1;i<=edge;i++)
    {   int a,b;
        cout << "VERTEX " << i <<" ";
        cin >> a >> b;
        A[a].pb(b);
    }
 for(int i = 1;i <= vertex;++i)
    {
            cout << "Aacency list of node " << i << ": ";
        for(int j = 0;j < A[i].size();++j)
            {
            if(j == A[i].size() - 1)
                    cout << A[i][j] << endl;
            else
                cout << A[i][j] << " --> ";
    }
}

}
