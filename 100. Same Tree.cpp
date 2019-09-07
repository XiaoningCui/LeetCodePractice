/*
URL: https://leetcode.com/problems/same-tree/
Author: CUI Xiaoning
Date: 2019-09-01
Difficulty: Easy
Tags: Tree, Depth-first Search
*/

/*
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
*/

// Definition for a binary tree node.
#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : value(v), left(NULL), right(NULL) { }
};

class Solution {
    public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        else if (p == NULL || q == NULL) return false;
        else if (p->value != q->value) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};