//
// Created by Leslie on 2020/2/19.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

    }
};

int main() {
    Solution sol;
    vector<vector<char>> matrix = {
            {'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','0','1','0'}
    };
    cout << sol.maximalRectangle(matrix) << endl;
}