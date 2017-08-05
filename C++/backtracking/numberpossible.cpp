#include <bits/stdc++.h>
using namespace std;
void print(vector<int>& A )
{   for(int i=0;i<A.size();i++)
        {cout << A[i] << " " ;}
    cout << endl;
}
void print2d(vector<vector<int> >& A )
{   for (int j=0;j<A.size();j++)
    {
    for(int i=0;i<A[0].size();i++)
        {cout << A[j][i] << " " << endl;}
    cout << endl;

    }
}
void combs(string S,vector<string> mapi,string& curr,std::vector<string>& ans,int index)
{
    if(index==S.length())
    { //  cout << curr << endl;
        ans.push_back(curr);
        // curr="";
        return ;
    }

    for(int i=0;i<mapi[S[index]-(int)'0'].length();i++)
    {
        curr.push_back(mapi[S[index]-(int)'0'][i]);
        cout << curr;
        combs(S,mapi,curr,ans,index+1);
        curr.erase(index);

    }
}

int main()
{
    vector<string> mapi;
    mapi.push_back("0");
    mapi.push_back("1");
    mapi.push_back("abc");
    mapi.push_back("def");
    mapi.push_back("ghi");
    mapi.push_back("jkl");
    mapi.push_back("mno");
    mapi.push_back("pqrs");
    mapi.push_back("tuv");
    mapi.push_back("wxyz");
    // unordered_mapi <int,string> A;
    vector<string> ans;
    string curr;
    string S="123456";
    combs(S,mapi,curr,ans,0);
    cout << endl;
    for (std::vector<string>::iterator i = ans.begin(); i != ans.end(); ++i)
    {
        cout << *i << endl;
    }
    return 0;
}



