#ifndef REMOVE_ELEMENT_HPP
#define REMOVE_ELEMENT_HPP
/**
 *  27. 移除元素
 
    给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
    不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
    元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

    提示：
        0 <= nums.length <= 100
        0 <= nums[i] <= 50
        0 <= val <= 100
 */

#include <iostream>
#include <vector>

using namespace std;

class RemoveElement {
public:
    int Solution1(vector<int>& nums, int val) {
        int new_size = 0;
        int left = 0;
        int right = (int)nums.size() - 1;

        while (left < right) {
            while (left < right && nums[left] != val) {
                ++left;
                ++new_size;
            }
               
            
            while (left < right && nums[right] == val)
                --right;

            if (left < right) {
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;

                left++;
                right--;
                new_size++;
            }
        }

        if (left == right && nums[left] != val)
            new_size++;

        return new_size;
    }

    // 时间复杂度：O(n)， 其中 n 为序列的长度。只需要遍历该序列至多一次。
    // 空间复杂度：O(1)。只需要常数的空间保存若干变量。
    int Solution2(vector<int>& nums, int val) {
        int left = 0;
        int right = (int)nums.size();

        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                --right;
            } else {
                ++left;
            }
        }

        return left;
    }
};

#endif