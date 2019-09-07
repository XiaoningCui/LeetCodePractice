/*
URL: https://leetcode.com/problems/symmetric-tree/
Author: CUI Xiaoning
Date: 2019-09-02
Difficulty: Easy
Tags: Tree, Depth-first Search, Breadth-first Search
*/

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
*/

/*
Ref
https://www.cnblogs.com/ariel-dreamland/p/9159806.html

Error Testcase
[1]
[1,2,2,null,3,3]
    1
   / \
  2   2
   \ / 
   3 3   
Output-false, Expected-true
*/
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : value(v), left(nullptr), right(nullptr) {}
};


// 判断一个二叉树是否左右对称
class Solution
{
    public:

    // 自定义函数：判断左、右子树是否对称
    // 左子树：左孩子为根节点的子树
    // 右子树：右孩子为根节点的子树
    bool isSymmetric(TreeNode *left, TreeNode *right)
    {
        // 如果左子树根节点，和右子树根节点，同时NULL，对称
        if (left == nullptr && right == nullptr) return true;
        // 如果左、右子树的根节点只有1个为NULL，
        // 或者左右子树根节点值不相等，不对称
        if (left == nullptr || right == nullptr || left->value != right->value) return false;
        // 返回：判断左子树的左子树和右子树的右子树是否对称 && 判断左子树的右子树和右子树的左子树是否对称
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        // 如果根节点为NULL，对称
        if (root == nullptr) return true;
        // 返回自定义函数：判断左右子树是否对称
        return isSymmetric(root->left, root->right);
    }
};

class Solution {
    public:

    bool isSymmetric(TreeNode *root)
    {
        // 如果根节点为NULL，对称
        if (root == NULL) return true;
        // 建立2个队列：q1，存左子树的左孩子、右孩子；q2，存右子树的右孩子、左孩子
        queue <TreeNode*> q1, q2;
        // 根节点左孩子入q1
        q1.push(root->left);
        // 根节点右孩子入q2
        q2.push(root->right);

        // 如果左子树q1和右子树q2没遍历完，则循环
        while (!q1.empty() && !q2.empty())
        {
            // 将q1、q2的头结点，赋值给新创建的2个树节点（分别代表左右子树root节点）
            TreeNode *left = q1.front();
            TreeNode *right = q2.front();
            // 赋值后，将q1、q2的头结点删除
            q1.pop();
            q2.pop();

            // 如果左、右子树的root节点都为NULL，继续循环进行后续判断
            if (left == nullptr && right == nullptr) continue;
            // 如果左右子树的root结点不相等
            if ((left == NULL || right == NULL) || 
                (left->value != right->value))
                // 则不对称
                return false;
            // 如果左右子树的root结点相等，则按顺序推入左右子树的孩子结点进行后续判断
            else
            {
                // 1. 左子树左孩子推入q1（和q2同位置的右子树右孩子对比）
                q1.push(left->left);
                // 2. 左子树右孩子推入q1（和q2同位置的右子树左孩子对比）
                q1.push(left->right);
                // 3. 右子树右孩子推入q2（和q1同位置的左子树左孩子对比）
                q2.push(right->right);
                // 4. 右子树左孩子推入q2（和q1同位置的左子树右孩子对比）
                q2.push(right->left);
            }
        }
        // 持续遍历至循环结束（未发现有不对称情况出现），返回True，即对称
        return true;
    }
};

class Solution
{
    public:

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL) return true;
        // 创建队列q
        queue <TreeNode*> q;
        q.push(root);
        q.push(root);

        while (!q.empty())
        {
            TreeNode *left = q.front();
            q.pop();
            TreeNode *right = q.front();
            q.pop();

            // 如果左、右子树的root节点都为NULL，继续循环进行后续判断
            if (left == nullptr && right == nullptr) continue;
            // 如果左、右子树的root节点不相等
            if ((left == NULL || right == NULL) || 
                (left->value != right->value))
                // 则不对称
                return false;
            // 如果左右子树的root结点相等，则按顺序推入左右子树的孩子结点进行后续判断
            else
            {
                // 1. 左子树左孩子推入q（弹出后，和后面的右子树右孩子对比）
                q.push(left->left);
                // 2. 右子树右孩子推入q（在左子树左孩子弹出后，再弹出并和其对比）
                q.push(right->right);
                // 3. 左子树右孩子推入q（弹出后，和后面的右子树左孩子对比）
                q.push(left->right);
                // 4. 右子树左孩子推入q（在左子树右孩子弹出后，再弹出并和其对比）
                q.push(right->left);
            }
        }
        // 持续遍历至循环结束（未发现有不对称情况出现），返回True，即对称
        return true;
    }
};