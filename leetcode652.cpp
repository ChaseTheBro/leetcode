#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    map<string, vector<TreeNode * >> treeMap;
    vector<TreeNode * > findDuplicateSubtrees(TreeNode * root) {
        buildTreeMap(root);
        vector<TreeNode * > result;

        for(auto it : treeMap){
            if(it.second.size() > 1){
                result.push_back(it.second.back());
            }
        }

        return result;
    }

    string buildTreeMap(TreeNode * node){
        if(node == nullptr){
            return "N";
        }
        string left = buildTreeMap(node->left);
        string right = buildTreeMap(node->right);
        string current = to_string(node->val) + left + right;
        treeMap[current].push_back(node);
        return current;
    }
};

int main()
{
    TreeNode * root;
    vector<TreeNode *> list;
    TreeNode node(1);
    TreeNode node2(2);
    TreeNode node3(4);
    TreeNode node4(4);
    TreeNode node5(4);
    root = &node;
    root->left = &node2;
    root->right = &node3;
    node2.right = &node4;
    node4.right = &node5;
    Solution sol;
    list = sol.findDuplicateSubtrees(root);
    for(auto it : list){
        cout << it->val << endl;
    }
}
