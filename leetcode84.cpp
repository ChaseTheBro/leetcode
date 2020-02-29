//
// Created by Leslie on 2020/2/22.
//

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
    vector<int> heights = {1,2,3,4,5,6};
    Solution sol;
    cout << sol.largestRectangleArea(heights) << endl;
}