/*
URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Author: CUI Xiaoning
Date: 2019-08-26
Difficulty: Easy
Tags: Array, Dynamic Programming
*/

/*

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(i.e., buy one and sell one share of the stock), design an algorithm 
to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.

Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
    public:
    
    int maxProfit(vector<int>& prices) 
    {
        if (prices.empty() || prices.size() == 1)
        {
            return 0;
        }

        // 历史最大利润（用于返回的结果）：初始化为0
        int max_profit = 0;
        // 历史最低价格：初始化为第0个价格
        int min_price = prices[0];
        
        // 跳过第0个价格，从第一个价格开始循环
        for (int i = 1; i < prices.size(); i++)
        {
            // 如果当日价格比历史最低价格还低
            if (min_price > prices[i])
            {
                // TODO：将当日价格赋值为历史最低价格
                min_price = prices[i];
            }
            // 如果当日价格比历史最低价格高
            else
            {
                // 用当日可获得的最大利润（当日价格 - 历史最低价格）
                // 与历史最大利润比较
                // 谁大就把谁的值赋值给历史最大利润
                max_profit = max(max_profit, prices[i] - min_price);
            }
        }
        return max_profit;
    }
};

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution s;
    std::cout << s.maxProfit(prices) << std::endl;
    std::cout << "_____END_____" << std::endl;
    return 0;
}