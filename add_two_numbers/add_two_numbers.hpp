#ifndef ADD_TWO_NUMBERS_HPP
#define ADD_TWO_NUMBERS_HPP

/**
 * 
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

提示：
每个链表中的节点数在范围 [1, 100] 内。
0 <= Node.val <= 9
题目数据保证列表表示的数字不含前导零。
*
*/

#include "common.hpp"

class AddTwoNumbers {
public:
    ListNode* Solution(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;

        while(l1 || l2) {
            int val1 = (l1 == nullptr) ? 0 : l1->val;
            int val2 = (l2 == nullptr) ? 0 : l2->val;
            int sum = val1 + val2 + carry;

            if (head != nullptr) {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            } else {
                head = new ListNode(sum % 10);
                tail = head;
            }

            carry = sum / 10;

            if (l1)
                l1 = l1->next;

            if (l2)
                l2 = l2->next;
        }

        if (carry > 0)
            tail->next = new ListNode(carry);

        return head;
    }
};

#endif