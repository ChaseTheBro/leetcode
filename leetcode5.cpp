//
// Created by Leslie on 2020/2/15.
//

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int num = s.size();
        bool dp[num][num];
        int pos = 0, len = 0;
        for(int i = 0; i < num; i++) {
            dp[i][i] = true;
            for(int j = 1; i - j >= 0 && i + j < num; j++) {
                if(s[i + j] == s[i - j] && dp[i - j + 1][i + j - 1]) {
                    dp[i - j][i + j] = true;
                    if(2 * j + 1 > len){
                        len = 2 * j + 1;
                        pos = i - j;
                    }
                }
            }
        }
        return s.substr(pos, len);
    }
};

int main()
{
    Solution sol;
    string s = "bczabazcd";
    cout << sol.longestPalindrome(s) << endl;
}