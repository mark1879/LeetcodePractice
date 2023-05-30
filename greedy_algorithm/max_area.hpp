#ifndef MAX_AREA_HPP
#define MAX_AREA_HPP
/**
    11. 盛最多水的容器

    给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
    找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。返回容器可以储存的最大水量。

    提示：
    n == height.length
    2 <= n <= 105
    0 <= height[i] <= 104
 */

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

class MaxArea 
{
public:
    static int Solution1(std::vector<int>& height) 
    {
        int size = (int)height.size();
        int max_area = 0;

        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                max_area = std::max(max_area, (j - i) * std::min(height[i], height[j]));
            }
        }

        return max_area;
    } 

    static int Solution2(std::vector<int>& height) 
    {
        int max_area = 0;
        int left = 0;
        int right = (int)height.size() - 1;

        while (left < right)
        {
            max_area = std::max(max_area, std::min(height[left], height[right]) * (right - left));

            if (height[left] <= height[right])
                ++left;
            else
                --right;
        }

        return max_area;
    }

    static int Solution3(std::vector<int>& height) 
    {
        int max_area = 0;
        int left = 0;
        int right = (int)height.size() - 1;

        while (left < right)
        {
            max_area = std::max(max_area, (right - left) * std::min(height[left], height[right]));

            if (height[left] <= height[right])
            {
                int tmp = height[left];
                while (++left < right && height[left] <= tmp)
                    ;
            }
            else
            {
                int tmp = height[right];
                while (--right > left && height[right] <= tmp)
                    ;
            }
        }

        return max_area;
    }

    static void Test() 
    {
        std::cout << "MaxArea::Test()" << std::endl;

        TestCase({1, 8, 6, 2, 5, 4, 8, 3, 7}, 49);
        TestCase({1, 1}, 1);
        TestCase({2, 3, 4, 5, 18, 17, 6}, 17);
    }

private:
    static void TestCase(std::vector<int> vec, int ans) 
    {
        EXPECT_EQ(Solution1(vec), ans);
        EXPECT_EQ(Solution2(vec), ans);
        EXPECT_EQ(Solution3(vec), ans);
    }
};

#endif