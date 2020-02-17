//
// Created by Leslie on 2020/2/15.
//

#include <string>
#include <iostream>
#include <memory.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int num = s.size();
        if(num == 0){
            return "";
        }
        bool dp[num][num];
        memset(dp, false, sizeof(dp));
        int pos = 0, len = 0;
        for(int i = 0; i < num; i++) {
            int head, rear;
            head = i;
            rear = i;
            dp[i][i] = true;
            while(i + 1 < num && s[i] == s[i + 1]) {
                rear = i + 1;
                dp[head][rear] = true;
                i++;
            }
            if(rear - head + 1 > len) {
                pos = head;
                len = rear - head + 1;
            }
            for(int j = 1; head - j >= 0 && rear + j < num; j++) {
                if(s[rear + j] == s[head - j] && dp[head - j + 1][rear + j - 1]) {
                    dp[head - j][rear + j] = true;
                    if(2 * j + rear - head + 1 > len){
                        len = 2 * j + rear - head + 1;
                        pos = head - j;
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
    string s1 = "cbababd";
    cout << sol.longestPalindrome(s) << endl;
    cout << sol.longestPalindrome(s1) << endl;
}