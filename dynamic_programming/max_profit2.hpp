#ifndef MAX_PROFIT2_HPP
#define MAX_PROFIT2_HPP
/**
 * 122. 买卖股票的最佳时机 II
 * 
 *  给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
    在每一天，你可以决定是否购买和/或出售股票。你在任何时候最多只能持有一股股票。你也可以先购买，然后在同一天出售。
    返回 你能获得的 最大 利润 。
    
    注意：可多次交易, 这是与第一道题不同的原因。

    提示：
    1 <= prices.length <= 3 * 104
    0 <= prices[i] <= 104
*/

#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class MaxProfit2
{
public:
    /**
     * 动态规划
     * 
     * dp[i][0] 表示当天手里没有股票的最大收益，
     * dp[i][1] 表示当天手里有一只股票的最大收益。
    */
    static int Solution(std::vector<int>& prices)
    {
        if (prices.size() == 0)
            return 0;

        int size = (int)prices.size();
        int max_profit[size][2];
        
        max_profit[0][0] = 0;
        max_profit[0][1] = -prices[0];

        for (int i = 1; i < size; i++)
        {
            max_profit[i][0] = std::max(max_profit[i - 1][0], max_profit[i - 1][1] + prices[i]);
            max_profit[i][1] = std::max(max_profit[i - 1][1], max_profit[i - 1][0] - prices[i]);
        }

        return max_profit[size - 1][0];
    }

    /**
     * 动态规划，优化空间复杂度
    */
    static int Solution2(std::vector<int>& prices)
    {
        if (prices.size() == 0)
            return 0;

        int size = (int)prices.size();
        int profit_0 = 0;
        int prifit_1 = -prices[0];

        for (int i = 1; i < size; i++)
        {
            profit_0 = std::max(profit_0, prifit_1 + prices[i]);
            prifit_1 = std::max(prifit_1, profit_0 - prices[i]);
        }

        return profit_0;
    }

    /**
     * 贪心算法
     * 
     * 由于股票的购买没有限制，因此整个问题等价于寻找 n 个不相交的区间[prices[i], prices[i - 1]]
     * 的和的最大化
    */
   static int Solution3(std::vector<int>& prices)
   {
        if (prices.size() == 0)
            return 0;

        int profit = 0;
        
        for (int i = 1, size = (int)prices.size(); i < size; i++)
        {
            profit += std::max(0, prices[i] - prices[i - 1]);
        }

        return profit;
   }

    static void Test()
    {
        std::cout << "test_max_profit2..." << std::endl;
        TestCase({7, 1, 5, 3, 6, 4}, 7);
        TestCase({1, 2, 3, 4, 5}, 4);
        TestCase({7, 6, 4, 3, 1}, 0);
    }   

private:
    static void TestCase(std::vector<int> data, int ans)
    {
        EXPECT_EQ(Solution(data), ans);
        EXPECT_EQ(Solution2(data), ans);
        EXPECT_EQ(Solution3(data), ans);
    }
};


#endif