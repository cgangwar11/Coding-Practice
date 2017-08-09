#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define RFOR(i,n) for(int j=n;j>-1;j--)
void printvec(vector<int>& A )
{   for(int i=0;i<A.size();i++)
        {cout << A[i] << " " ;}
    cout << endl;
}

void stringopenation(string& A)
{
    A.append(" chandan");
    cout << A << endl;
    A.erase(A.end()-7,A.end());
    cout << A << endl;
    string Q="abc";
    // ss << "." << Q[1];
    // ss << "." << Q[2];
    // Q.insert(1,".");
    // Q.insert(3,".");
    cout << Q << endl;
    string P="A";
    P+="B";
    cout << endl << P;
}




int main()
{   int B[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

    vector<int> A(B,B+15);
    printvec(A);
    cout << endl << A.size();
    string P="ueifdgwefghuerfgeruiyfgeruygferurfgefuygerfyuegfueyfgufgeuyfgverfewrfyugrefuberfvbcjhrvcgfdkdhnfwyfkf";

    stringopenation(P);
    return 0;
}
