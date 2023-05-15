#ifndef MAX_PROFIT3_HPP
#define MAX_PROFIT3_HPP
/**
 *  123. 买卖股票的最佳时机 III
 * 
 *  给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
    设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

    注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

    提示：
    1 <= prices.length <= 105
    0 <= prices[i] <= 105
*/

#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class MaxProfit3
{
public:
    /**
     * 动态规划
     * 
     * 共5种状态：
     * （1）未进行任何操作；
     * （2）只进行过一次买操作；
     * （3）进行了一次买操作和一次卖操作，即完成了一笔交易；
     * （4）在完成了一笔交易的前提下，进行了第二次买操作；
     * （5）完成了全部两笔交易。
    */
    static int Solution(std::vector<int>& prices)
    {
        if (prices.size() == 0)
            return 0;

        int none = 0;
        int buy1 = -prices[0];
        int sell1 = 0;
        int buy2 = -prices[0];
        int sell2 = 0;

        for (int i = 1, size = (int)prices.size(); i < size; i++)
        {
            buy1 = std::max(buy1, none - prices[i]);
            sell1 = std::max(sell1, buy1 + prices[i]);
            buy2 = std::max(buy2, sell1 - prices[i]);
            sell2 = std::max(sell2, buy2 + prices[i]);
        }

        return sell2;
    }

    static void Test()
    {
        std::cout << "test_max_profit3..." << std::endl;
        TestCase({3, 3, 5, 0, 0, 3, 1, 4}, 6);
        TestCase({1, 2, 3, 4, 5}, 4);
        TestCase({7, 6, 4, 3, 1}, 0);
        TestCase({1}, 0);
    }   

private:
    static void TestCase(std::vector<int> data, int ans)
    {
        EXPECT_EQ(Solution(data), ans);
    }
};


#endif