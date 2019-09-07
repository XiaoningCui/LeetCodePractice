/*
URL: https://leetcode.com/problems/minimum-depth-of-binary-tree/
Author: CUI Xiaoning
Date: 2019-09-01
Difficulty: Easy
Tags: Tree, Depth-first Search, Breadth-first Search
*/

/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
*/

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : value(v), left(NULL), right(NULL) { }
};

class Solution
{
    public:

    int minDepth(TreeNode *root)
    {
        // root节点不存在，深度为0
        if (root == NULL) return 0;
        // 如果root节点的左右孩子节点：同时存在
        if (root->left != NULL && root->right != NULL)
            // 最小深度 = min(左子树深度, 右子树深度) + 1（当前root节点深度）
            // 因为左右子树同时存在，所以哪边浅，就返回哪边的深度，所以用min
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        // 如果root节点的左右孩子节点：不同时存在
        else
            // 最小深度 = max(左子树深度, 右子树深度) + 1（当前root节点深度）
            // 因为左右子树不同时存在，为了探索叶子节点深度，
            // 所以要选择包含孩子节点的长边继续向下递归，所以用max
            return max(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

class Solution {
	public:
    
    int minDepth(TreeNode *root) {
		if(root == NULL) return 0;
		int l = minDepth(root->left);
		int r = minDepth(root->right);

		if(l == 0) return 1 + r;
		if(r == 0) return 1 + l;
		else return 1 + min(l,r);
	}
};