#include<bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
void print(vector<int>& A)
{
    FOR(i,A.size())
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int findmin(vector<int>& A)
{
    int n=A.size();

    vector<int> DP(0,n);

    FOR(i,A.size())




}













int main()
{
    int n;
    cin >> n;
    FOR(i,n)
        {
            int k;
            cin >> k;
            vector<int> mat;
            FOR(j,k)
            {
                int temp;
                cin >> temp;
                mat.push_back(temp);
            }

            cout << findmin(mat) << endl;
        }
}
