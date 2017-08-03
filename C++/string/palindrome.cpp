#include <bits/stdc++.h>
using namespace std;




void printvec(vector<int>& A )
{   for(int i=0;i<A.size();i++)
        {
            // cout << i;
            cout << A[i] << " " ;

        }
    cout << endl;
}

int isPalindrome(string A) {
vector<int> B;

int removed=0;
int k=A.length();
for (int i=0;i<A.length();i++)
{
    int it=A[i];
    int a1='a',b1='z',c1='A',d1='Z';

    if((it>=a1 && it<=b1) || (it>=c1 && it<=d1) )
      {

            if (it<a1)
                B.push_back(it-c1+a1);
            else
                B.push_back(it);

        }

    if(it>='0' && it<='9')
    {
        B.push_back(it);
    }
}

k=B.size();
for(int i=0;i<B.size();i++)
{
    if (B[i]!=B[k-i-1])
        return 0;


}
return 1;
}

int main()
{
    string A="A man, a plan, a canal: Panama";
    cout << endl << isPalindrome(A);
    return 0;
}
