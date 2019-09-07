/*
URL: https://leetcode.com/problems/binary-tree-level-order-traversal/
Author: CUI Xiaoning
Date: 2019-09-03
Difficulty: Medium
Tags: Tree, Breadth-first Search
*/

/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

/*
Ref
https://blog.csdn.net/zhangyumengs/article/details/80414858
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(NULL), right(NULL) {}
};

class Solution {
    public:

    vector<vector<int>> levelOrder(TreeNode* root) {
        // 定义按层存储树中所有节点的vector V
        vector<vector<int>> V;
        // 如果根节点为NULL，直接返回V
        if (root == NULL) return V;
        // 用队列暂存每一层的节点
        queue<TreeNode*> q;
        // 根节点入队（如果根节点为NULL，则将NULL入队，q中首元素为NULL，即q非空）
        q.push(root);

        // 如果队列不为空，则循环（此循环完成，整个树的遍历结束）
        // 注：如果根节点为NULL且入队，依然会进入此循环
        while (!q.empty()) {
            // 定义存储每一层树节点的vector v
            vector<int> v;

            // 循环，次数为树中每一层的节点个数（此循环完成，树中的一层遍历结束）
            // 每循环完一次，当前层的所有节点都存入v，下一层的所有节点都入队
            for (int s = q.size(); s > 0; s--) {
                // 队列首元素赋值给n（临时变量）
                TreeNode* n = q.front();
                // 首元素出队
                q.pop();
                // 如果n非NULL
                if (n != NULL) {
                    // 存储当前层节点操作：将节点n的值放入存储当前层节点的vector v
                    v.push_back(n->val);
                    // 下一层节点入队操作：如果n的左孩子非NULL，将n的左孩子入队
                    if (n->left != NULL) q.push(n->left);
                    // 下一层节点入队操作：如果n的右孩子非NULL，将n的右孩子入队
                    if (n->right != NULL) q.push(n->right);
                }
            }
            // 将存储当前层节点的vector v，放入存储树中所有层的节点的vector V
            V.push_back(v);
        }
        // 返回树中所有层的节点
        return V;
    }
};