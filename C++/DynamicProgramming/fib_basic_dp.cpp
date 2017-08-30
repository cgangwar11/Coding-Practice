#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

void print_map(std::map<int, int>& ma)
{
	std::map<int,int>::iterator A;
	for (A=ma.begin();A !=ma.end();A++)
	{
		cout <<" ("  << A->first << " " <<  A->second << ") ";// cout << A.first << A.second;
	}	
	cout << endl;
}


int fib_mem(int n,map<int,int>& lookup){

	if (n==1 || n==0)
		return 1;
	if (lookup.find(n)!=lookup.end())  return lookup[n];
	cout<<"//";
	print_map(lookup);
	lookup[n]=fib_mem(n-1,lookup)+fib_mem(n-2,lookup);
	print_map(lookup);
	return lookup[n];

}


int fib_tab(int n)
{
	vector<int> tab(n+1,0);
	tab[0]=0;
	tab[1]=1;
	for(int i=2;i<n+1;i++)  tab[i]=tab[i-1]+tab[i-2];

	return tab[n];
}

int main()
{
	vector<int> v(3,0);
	std::vector<int> P(4,0);
	cout << int(v==P);
	map<int,int> A;
	int n=9;
	// cout << fib_tab(n) << " " << fib_mem(n,A);
	return 0;
}