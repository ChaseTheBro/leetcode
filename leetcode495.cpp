#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int lastAttack = 0;
        int attackDuration = 0;
        int result = 0;
        for(int & i : timeSeries){
            attackDuration -= i - lastAttack;
            lastAttack = i;
            if(attackDuration <= 0){
                result += duration;
            }
            else{
                result += duration - attackDuration;
            }
            attackDuration = duration;
        }
        return result;
    }
};

int main() {
    vector<int> timeSeries = {1,2};
    int duration = 2;
    Solution sol;
    cout << sol.findPoisonedDuration(timeSeries, duration) << endl;
}
