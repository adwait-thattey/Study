#include <bits/stdc++.h>
using namespace std;

int main()
{	long long int n = 934261874318,i=1;

	for(;i<=n;++i)
		if((n%i)==0) {cout<<i<<"\n";n/=i;}
	
	
	
	return 0;

}