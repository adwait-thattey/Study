/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
 */

#include <vector>
#include <iostream>

using namespace std;

int singleNumber(vector<int>& nums) {
        int tot_xor = 0;

        for (auto&& x: nums){
            tot_xor ^= x;
        }

        return tot_xor;
}

int main() {
    vector<int> V;
    int size;
    cin >> size;
    for (int i=0;i<size;++i){
        int inp;
        cin >> inp;
        V.push_back(inp);
    }

    cout << singleNumber(V);
    return 0;
}
