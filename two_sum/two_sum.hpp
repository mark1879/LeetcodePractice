#ifndef TWO_SUM_HPP
#define TWO_SUM_HPP

// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 “和为目标值 target“ 的那两个整数，并返回它们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class TwoSum {
public:
    vector<int> Solution(const vector<int>& nums, int target){
        unordered_map<int , int> hash_table;
    
        for (int i = 0, size = (int)nums.size(); i < size; i++){
            auto it = hash_table.find(target - nums[i]);
            if (it != hash_table.end()){
                return {it->second, i};
            }
            hash_table[nums[i]] = i;
        }
        return {};
    }
};

#endif