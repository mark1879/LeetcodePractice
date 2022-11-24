#ifndef REVERSE_K_GROUP
#define REVERSE_K_GROUP
/**
 *  25. K 个一组翻转链表
 * 
    给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
    k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
    你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

    提示：
        链表中的节点数目为 n
        1 <= k <= n <= 5000
        0 <= Node.val <= 1000
 */

#include "list_node.hpp"
#include <iostream>

using namespace std;

class ReverseKGroup {
public:
    ListNode* ReverseList(ListNode* head, ListNode* end) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        end->next = nullptr;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* Solution(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* prev = dummy;
        ListNode* iter = head;

        int i = 0;
        while (iter) {
            ++i;
            if (i % k == 0) {
                ListNode* next = iter->next;
                prev->next = ReverseList(head, iter);
                head->next = next;
                prev = iter = head;
                head = next;
            }

            iter = iter->next;
        }

        ListNode* ret = dummy->next;
        delete dummy;

        return ret;
    }

};


#endif