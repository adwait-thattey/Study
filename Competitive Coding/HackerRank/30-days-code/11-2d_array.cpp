#include <iostream>
using namespace std;
int mat[6][6];

int main() {
    for(int i=0;i<6;++i) {
        for(int j=0;j<6;++j) {
            cin>>mat[i][j];
        }
    }
    int cur_sum = 0 , flag=1;
    for(int i=0;i<4;++i) {
        for(int j=0;j<4;++j){
            int temp_sum = 0;
            temp_sum+=mat[i][j] + mat[i][j+1] + mat[i][j+2];
            temp_sum+=mat[i+1][j+1];
            temp_sum+=mat[i+2][j] + mat[i+2][j+1] + mat[i+2][j+2];
            if(flag) {
                cur_sum = temp_sum;
                flag=0;
                continue;
            }
            if(temp_sum > cur_sum)
                cur_sum = temp_sum;
        }
    }

    cout<<cur_sum;
    return 0;
}    