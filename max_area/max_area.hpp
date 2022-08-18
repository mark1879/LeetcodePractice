#ifndef MAX_AREA_HPP
#define MAX_AREA_HPP
/**
    盛最多水的容器.
    给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

    找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。返回容器可以储存的最大水量。

    提示：
    n == height.length
    2 <= n <= 105
    0 <= height[i] <= 104
 */

#include <iostream>
#include <vector>

using namespace std;

class MaxArea {
public:
    int Solution1(vector<int>& height) {
        int size = (int)height.size();
        int max_area = 0;

        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++)
                max_area = max(max_area, (j - i) * min(height[i], height[j]));

        return max_area;
    } 

    int Solution2(vector<int>& height) {
        int max_area = 0;
        int left = 0;
        int right = (int)height.size() - 1;

        while (left < right) {
            max_area = max(max_area, (right - left) * min(height[left], height[right]));

            if (height[left] < height[right]) {
                int temp = height[left];

                while (++left < right && height[left] <= temp)
                    ;
            } else {
                int temp = height[right];

                while (--right > left && height[right] >= temp)
                    ;
            }
        }

        return max_area;
    }
};

#endif