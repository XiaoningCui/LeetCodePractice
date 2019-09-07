/*
URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
Author: CUI Xiaoning
Date: 2019-09-07
Difficulty: Easy
Tags: Array, Greedy
*/

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

/*
逻辑：
1. 如果第i+1天价格“大于”第i天的价格，则第i天时buy；
2. 如果第i+1天价格“等于”第i天的价格，则第i天hold；
3. 如果第i+1天价格“小于”第i天的价格，则第i天时sell。

整理逻辑：如果后一天价格大于前一天价格，就将差价累加进要返回的结果。
*/
# include <iostream>
# include <vector>
using namespace std;

class Solution {
    public:

    int maxProfit(const std::vector<int>& prices) {
        // 如果数组为空或者只有一个元素，返回0，即无最大利润。
        if (prices.empty() || prices.size() == 1) return 0;
        // 最大利润，用于返回的结果
        int maxProfit = 0;
        // 从数组的第1个价格，循环到倒数第2个价格
        for (int i = 0; i < prices.size() - 1; i++) {
            // 如果后一天价格大于前一天，就将前后这两天的差价加到maxProfit中
            // 即相当于进行一次买卖：第i-1天买，第i天卖
            if (prices[i] < prices[i + 1]) maxProfit += prices[i + 1] - prices[i];
        }
        // 返回最终累加的所有低买高卖的差价
        return maxProfit;
    }
};

int main(int argc, char* argv[])
{
    vector<int> prices = {};
    Solution s;
    cout << s.maxProfit(prices) << endl;
    cout << "_____END_____" << endl;
    return 0;
}