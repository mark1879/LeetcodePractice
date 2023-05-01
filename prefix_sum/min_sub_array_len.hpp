#ifndef MIN_SUB_ARRAY_LEN
#define MIN_SUB_ARRAY_LEN
#include <iostream>
#include <gtest/gtest.h>

/**
 *  209. 长度最小的子数组
 *  给定一个含有 n 个正整数的数组和一个正整数 target 。
    找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

    示例 1：
    输入：target = 7, nums = [2,3,1,2,4,3]
    输出：2

    示例 2：    
    输入：target = 4, nums = [1,4,4]
    输出：1

    示例 3：
    输入：target = 11, nums = [1,1,1,1,1,1,1,1]
    输出：0

    提示：
    1 <= target <= 109
    1 <= nums.length <= 105
    1 <= nums[i] <= 105
*/
class MinSubArrayLen
{
public:
    /**
     * 暴力搜索, O(n^2)
    */
    static int Solution1(int target, std::vector<int>& nums)
    {
        int size = (int)nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < size; i++)
        {
            int sum = 0;
            for (int j = i; j < size; j++)
            {  
                sum += nums[j];
                if (sum >= target)
                {
                    ans = std::min(ans, j - i + 1);
                    break;
                }
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }

    /**
     * 滑动窗口, O(n)
    */
    static int Solution2(int target, std::vector<int>& nums)
    {
        int size = (int)nums.size();
        int ans = INT_MAX;
        int start = 0;
        int end = 0;
        int sum = 0;

        while (end < size)
        {
            sum += nums[end];
            if (sum >= target)
            {
                while (start <= end && sum >= target)
                {
                    ans = std::min(ans, end - start + 1);
                    sum -= nums[start];
                    ++start;
                }
            }

            ++end;
        }

        return ans == INT_MAX ? 0 : ans;
    }

    /*
    *   前缀和，O(nlogn)
    */
    static int Solution3(int s, std::vector<int>& nums)
    {
        int n = (int)nums.size();
        if (n == 0) {
            return 0;
        }

        int ans = INT_MAX;
        std::vector<int> sums(n + 1, 0); 

        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        for (int i = 1; i <= n; i++) {
            int target = s + sums[i - 1];
            auto bound = std::lower_bound(sums.begin(), sums.end(), target);
            if (bound != sums.end()) {
                ans = std::min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }

public:
    static void TestCase(std::vector<int> nums, int target, int ans)
    {
        EXPECT_EQ(Solution1(target, nums), ans);
        EXPECT_EQ(Solution2(target, nums), ans);
        EXPECT_EQ(Solution3(target, nums), ans);
    }

    static void Test()
    {
        std::cout << "test_min_sub_array_len..." << std::endl;

        TestCase({2, 3, 1, 2 ,4, 3}, 7, 2);
        TestCase({1, 4, 4}, 4, 1);
        TestCase({1, 1, 1, 1, 1, 1, 1, 1}, 11, 0);

        std::cout << "test done!" << std::endl << std::endl;
    }
};

#endif