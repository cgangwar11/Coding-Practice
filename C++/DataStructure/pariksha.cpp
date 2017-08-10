#include <bits/stdc++.h>
using namespace std;

int findmax(int value)
{

	if (value<10)
		return value;
	int sum=findmax(value/2)+findmax(value/3)+findmax(value/4);
     if (sum>value)
          return sum;
     else
          return value;
}

int main()
{
	cout << findmax(2000);

	return 0;
}