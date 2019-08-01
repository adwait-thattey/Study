#include <iostream>
using namespace std;

union intAndChar {
	int i; //int takes 4 bytes
	char ch[4]; //char takes 1 byte. Thus total = 4*1= 4
};

int main() {

	intAndChar IC;
	/*IC.i = 10;
	cout<<IC.ch[0]<<" "<<IC.ch[1]<<" "<<IC.ch[2]<<" "<<IC.ch[3];
	IC.ch[1] = 'x';*/
	IC.ch[0] = '1';//49 = 00110001
	IC.ch[0] = '2';//50 = 00110010
	IC.ch[0] = '3';//51 = 00110011
	IC.ch[0] = '4';//52 = 00110100
	cout<<IC.i;

	return 0;
}