#ifndef CAN_COMPLETE_CIRCUIT_HPP
#define CAN_COMPLETE_CIRCUIT_HPP
/**
    134. 加油站

    在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
    你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
    给定两个整数数组 gas 和 cost ，如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。

     

    提示:

    gas.length == n
    cost.length == n
    1 <= n <= 10^5
    0 <= gas[i], cost[i] <= 10^4

 */
#include <iostream>
#include <vector>

using namespace std;

class CanCompleteCircuit {
public:
    // 最佳解法
    int Solution1(vector<int>& gas, vector<int>& cost) {
        int size = (int)gas.size();
        int cover_dist = 0;
        int gap = 0;
        int start_index = 0;

        for (int i = 0; i < size; i++) {
            cover_dist += gas[i] - cost[i];

            if (cover_dist < 0) {
                gap += cover_dist;
                start_index = i + 1;
                cover_dist = 0;
            }
        }

        if (cover_dist + gap >= 0)
            return start_index;

        return -1;
    } 

public:
    // 双循环
    int Solution2(vector<int>&gas, vector<int>& cost) {
        int size = (int)gas.size();
        int i = 0;

        while (i < size) {
            int cover_dist = 0;
            int count = 0;

            while (count < size) {
                int j = (i + count) % size;

                cover_dist += (gas[j] - cost[j]);
                if (cover_dist < 0)
                    break;

                count++;
            }

            if (count == size)
                return i;
            else
                i = i + count + 1;
        }

        return -1;
    }

};

#endif