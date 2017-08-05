#include <bits/stdc++.h>
using namespace std;
void printvec(vector<string>& A )
{   for(int i=0;i<A.size();i++)
        {cout << A[i] << " " <endl};
    cout << endl;
}




string reverse(string& A)
{
    vector<string> X;
    // X.push
    int start=0,end=0;
    // string C(A.rbegin(),A.rend());
    for (int i=0;i<A.length();i++)
    {
        if (i==' ' || i==A.length())
        {   if (i<(A.length()-1))
                end=i-1;
            else
                end=i;
            string temp(A.begin()+start, A.begin()+end);
            X.push_back(temp);
            start=i+1;
        }


    }
    printvec(X);
    // for(vector<string>& it=X.begin();it<X.end();it++)
    //     cout << *it << endl;
    return A;

}








int main()
{
    string A="Dog is man and donkey";
    cout << reverse(A);
    return 0;
}
