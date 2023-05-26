#ifndef MAX_PROFIT5_HPP
#define MAX_PROFIT5_HPP
#include <iostream>
#include <gtest/gtest.h>
#include <vector>

/**
 *  309. 最佳买卖股票时机含冷冻期
 * 
 *  给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
    设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

    卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
    注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

    提示：
    1 <= prices.length <= 5000
    0 <= prices[i] <= 1000
*/

#include <vector>

class MaxProfit5
{
public:
    static int Solution(std::vector<int>& prices)
    {
        if (prices.size() == 0)
            return 0;

        size_t size = prices.size();

        // dp[i][0] 持有股票的最大收益
        // dp[i][1] 不持有股票，处于冷冻期的最大收益
        // dp[i][2] 不持有股票，不处于冷冻期的最大收益
        std::vector<std::vector<int>> dp(size, std::vector<int>(3));

        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        for (size_t i = 1; i < size; i++)
        {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][1]);         
        }

        return std::max(dp[size - 1][1], dp[size - 1][2]);
    }

    // 优化空间复杂度
    static int Solution2(std::vector<int>& prices)
    {
        if (prices.size() == 0)
            return 0;

        size_t size = prices.size();

        int dp0 = -prices[0];
        int dp1 = 0;
        int dp2 = 0;

        for (size_t i = 1; i < size; i++)
        {
            int tmp0 = std::max(dp0, dp2 - prices[i]);
            int tmp1 = dp0 + prices[i];
            int tmp2 = std::max(dp2, dp1);

            dp0 = tmp0;
            dp1 = tmp1;
            dp2 = tmp2;
        }

        return std::max(dp1, dp2);
    }

    static void Test()
    {
        std::cout << "test_max_profit5..." << std::endl;
        TestCase({1, 2, 3, 0, 2}, 3);
        TestCase({1}, 0);
    }

private:
    static void TestCase(std::vector<int> prices, int ans)
    {
        EXPECT_EQ(Solution(prices), ans);
        EXPECT_EQ(Solution2(prices), ans);
    }
};

#endif