#ifndef THREE_SUM_HPP
#define THREE_SUM_HPP

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