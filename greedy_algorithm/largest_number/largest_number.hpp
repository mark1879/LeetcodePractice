#ifndef LARGEST_NUMBER_HPP
#define LARGEST_NUMBER_HPP
/**
    179. 最大数
    
    给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
    注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。

    提示：
        1 <= nums.length <= 100
        0 <= nums[i] <= 109
 */

#include <iostream>
#include <vector>

using namespace std;

class LargestNumber {
public:
    string Solution(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int& x, const int& y) {
            long carry_x = 10;
            long carry_y = 10;

            while (carry_x <= x)
                carry_x *= 10;

            while (carry_y <= y)
                carry_y *= 10;

            return carry_y * x + y > carry_x * y + x;
        });

        if (nums[0] == 0)
            return "0";

        string str;
        for (auto& it : nums)
            str += to_string(it);

        return str;
    };
};

#endif