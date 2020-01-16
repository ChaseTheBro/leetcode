# LeetCode 题目记录

## [652](https://leetcode-cn.com/problems/find-duplicate-subtrees/) 1.17

使用先序遍历将树的每一棵子树所对应的字符串保存到一个map中，之后看这个map中有哪些字符串出现的次数在两次以上，将这些子树的根结点加入到返回值中。
