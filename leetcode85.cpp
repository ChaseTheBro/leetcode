//
// Created by Leslie on 2020/2/19.
//

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int num = matrix.size(), line = matrix[0].size();
        int result = 0;
        for(int j = 0; j < num; j++){
            int cur = j;
            vector<int> heights(line, 0);
            for(auto row : matrix) {
                if(cur != 0){
                    cur--;
                    continue;
                }
                for(int i = 0; i < line ; i++) {
                    if(row[i] == '1' && heights[i] >= 0) {
                        heights[i] += 1;
                    }
                    else {
                        if(heights[i] == 0 || heights[i] == INT_MIN) {
                            heights[i] = INT_MIN;
                        } else if(heights[i] > 0){
                            heights[i] = -heights[i];
                        }
                    }
                }
            }
            for(int & height : heights) {
                if(height == INT_MIN) {
                    height = 0;
                }
                else if(height < 0) {
                    height = -height;
                }
            }
            int temp = largestRectangleArea(heights);
            if(result < temp) {
                result = temp;
            }
        }
        return result;
    }

    int largestRectangleArea(vector<int> heights) {
        stack<int> s;
        int result = 0;
        heights.push_back(0);
        for(int i = 0; i < heights.size(); i++) {
            while(!s.empty() && heights[s.top()] >= heights[i]) {
                int current = heights[s.top()];
                s.pop();
                int width = 0;
                if(s.empty()) {
                    width = i;
                } else {
                    width = i - s.top() - 1;
                }
                if(current * width > result) {
                    result = current * width;
                }
            }
            s.push(i);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> matrix = {
            {'1','0','1','1','0','1'},
            {'1','1','1','1','1','1'},
            {'0','1','1','0','1','1'},
            {'1','1','1','0','1','0'},
            {'0','1','1','1','1','1'},
            {'1','1','0','1','1','1'}};
    cout << sol.maximalRectangle(matrix) << endl;
}