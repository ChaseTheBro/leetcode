#include <vector>
#include <iostream>

using namespace std;

vector<int> numList = {1, 1, 1, 3, 5, 6, 8, 2, 3, 1, 8, 1, 2};

vector<int> standardList = {1, 7, 2, 4, 1, 5, 3};

bool findSubList(vector<int> inputList, int A) {
    vector<int> processInputList;
    vector<int> processStandardList;
    for(auto i : inputList) {
        if(i < A) {
            processInputList.emplace_back(i);
        }
    }
    for(auto i : standardList) {
        if(i < A) {
            processStandardList.emplace_back(i);
        }
    }
    for(int i = 0; i < processInputList.size(); ++i) {
        int iter = i;
        int j;
        for(j = 0; j < processStandardList.size(); ++j) {
            if(processInputList[iter] != processStandardList[j]) {
                break;
            } else {
                iter++;
            }
        }
        if(j == processStandardList.size()) {
            return true;
        }
    }
    return false;
}

int main() {
    if(findSubList(numList, 3)) {
        cout << "OK" << endl;
    }
}