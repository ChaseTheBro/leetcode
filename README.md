# LeetCode 题目记录

## [652](https://leetcode-cn.com/problems/find-duplicate-subtrees/) 1.17 [中等]

使用先序遍历将树的每一棵子树所对应的字符串保存到一个map中，之后看这个map中有哪些字符串出现的次数在两次以上，将这些子树的根结点加入到返回值中。

## [315](https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/) 1.18 [困难]

使用二叉树构建输入的数组的倒序二叉树，右侧小于当前元素的个数就是遍历过的较小节点和它们的左子树包含节点数目之和。
