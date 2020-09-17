/*

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <array>

#include "./matutils.cpp"

using namespace std;

void swap(int& a , int& b){
    int temp = b;
    b = a;
    a = temp;
}


void noSpaceRotation(vector<vector<int>>& matrix) {
    int N = matrix.size();

    // get transpose
    for (int i=0;i<N;++i) {
        for (int j=0;j<i;++j){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // change rows
    for(int i=0;i<N;++i){
        for (int j=0; j< N/2; ++j){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][N - 1 - j];
            matrix[i][N-1-j] = temp;
        }
    }
}

void useSpaceRotation(vector<vector<int>>& matrix) {

    int N = matrix.size();

    for(int start=0, end=N-1;start*2 < end;start++){

        // start taking in groups of 4
        for(int x=start,y=start;y<end-start;++y) {

            // 4 pairs are: x,y | y,end-x | end-x,end-y | end-y,x

            int temp = matrix[end-y][x];
            matrix[end-y][x] = matrix[end-x][end-y];
            matrix[end-x][end-y] = matrix[y][end-x];
            matrix[y][end-x] = matrix[x][y];
            matrix[x][y] = temp; 
        }
    }

}

void rotate(vector<vector<int>>& matrix) {
    
    noSpaceRotation(matrix);

}

int main(){
    vector<vector<int>> mat = input_mat<int>(4,4);
    print_mat(mat);
    rotate(mat);
    cout << "\n\n";
    print_mat(mat);
}