#include<bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
void print(vector<int>& A)
{
    FOR(i,A.size())
    {
        cout << A[i] << " ";
    }
}

pair<int,int> find_max_sum_subarray(std::vector<int>& A)
{
    // print(A);
    pair<int,int> cur,global;
    int sglobal,scur;
    sglobal=A[0];
    scur=sglobal;
    cur=make_pair(0,0);
    global=cur;
    for(int i=1;i<A.size();i++)
    {

        if (scur+A[i]>=A[i])
        {
            scur=scur+A[i];
            cur.second=i;
        }

        else
        {
            scur=A[i];
            cur.first=i;
            cur.second=i;
        }




        if (scur>sglobal)
        {
            sglobal=scur;
            global=cur;
        }
        // cout << endl;
        // cout << scur << " " << cur.first << " " << cur.second;
        if (scur==sglobal)
        {
            if (global>cur)
            {
                cur=global;
            }
        }

    }


    return global;





}







pair<int,int> find_max(string s)
{
    vector<int> A;
    for(int i=0;i<s.length();i++)
    {
        if ((char)s[i]==(char)'1')
            A.push_back(-1);
        else
            A.push_back(1);

    }
    pair<int,int> ans = find_max_sum_subarray(A);
    return ans;

}





int main()
{
    string s="010";
    pair<int,int> b = find_max(s);
    cout << b.first << " " << b.second;
    return 0;
}
