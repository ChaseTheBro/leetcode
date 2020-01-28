//
// Created by Leslie on 2020/1/23.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for(int i : nums1){
            auto pos = findPos(i, nums2);
            if(pos != nums2.end()){
                result.push_back(*pos);
            }
            else{
                result.push_back(-1);
            }
        }
        return result;
    }

    vector<int>::iterator findPos(int val, vector<int> & nums2){
        auto iter = nums2.begin();
        bool flag = false;
        while(iter != nums2.end()){
            if(*iter == val && !flag){
                flag = true;
            }
            if(*iter > val && flag){
                return iter;
            }
            iter++;
        }
        return iter;
    }
};

int main() {
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> result;
    Solution sol;
    result = sol.nextGreaterElement(nums1, nums2);
    for(int i : result){
        cout << i << endl;
    }
}
