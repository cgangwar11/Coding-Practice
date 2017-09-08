#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
void print2d(const std::vector<std::vector<int> >& ans)
{
        for(int i=0;i<ans.size();i++)
        {
            for (int j = 0; j < ans[i].size(); ++j)
            {
                cout << ans[i][j] << " "  ;
                /* code */
            }
            // cout << ans[i].size() ;
            cout << endl;
        }
}
void print(vector<int>& A)
{
    FOR(i,A.size())
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
bool invalid(std::vector<vector<int> >& B)
{
    vector<int> indx,indy;
    FOR(i,B.size())
        {
            FOR(j,B.size())
                {
                    if (B[i][j]==1)
                    {
                        indx.push_back(i);
                        indy.push_back(j);
                    }
                }
        }

    FOR(i,indx.size())
        {
            for(int j=i+1;j<indx.size();j++)
                {
                    int x1,y1,x2,y2;
                    x1=indx[i];
                    y1=indy[i];
                    x2=indx[j];
                    y2=indy[j];
                    if (y1==y2)
                        return false;
                    if (abs(x1-x2)==abs(y1-y2))
                        return false;


                }
        }

    return true;
}


void Nqueen(std::vector<vector<int> >& B,int row,vector<int> temp,std::vector<std::vector<int> >& ans)
{

    if (row==B.size())
    {
        // vector<int> pp(temp.begin(),temp.end());
        // print(pp);
        ans.push_back(temp);
        // temp.clear();
        return;
    }




    else{

    FOR(col,B.size())
    {
        // cout << row << " " << col << endl;

        temp.push_back(col);
        B[row][col]=1;
        if (invalid(B))
        {//print2d(B);
            // cout << "**************************" << endl;
            Nqueen(B,row+1,temp,ans);
        }
        // else
        temp.pop_back();
        B[row][col]=0;


    }

}


}


int main()
{

    int n;
    cin >> n;
    vector<vector<int> > A(n,std::vector<int>(n,0));
    vector<int> temp;
    vector<vector<int> > ans;
    // print2d(A);
    // invalid(A,5,5);
    // print2d(A);
    Nqueen(A,0,temp,ans);
    print2d(ans);

    // for====
    return 0;
}
