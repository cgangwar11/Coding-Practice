#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define RFOR(i,a,n) for(int i=a;i<=n;i++)
vector<int> P;
//https://www.youtube.com/watch?v=3hcaVyX00_4
//http://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0
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
            for(int j=0;j<A[i].size();j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
}



int calc_tab(int n,int k)
{
    vector<vector<int> > A(n+1,vector<int>(k+1,0));                //ne eggs nf floor num to work

    RFOR(ne,1,n)
    {
        RFOR(nf,1,k)
            {
                if (ne==1)
                {
                    A[ne][nf]=nf;
                }

                else if (nf<ne)
                {
                    A[ne][nf]=A[ne-1][nf];
                }

                else
                {
                    int mini=INT_MAX;
                    for (int i=1;i<=nf;i++)
                    {
                        mini=min(1+max(A[ne-1][i-1],A[ne][nf-i]),mini);
                    }

                    A[ne][nf]=mini;

                }

            }

    }
    // print2d(A);
    return A[n][k];



}





int main()
{
    int te;
    cin >> te;
    FOR(i,te)
    {
        int n,k;
        cin >> n;
        cin >> k;
        cout << calc_tab(n,k) << endl;
    }
    return 0;
}
