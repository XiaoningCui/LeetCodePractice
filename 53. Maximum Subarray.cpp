/*
URL: https://leetcode.com/problems/maximum-subarray/
Author: CUI Xiaoning
Date: 2019-08-19
Difficulty: Easy
Tags: Array, Divide and Conquer, Dynamic Programming
*/

/*

Given an integer array nums, find the contiguous subarray (containing at least one number)
 which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution 
using the divide and conquer approach, which is more subtle.

*/

#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

class Solution
{
    public:

    int MaxSubArr(vector<int>& nums)
    {
        // sum：截止到索引i - 1的，nums的最大子序列和
        int sum = nums[0];
        // max：当前出现过的最大的子序列和
        int _max = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            // sum(截止到nums[i - 1]的最大子序列和) + nums[i](索引为i的值)，
            // 与nums[i](索引为i的值)比大小，谁大把谁赋值给sum
            // sum + nums[i]大就说明：持续的累加使sum增大，保留
            // nums[i]大就说明：nums[i]与前面的最大子序列和相加还没有nums[i]自己大，
            // 前面的sum自然要舍弃，将nums[i]赋值为sum
            sum = max(sum + nums[i], nums[i]);
            // 更新sum后，把sum和max中更大那个赋值给max，保持max持续最大
            _max = max(_max, sum);
        }
        return _max;
    }
};