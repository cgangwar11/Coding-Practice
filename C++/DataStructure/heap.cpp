#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define RFOR(i,n) for(int j=n;j>0;j--)
#define pb push_back
void printvec(vector<int>& A )
{   for(int i=0;i<A.size();i++)
        {cout << A[i] << " " ;}
    cout << endl;
}
void max_heapify(std::vector<int>& A,int i,int N)
{
    int left=2*i;
    int right=2*i+1;
    int largest;
    if (right>N) return;
    if (left<=N && A[left]>A[i])
    {
        largest=left;
    }
    else largest=i;

    if (right<=N && A[right]>A[largest])
    {
        largest=right;
    }

    if (largest!=i)
    {// printvec(A);
    swap(A[i],A[largest]);
    max_heapify(A,largest,N);
}

}
void build_heap(std::vector<int>& A,int N)
{
    // int N=A.size();
    // for(int i=A.size();i>0;i++)
    for(int i=N/2;i>0;i--)
    {
        max_heapify(A,i,N);
    }
    // A.pop_fro

}
void heap_sort(vector<int>& A)
{  A.insert(A.begin(),-1);
    printvec(A);
    // int N=A.size();
    for(int i=A.size();i>1;i--)
    {
        build_heap(A,i);
        swap(A[1],A[i]);
    }
    // // }
    // A.pop_front();

}




int main()
{   //int B[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector<int> A;
    int N=25;
    RFOR(j,N) A.pb(j);
    N=A.size();
    printvec(A);
    // max_heapify(A,1,20);
    heap_sort(A);
    // heap_sort(A);
    printvec(A);

    return 0;
}
