#include<bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=1;i<n;i++)

//http://www.geeksforgeeks.org/ugly-numbers/



int getNthUglyNo(int n)
{
    vector<int> A(n,0);
    A[0]=1;
    int i2=0,i3=0,i5=0;
    FOR(i,n)
    {
        int k = min(A[i2]*2,min(A[i3]*3,A[i5]*5));
        A[i]=k;
        if (A[i]==A[i2]*2)
        {
            i2+=1;

        }

        if (A[i]==A[i3]*3)
        {
            i3+=1;
        }

        if (A[i]==A[i5]*5)
        {
            i5+=1;
        }

    }

    return A[A.size()-1];
}




int main()
{
    int no = getNthUglyNo(150);
    printf("150th ugly no. is %d ",  no);
    getchar();
    return 0;
}
