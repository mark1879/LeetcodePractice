#ifndef JUMP_HPP
#define JUMP_HPP

/** 
 *  55. 跳跃游戏
 * 
 *  给定一个非负整数数组 nums ，你最初位于数组的第一个下标 。
    数组中的每个元素代表你在该位置可以跳跃的最大长度。
    判断你是否能够到达最后一个下标。

    提示：  
        1 <= nums.length <= 3 * 104
        0 <= nums[i] <= 105
 */

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

class Jump 
{
public:
   static bool Solution(std::vector<int>& nums) 
    {
        int size = (int)nums.size();
        int right_most = 0;
    
        for (int i = 0; i < size; i++)
        {
            if (i <= right_most)
            {
                right_most = std::max(right_most, i + nums[i]);

                if (right_most >= size - 1)
                    return true;
            }
        }

        return false;
    }

    static void Test()
    {
        std::cout << "Jump::Test()" << std::endl;

        TestCase({2, 3, 1, 1, 4}, true);
        TestCase({3, 2, 1, 0, 4}, false);
    }

private:
    static void TestCase(std::vector<int> nums, bool ans)
    {
        EXPECT_EQ(Solution(nums), ans);
    }
};

#endif