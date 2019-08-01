#include <bits/stdc++.h>

using namespace std;


int main() {

	int *pointer;
	long double count = 0;
	while(1){
		try {
			pointer = new int;
			cout<<count++<<"\n";
		}
		catch(std::bad_alloc &ba) {
			cerr<<"Bad Allocation ::"<<ba.what()<<"\n";
			return 0;
		}
	}

	return 0;
}