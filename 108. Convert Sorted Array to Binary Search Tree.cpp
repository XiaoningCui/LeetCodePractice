/*
URL: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
Author: CUI Xiaoning
Date: 2019-09-05
Difficulty: Easy
Tags: Tree, Depth-first Search
*/

/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
 */

# include <iostream>
# include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

/*
class TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v, TreeNode* l, TreeNode* r) {
        this->val = v; 
        this->left = l;
        this->right = r;
    }
};
*/
class Solution {
    public:

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // 如果数组的头和尾相等，说明数组为空，即返回NULL
        if (nums.empty()) return NULL;
        int middleIndex = (0 + nums.size()) >> 1;
        // 创建一棵树root（根节点），值为nums中间位置的值
        TreeNode* root = new TreeNode(nums[middleIndex]);
        // 提取出用于创建root左子树的新数组
        // 新数组的元素：从原数组的首元素，到原数组的中间元素的前一个元素
        vector <int> l = vector <int> (nums.begin(), nums.begin() + middleIndex);
        // 提取出用于创建root右子树的新数组
        // 新数组的元素：从原数组的中间元素的后一个元素，到原数组的末尾元素
        vector <int> r = vector <int> (nums.begin() + middleIndex + 1, nums.end());
        // 递归创建root的左子树
        root->left = sortedArrayToBST(l);
        // 递归创建root的右子树
        root->right = sortedArrayToBST(r);
        // 返回树的根节点
        return root;
    }
};

class Solution {
    public:

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // 给定数组、起始元素的索引0、数组尺寸，建立树
        return _buildTree(nums, 0, nums.size());
    }

    private:

    TreeNode* _buildTree(const std::vector<int>& nums, int begin, int end) {
        // 如果数组尺寸，同起始元素索引，即0，相等，说明数组尺寸为0，没有元素，返回NULL
        if (begin == end) return NULL;
        // 找到数组的中间位置，即要创建的树的根节点（因为题设是根节点在中间）
        // 将一个数的二进制表示右移一位，相当于，这个数除以2并向下取整
        // middle也就是数组最中间元素的索引
        int middle = (begin + end) >> 1;
        // 或者写成int middle = (begin + end) / 2;
        // 创建一棵树root（根节点），值为nums中间位置元素的值
        TreeNode* root = new TreeNode(nums[middle]);
        // 从middle处，数组被分开两半
        // root的左子树根据数组的左半部分继续递归创建
        root->left = _buildTree(nums, begin, middle);
        // root的右子树根据数组的右半部分继续递归创建
        root->right = _buildTree(nums, middle + 1, end);
        // 返回根节点
        return root;
    }
};