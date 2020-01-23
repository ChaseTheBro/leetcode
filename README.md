# LeetCode 题目记录

## [652](https://leetcode-cn.com/problems/find-duplicate-subtrees/) 1.17 [中等]

使用先序遍历将树的每一棵子树所对应的字符串保存到一个map中，之后看这个map中有哪些字符串出现的次数在两次以上，将这些子树的根结点加入到返回值中。

## [315](https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/) 1.18 [困难]

使用二叉树构建输入的数组的倒序二叉树，右侧小于当前元素的个数就是遍历过的较小节点和它们的左子树包含节点数目之和。

## [493](https://leetcode-cn.com/problems/reverse-pairs/) 1.19[困难]

题目描述如下：

> 给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。

自然而然的会想到直接遍历两次暴力求解时间复杂度为O(logN^2)，然后可以想到使用归并排序来降低这个暴力算法的时间复杂度，因为归并排序不会影响数组中原本元素的位置关系，而且每次两两合并的数组都是有序的，那么就可以在合并的时候使用二分查找来降低时间复杂度，总的时间复杂度为O((N + LogN)*logN)。

## [494](https://leetcode-cn.com/problems/target-sum/) 1.23[中等]

这道题可以本能的想到使用深度优先搜索来解决，也就是在每一个节点都分支出正和负两种情况，然后分别进行递归求解。

在LeetCode的讨论区看到另一个使用动态规划来解决的思路：

> sum(P)：前面符号为"+"的集合 sum(N)：前面符号为"-"的集合
>
> sum(P) - sum(N) = S
>
> sum(nums) + sum(P) - sum(N) = sum(nums) + S
>
> sum(P) = (sum(nums) + S) / 2
>
> 问题转换为能组合成容量为sum(P)的方式有多少种
