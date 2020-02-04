/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9
Output: true
Example 2:

Input:
8 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <array>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {

    array<int, 9> rows {0};    
    array<int, 9> cols {0};
    array<int, 9> squares {0};
    
    for (short rix = 0; rix < 9; ++rix){
        for (short cix = 0; cix < 9; ++cix) {
            if (board[rix][cix] != '.') {
                short num = board[rix][cix] - '0';
                short offset = 1 << num;
                short square_number = 3*(rix/3) + cix/3;
                if( offset & rows[rix] || offset & cols[cix] || offset & squares[square_number])
                    return false;
                
                rows[rix] = rows[rix] | offset;
                cols[cix] = cols[cix] | offset;
                squares[square_number] = squares[square_number] | offset;
            }            
        }
    }

    
    return true;        
}

int main(){
    vector<vector<char>> board;

    for (int i=0;i<9;++i){
        vector<char> sudoku_line;
        string line;
        getline(cin, line);

        stringstream ss(line);
        char temp;
        while (ss >> temp){
            sudoku_line.push_back(temp);
        }

        board.push_back(sudoku_line);
    }

    cout << isValidSudoku(board);
}