#include <bits/stdc++.h>

using namespace std;

float divide(float a,float b) {

	if(b==0) {
		throw "Fuck You";
	}

	return a/b;
}
int main() {

	float a,b;
	cout<<"Enter 2 Numbers";

	cin>>a;
	cin>>b;

	try {
/*		float c = divide(a,b);
		cout<<c;	
*/
		if(b==0) {
			throw "Fuck You";
		}

		cout<<a/b;
	}

	catch(const char *msg) {
		cout<<msg;
	}
	return 0;
}