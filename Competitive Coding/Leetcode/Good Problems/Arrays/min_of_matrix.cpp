/*
Given a matrix. find a maxima

*/

#include <bits/stdc++.h>

using namespace std;

int find_maxima(vector<vector<int>> mat, int start_col, int end_col) {
    int mid_col = (start_col + end_col )/2 
}

int main() {

    vector<vector<int>> mat;
    int row_size, column_size;

    cin >> row_size;
    cin >> column_size;
    int input;
    for (int i =0; i< row_size; ++i) {
        vector<int> new_row;
        for (int j = 0; j < column_size; ++j) {
            cin >> input;
            new_row.push_back(input);
        }

        mat.push_back(new_row);
    }
}