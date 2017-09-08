#include <bits/stdc++.h>
using namespace std;


struct TrieNode
{
    map<char,TrieNode*> child;
    bool last;
}
void make_trie(std::vector<string> A)
{
    TrieNode root;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].length();j++)
        {
            TrieNode* k=new TrieNode;
            if (k.child.find(A[i][j])!=k.child.end())
            {

            }
        }
    }


}



void print_it(unordered_map<string,int>& A)
{
    unordered_map<string,int>::iterator it;

    for(it=A.begin();it!=A.end();it++)
    {
        cout << it->first << " " <<it->second;
    }
}

vector<string> prefix(vector<string> &A) {

    vector<string> ans(A.size(),"_");
    unordered_map<string,int> P;
    int N=A.size();
    int max_len = INT_MAX;
    for(int i=0;i<N;i++)
    {
        int tt=A[i].length();
        max_len=min(tt,max_len);
    }
    for(int j=1;j<max_len;j++)
    {
        for(int i=0;i<N;i++)
            {
                string code(A[i].begin(),A[i].begin()+j);
                if (P.find(code)!=P.end())
                    {
                        P[code]=1;
                    }
                else
                    P[code]++;

            }


    }
    print_it(P);

    return ans;



}
