/*
URL: https://leetcode.com/problems/maximum-depth-of-binary-tree/
Author: CUI Xiaoning
Date: 2019-09-03
Difficulty: Easy
Tags: Tree, Depth-first Search
*/

/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
*/

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

class Solution {
    public:

    int maxDepth(TreeNode* root) {
        // 如果根节点为NULL，无层数
        if (root == nullptr) return 0;
        // 返回：max(左子树深度, 右子树深度) + 1 (算上当前根节点的深度)
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
