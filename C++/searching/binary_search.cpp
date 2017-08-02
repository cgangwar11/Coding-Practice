#include <bits/stdc++.h>
using namespace std;



int findpivot(const vector<int> &A)
{
    int len=A.size();
    int start=0;
    int end=A.size();
    int ind=-1;
    int pivot=-1;
    while(start<=end)
    {   ind=(start+end)/2;

        if(A[ind]<A[ind-1] && ind==A.size()-1)
        {   pivot=1;
            return ind;
        }


        if(A[ind]<=A[ind+1] && A[ind]<A[ind-1] && ind<A.size()-1)
        {   pivot=1;
            return ind;
        }

        if(A[ind]>=A[0])
        {
            start=ind+1;
        }
        if(A[ind]<=A[len-1])
        {
            end=ind-1;
        }

    }
    if (pivot==-1)
        {return -1;}
    return ind;
}


int search(const vector<int> &A, int B) {

    int d=findpivot(A);
    int start1=0,start2=d,end1=d,end2=A.size();
    int in1=-1,in2=-1;
    while(start1<end1)
    {
        int ind1=(start1+end1)/2;
        if (A[ind1]==B)
            {
                in1=ind1;
                break;
            }
        if (A[ind1]>B) end1=ind1-1;

        if (A[ind1]<B) start1=ind1+1;

    }

    while(start2<end2)
    {
        int ind2=(start2+end2)/2;
        if (A[ind2]==B)
            {
                in2=ind2;
                break;
            }
        if (A[ind2]>B) end2=ind2-1;

        if (A[ind2]<B) start2=ind2+1;

    }


    if (in1==-1)
        return in2;
    return in1;




    return 0;


}

void printvec(vector<int>& A )
{
    for(int it=0;it<A.size();it++)
        cout << A[it] << " ";
    cout << endl;
}

int main()
{

    int K[6]={5,6,7,7,8,3};
    std::vector<int> A(&K[0],&K[6]);
    printvec(A);
    cout << endl;
    cout << search(A,4) << endl;
    return 0;
}
