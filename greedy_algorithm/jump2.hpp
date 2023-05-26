#ifndef JUMP2_HPP
#define JUMP2_HPP
/**
 *  45. 跳跃游戏 II 
 *
 *  给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
    每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。
    换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
                0 <= j <= nums[i] 
                i + j < n

    返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。

    提示:
        1 <= nums.length <= 104
        0 <= nums[i] <= 1000
        题目保证可以到达 nums[n-1]
 */

#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <gtest/gtest.h>

class Jump2 {
public:
    // 正向查找
    static int Solution1(std::vector<int>& nums) 
    {
        int size = (int)nums.size();
        int right_most = 0;
        int begin = 0;
        int step = 0;

        for (int i = 0; i < size - 1; i++)
        {
            right_most = std::max(right_most, i + nums[i]);

            if (i == begin)
            {
                begin = right_most;
                ++step;
            }
        }

        return step;
    }

    // 反向查找
    static int Solution2(std::vector<int>& nums) 
    {
        int step = 0;
        int start = (int)nums.size() - 1;

        while (start > 0)
        {
            for (int i = 0; i < start; i++)
            {
                if (i + nums[i] >= start)
                {
                    ++step;
                    start = i;
                    break;
                }
            }
        }

        return step;
    }

    static void Test()
    {
        std::cout << "Jump2::Test()" << std::endl;

        TestCase({2, 3, 1, 1, 4}, 2);
        TestCase({2, 3, 0, 1, 3}, 2);
    }

private:
    static void TestCase(std::vector<int> data, int ans)
    {
        EXPECT_EQ(Solution1(data), ans);
        EXPECT_EQ(Solution2(data), ans);
    }

};


#endif