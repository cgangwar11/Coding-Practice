#include<bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)



int lcs(char X[],char Y[],int m,int n)
{
    if (m==0 or n==0)
        return 0;
    int ans;

    if (X[m-1]==Y[n-1])
    {
        ans=1+lcs(X,Y,m-1,n-1);
    }

    else
        ans=max(lcs(X,Y,m-1,n),lcs(X,Y,m,n-1));

    return ans;

}






int main()
{
   char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";

  int m = strlen(X);
  int n = strlen(Y);

  cout << lcs( X, Y, m, n );

  return 0;
}
