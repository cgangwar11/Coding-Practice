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
#define INF INT_MAX
typedef pair<int,int> pii;
typedef pair<int,pii> pipii;
void print(vi&);
void print2d(vii& );
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

int main(){

}
