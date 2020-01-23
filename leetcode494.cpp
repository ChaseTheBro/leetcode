#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int result = 0;
    int length = 0;
    int findTargetSumWays(vector<int>& nums, int S) {
        length = nums.size();
        getSum(nums, S, 0);
        return result;
    }

    void getSum(vector<int> & nums, long S, int currentLen) {
        if(currentLen == length) {
            if(S == 0) {
                result += 1;
            }
            return;
        }
        getSum(nums, S + nums[currentLen], currentLen + 1);
        getSum(nums, S - nums[currentLen], currentLen + 1);
    }
};

int main() {
    vector<int> nums = {2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53};
    int S = 2147483647;
    Solution sol;
    cout << sol.findTargetSumWays(nums, S) << endl;
}