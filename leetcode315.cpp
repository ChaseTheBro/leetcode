#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * count 左子树包含节点的数量
     * val 节点的值
     */
    struct TreeNode {
        TreeNode * left;
        TreeNode * right;
        int val;
        int count;
    };
    TreeNode * root = nullptr;
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> temp;
        vector<int> result;

        if(nums.empty())
            return result;

        root = (TreeNode *)malloc(sizeof(TreeNode));
        root->left = nullptr;
        root->right = nullptr;
        root->val = nums.back();
        root->count = 0;
        temp.push_back(0);

        for(auto it = nums.rbegin() + 1; it != nums.rend(); it++){
            temp.push_back(insertNode(root, *it, 0));
        }
        for(auto it = temp.rbegin(); it != temp.rend(); it++){
            result.push_back(*it);
        }
        return result;
    }
    /**
     *
     * @param node 当前遍历到的节点
     * @param val 当前要插入的值，从nums中倒序输入
     * @param prevCount 之前节点左子树节点数和之前遍历的所有比val小的根结点之和
     * @return 右侧小于当前元素的个数
     */
    int insertNode(TreeNode * node, int val, int prevCount){
        // 进入右子树
        if(val > node->val){
            prevCount++;
            if(node->right == nullptr){
                node->right = (TreeNode *)malloc(sizeof(TreeNode));
                node->right->val = val;
                node->right->left = nullptr;
                node->right->right = nullptr;
                node->right->count = 0;
                return prevCount + node->count;
            }
            else{
                return insertNode(node->right, val, node->count + prevCount);
            }
        }
        // 进入左子树
        else{
            node->count += 1;
            if(node->left == nullptr){
                node->left = (TreeNode *)malloc(sizeof(TreeNode));
                node->left->val = val;
                node->left->left = nullptr;
                node->left->right = nullptr;
                node->left->count = 0;
                return prevCount;
            }
            else{
                return insertNode(node->left, val, prevCount);
            }
        }
    }
};

int main(){
    vector<int> num = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
    Solution sol;
    vector<int> result = sol.countSmaller(num);
    for(auto it : result){
        cout << it << endl;
    }
}