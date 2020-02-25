# LeetCode 题目记录

## [652](https://leetcode-cn.com/problems/find-duplicate-subtrees/) 1/17 [中等]

使用先序遍历将树的每一棵子树所对应的字符串保存到一个map中，之后看这个map中有哪些字符串出现的次数在两次以上，将这些子树的根结点加入到返回值中。

## [315](https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/) 1/18 [困难]

使用二叉树构建输入的数组的倒序二叉树，右侧小于当前元素的个数就是遍历过的较小节点和它们的左子树包含节点数目之和。

## [493](https://leetcode-cn.com/problems/reverse-pairs/) 1/19[困难]

题目描述如下：

> 给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。

自然而然的会想到直接遍历两次暴力求解时间复杂度为O(logN^2)，然后可以想到使用归并排序来降低这个暴力算法的时间复杂度，因为归并排序不会影响数组中原本元素的位置关系，而且每次两两合并的数组都是有序的，那么就可以在合并的时候使用二分查找来降低时间复杂度，总的时间复杂度为O((N + LogN)*logN)。

## [494](https://leetcode-cn.com/problems/target-sum/) 1/23[中等]

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

## [495](https://leetcode-cn.com/problems/teemo-attacking/) 1/23[中等]

英雄联盟伤害计算相关的问题，只要玩过游戏的应该都很容易解决。

## [496](https://leetcode-cn.com/problems/next-greater-element-i/) 1/26[简单]

直接遍历就可以得到结果，非常简单

## [5](https://leetcode-cn.com/problems/longest-palindromic-substring/) 2/17[中等]

一道经典的动态规划问题，首先想到这个问题可以这样划分为子问题，首先回文子串去掉首尾之后的字串也一定是回文子串，所以使用一个二维数组来存放确认是回文子串的所有子串，当需要判定一个子串是否是回文子串的时候就在这个二维数组中进行查找，当一个新的子串确定是回文子串之后，就更新这个二维数组。

## [53](https://leetcode-cn.com/problems/maximum-subarray/) 2/18[简单]

经典的求连续子串中最大的和的问题，容易想到一个O(N)的解决方法，那就是用一个计数器来保存目前的加和情况，然后将它和暂定的结果相对比，如果这个计数器是正的话，就加上当前便利到的数，如果计数器为负那么就重置计数器为当年遍历到的数字。每遍历到一个数就比较计数器和返回值的大小，最终可以得到最大连续子串的值。

# [84](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/) 2/22[困难]

维护一个栈，里面存储柱状图的高度信息的顺序，当遇到一个比当前栈顶对应的高度更小的柱状图的时候就不断的出栈，直到栈为空或者当前的栈顶小于或等于当前的柱状图的高度，每次出栈的时候计算出栈元素到当前位置能够构成的最大矩形的面积。当对柱状图的高度遍历完成的时候就得到了能够构成的最大矩形的大小。

# [85](https://leetcode-cn.com/problems/maximal-rectangle/) 2/22[困难]

这道题可以使用84题中用过的那个用栈的函数，这个问题可以转换为每行中每一列对应高度的柱状图可以产生的最大面积的大小，对每一行的情况都更新一次最大值就可以得到结果。

# [1](https://leetcode-cn.com/problems/two-sum/) 2/25[简单]

这道题首先容易想到一个时间复杂度为O(N^2)的暴力算法，然后可以想到使用一个hash table来用空间换时间，将查找的时间缩短到O(1)，节约了查找的时间。
