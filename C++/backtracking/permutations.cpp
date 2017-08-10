#include <bits/stdc++.h>
using namespace std;
void print(vector<int>& A )
{   for(int i=0;i<A.size();i++)
        {cout << A[i] << " " ;}
    cout << endl;
}
int generateperm(std::vector<int> A,std::vector<int>& curr,vector<vector<int> >& ans,int size){
	if (curr.size()==size)
	{	print(curr);
		ans.push_back(curr);
		return 0;
	}

	for(int i=0;i<A.size();i++)
	{
		curr.push_back(A[i]);
		std::vector<int> temp=A.erase(A.begin()+i);
		generateperm(temp,curr,ans,size);
		curr.pop_back();
	}
}








int main()
{
	std::vector<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	std::vector<int> curr;
	vector<vector<int> > ans;
	generateperm(A,curr,ans,A.size());
	return 0;
}