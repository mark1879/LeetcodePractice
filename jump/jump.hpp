#ifndef JUMP_HPP
#define JUMP_HPP

/**
 *  45. 跳跃游戏 II
    给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
    数组中的每个元素代表你在该位置可以跳跃的最大长度。
    你的目标是使用最少的跳跃次数到达数组的最后一个位置。
    假设你总是可以到达数组的最后一个位置。

    提示:
    1 <= nums.length <= 104
    0 <= nums[i] <= 1000
 */

#include <iostream>
#include <vector>

using namespace std;

class Jump {
public:
    int Solution1(vector<int>& nums) {
        int step = 0;
        int size = (int)nums.size();
        int start = 0;
        int right_most = 0;

        for (int i = 0; i < size - 1; i++) {
            right_most = max(right_most, i + nums[i]);
            
            if (i == start) {
                step++;
                start = right_most;
            }
        }

        return step;
    }

    int Solution2(vector<int>& nums) {
        int step = 0;
        int start = (int)nums.size() - 1;

        while (start > 0) {
            // 从左往右，第一个达到条件的自然是跳跃区间最大的
            for (int i = 0; i < start; i++) {
                if (i + nums[i] >= start) {
                    start = i;
                    step++;
                    break;
                }
            }
        }

        return step;
    }

};

#endif