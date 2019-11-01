#include <bits/stdc++.h>

using namespace std;

void print_matrix_details(int m, int n, int** mat) {

	cout<<"\n[Row 0, Col 0] : " << **mat;
	cout<<"\n[Row 0, Col 1] : " << *(*mat + 1);
	cout<<"\n[Row 0, Col 2] : " << *(*mat + 2);


	cout<<"\n[Row 1, Col 0] : " << *(*(mat+1));
	cout<<"\n[Row 1, Col 1] : " << *(*(mat+1) + 1);
	cout<<"\n[Row 1, Col 2] : " << *(*(mat+1) + 2);
	cout<<"\n[Row 1, Col 3] : " << *(*(mat+1) + 3);

	cout<<"\n\n*mat represents the first row. *(*mat) represents the 1st row and 1st column. (written in short as **mat";
	cout<<"\n*(*mat + 1) represents the first row, 2nd column. ";
	cout<<"\n mat+1 will represent the 2nd row";


}

int main() {
	
	int** m1 = new int*[3]; // no of rows

	m1[0] = new int[4]; // no of columns
	m1[1] = new int[4]; // no of columns
	m1[2] = new int[4]; // no of columns
	

	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[0][2] = 3;
	m1[0][3] = 4;
	m1[1][0] = 5;
	m1[1][1] = 6;
	m1[1][2] = 7;
	m1[1][3] = 8;
	m1[2][0] = 9;
	m1[2][1] = 10;
	m1[2][2] = 11;
	m1[2][3] = 12;

	
	print_matrix_details(3, 4, m1);
	return 0;
}
