#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define pb push_back
// #define FOR(i,j) for(int i;i<j;i++)

#define all(v) v.begin(),v.end()
#define loop(x,n) for(int x = 0; x < n; ++x)


int main()

{   int vertex,edge;
    cin >> vertex >> edge;
    vector<int> A[10];
    for (int i=1;i<=edge;i++)
    {   int a,b;
        // cout << "VERTEX " << i <<" ";
        cin >> a >> b;
        A[a].pb(b);
        A[b].pb(a);
    }

    int Q;
    cin >> Q;
    loop(i,Q)
    {
        int a,b;
        cin >> a >> b;
        if (find(A[a].begin(),A[a].end(),b)!=A[a].end())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }



}
