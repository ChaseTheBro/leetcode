//
// Created by Leslie on 2020/2/29.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * l1_head = l1, * l2_head = l2;
        ListNode * result = nullptr, *current_node = nullptr;
        int advance = 0;
        while(l1_head != nullptr || l2_head != nullptr || advance != 0) {
            int num1 = 0, num2 = 0, current = 0;
            if(l1_head != nullptr) {
                num1 = l1_head->val;
            }
            if(l2_head != nullptr) {
                num2 = l2_head->val;
            }
            if(l1_head != nullptr)
                l1_head = l1_head->next;
            if(l2_head != nullptr)
                l2_head = l2_head->next;
            current = num1 + num2 + advance;
            if(current >= 10){
                advance = 1;
                current -= 10;
            }else{
                advance = 0;
            }

            if(result == nullptr) {
                result = new ListNode(current);
                current_node = result;
            } else {
                current_node->next = new ListNode(current);
                current_node = current_node->next;
            }
        }
        return  result;
    }
};

int main() {
    Solution sol;
    ListNode l1(4);
    ListNode l2(6);
    cout << sol.addTwoNumbers(&l1, &l2) << endl;
}