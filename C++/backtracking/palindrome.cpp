#include<bits/stdc++.h>
using namespace std;

void print2d(const std::vector<std::vector<string> >& ans)
{
	    for(int i=0;i<ans.size();i++)
    	{
    		for (int j = 0; j < ans[i].size(); ++j)
    		{
    			cout << ans[i][j] << " "  ;
    			/* code */
    		}
    		cout << ans[i].size() ;
    		cout << endl;
    	}
}
int ispalindrome(string A)
{   if(A.length()==1)
        return 1;
    if(A.length()==1)
        return 0;
    // cout << A << endl;
    string B(A.rbegin(),A.rend());
    // cout << B ;
    // cout << A;
    if (B==A)
        return 1;
    else
        return 0;
}
void part(const string& S,int index,vector<string>& curr,vector<vector<string> >& ans)
{   

    if(index>=S.length())

    	{	if(S!="")
    			curr.push_back(S);
    		ans.push_back(curr);
    		if(S!="")
    			curr.pop_back();
    		return;
    	}

    for(int i=0;i<S.length();i+=1)    
    {

        string P(S.begin(),S.begin()+i+1);
        string Q(S.begin()+i+1,S.end());


        index=i;
        if(ispalindrome(P))
			{
				curr.push_back(P);
	       		part(Q,index+1,curr,ans);
	        	curr.pop_back();
	    	}
        
    }
    // index=0;
    // part(S,length-1,index,curr,ans);
    
    
}

void partition(string A)
 {
  vector<vector<string> > ans;
  vector<string> curr;
  int size;
//   cout << ispalindrome("aa");
  	part(A,0,curr,ans);

    // cout << ans.size() << endl;
    print2d(ans);
}



int main()
{

    string str = "nitish";
    // string p(str.begin(),str.begin()+2);
    // string q(str.begin()+2,str.end());
    // cout << p << "  " << q <<  endl;
    partition(str);
    return 0;
}