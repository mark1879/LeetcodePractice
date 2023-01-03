#ifndef THREE_SUM_HPP
#define THREE_SUM_HPP
/**
 *  15. 三数之和
 
    给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
    同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
    注意：答案中不可以包含重复的三元组。

    提示：
        3 <= nums.length <= 3000
        -105 <= nums[i] <= 105
 */

#include <iostream>
#include <vector>

using namespace std;

class ThreeSum {
public:
    vector<vector<int>> Solution(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int size = (int)nums.size();
       
        for (int first = 0; first < size; first++) {
            if (first > 0 && nums[first] == nums[first - 1])
                continue;

            int target = -nums[first];
            int third = size - 1;

            for (int second = first + 1; second < size; second++) {
                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue;

                while (second < third && nums[second] + nums[third] > target)
                    --third;

                if (second == third)
                    break;

                if (nums[second] + nums[third] == target)
                    ans.push_back({nums[first], nums[second], nums[third]});
            }
        } 

        return ans;
    }
};

#endif