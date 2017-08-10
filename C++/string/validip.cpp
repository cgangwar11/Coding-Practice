
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define RFOR(i,n) for(int j=n;j>-1;j--)
void printvec(vector<int>& A )
{   for(int i=0;i<A.size();i++)
        {cout << A[i] << " " ;}
    cout << endl;
}
bool isvalid(string& P)
{   cout << P << endl;
    istringstream f(P);
    string temp;
    // string k=strtok(P,'.');
    while(getline(f,temp,'.'))
        {
            if(atoi(temp.c_str())>255 || atoi(temp.c_str())<0 || (temp.c_str()[0]=='0' && temp.length()>1)) return false;

        }
        // cout << endl;
    return true;
}

int main()
{
    string A="0100100";
    vector<string> ans;
    int l=A.length();
    // if (l)
    for(int i=1;i<l;i++)
        {
            for(int j=i+1;j<l;j++)
                {
                    for(int k=j+1;k<l;k++)
                        {

                                {
                                    // cout << i << j << k  << endl;
                                    string B=A;
                                    B.insert(i,".");
                                    B.insert(j+1,".");
                                    B.insert(k+2,".");
                                    if (isvalid(B)) cout << B << "  sdsd"<<endl;
                                    // B.insert(l+3,".");
                                    // cout << B << endl;
                                }
                        }
                }
        }
    return 0;
}


