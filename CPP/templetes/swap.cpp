#include <iostream>

using namespace std;

template <class T>
void SWAP(T &a , T &b)
{

	T c;

	c = a;
	a = b;
	b = c;
}

int main() {
	int x=10,y=20;
	float f1 = 10.5 , f2 = 16.8;
	bool B1 = true , B2 = false;
	char c1 = 'a' , c2 = 'b' ; //, str1[100] = "First" , str2[100] = "Second";

	cout<<"After SWAPping : ";
	SWAP(x,y);
	SWAP(f1,f2);
	SWAP(B1,B2);
	SWAP(c1,c2);
	//SWAP(str1,str2);

	cout<<x<<" "<<y;
	cout<<"\n"<<f1<<" "<<f2;
	cout<<"\n"<<B1<<" "<<B2;
	cout<<"\n"<<c1<<" "<<c2;

	return 0;
}