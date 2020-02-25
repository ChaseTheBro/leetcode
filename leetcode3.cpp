//
// Created by Leslie on 2020/2/25.
//

#include <string>
#include <iostream>
#include <unordered_map>

using namespace  std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> sub_map;
        int pos = 0;
        int result = 0;
        for(int i = 0; i < s.size(); i++) {
                if(sub_map.find(s[i]) != sub_map.end() && sub_map.find(s[i])->second > pos) {
                    pos = sub_map.find(s[i])->second;
                }
                cout << i << " " << pos << endl;
                if(i - pos + 1 > result) {
                    result = i - pos + 1;
                }
                sub_map[s[i]] = i + 1;
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") << endl;
}