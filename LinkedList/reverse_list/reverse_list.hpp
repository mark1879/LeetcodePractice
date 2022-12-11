#ifndef REVERSE_LIST_HPP
#define REVERSE_LIST_HPP
/**
 * 206. 反转链表
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 * 
 * 提示：
 * 链表中节点的数目范围是 [0, 5000]
 * -5000 <= Node.val <= 5000
 */

#include <iostream>
#include "list_node.hpp"

using namespace std;

class ReverseList {
public:
    ListNode* Solution1(ListNode* head) {
        // ListNode* next = nullptr;

        // while (head != nullptr) {
        //     ListNode* tmp = head->next;
        //     head->next = next;
        //     next = head;
        //     head = tmp;
        // }

        // return next;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }

    ListNode* Solution2(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* new_head = Solution2(head->next);
        head->next->next = head;
        head->next = nullptr;

        return new_head;
    }
};

#endif