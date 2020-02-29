//
// Created by Leslie on 2020/2/25.
//

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int result = 0;
        unordered_map<char, char> jewels_map;
        for(char i : J) {
            jewels_map[i] = i;
        }
        for(char i : S) {
            if(jewels_map.find(i) != jewels_map.end()) {
                result++;
            }
        }
        return result;
    }
};