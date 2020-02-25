//
// Created by Leslie on 2020/2/22.
//

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); i++) {
            umap[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i];
            if(umap.find(remain) == umap.end() || umap.find(remain)->second == i) {
                continue;
            } else {
                result = {i, umap.find(remain)->second};
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    sol.twoSum(nums, 9);
}