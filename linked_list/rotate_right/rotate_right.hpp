#ifndef ROTATE_RIGHT_HPP
#define ROTATE_RIGHT_HPP
/**
 * 61. 旋转链表
 * 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
 * 
 * 提示：
    链表中节点的数目在范围 [0, 500] 内
    -100 <= Node.val <= 100
    0 <= k <= 2 * 109
 */
#include <iostream>
#include "list.hpp"

using namespace List;
using namespace std;

class RotateRight {
public:
    ListNode* Solution(ListNode* head, int k) {
        int size = 0;
        ListNode* curr = head;
        ListNode* tail = nullptr;
        while (curr) {
            ++size;
            tail = curr;
            curr = curr->next;
        }

        // 闭环
        if (tail)
            tail->next = head;

        int rotate_right = (size == 0) ? 0 : k % size;
        curr = head;
        ListNode* prev = tail;
        for (int i = 0; i < (size - rotate_right); i++) {
            prev = curr;
            curr = curr->next;
        }

        head = curr;
        // 拆环
        if (prev)
            prev->next = nullptr;

        return head;
    }
};


#endif