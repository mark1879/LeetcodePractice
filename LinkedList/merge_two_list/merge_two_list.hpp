#ifndef MERGE_TWO_LIST_HPP
#define MERGE_TWO_LIST_HPP
/**
 * 21. 合并两个有序链表
 
   将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 
   提示：
     两个链表的节点数目范围是 [0, 50]
     -100 <= Node.val <= 100
     l1 和 l2 均按 非递减顺序 排列
 */

#include <iostream>
#include "list_node.hpp"

class MergeTwoList {
public:
    ListNode* Solution1(ListNode* l1, ListNode* l2) {
        ListNode* pre_head = new ListNode(-1);
        ListNode* iter = pre_head;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                iter->next = l1;
                l1 = l1->next;
                iter = iter->next;
            } else {
                iter->next = l2;
                l2 = l2->next;
                iter = iter->next;
            }
        }

        iter->next = (l1 == nullptr) ? l2 : l1;

        ListNode* ret = pre_head->next;
        delete pre_head;

        return ret;
    }

    ListNode* Solution2(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;

        if (!list2)
            return list1;

        ListNode* new_head = nullptr;
        if (list1->val <= list2->val) {
            new_head = list1;
            list1 = list1->next;
        } else {
            new_head = list2;
            list2 = list2->next;
        }

        ListNode* it = new_head;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                it->next = list1;
                list1 = list1->next;
                it = it->next;
            } else {
                it->next = list2;
                list2 = list2->next;
                it = it->next;
            }
        }

        it->next = (list1 == nullptr) ? list2 : list1;

        return new_head;
    }

    ListNode* Solution3(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        else if (!l2)
            return l1;
        else if (l1->val <= l2->val) {
            l1->next = Solution3(l1->next, l2);
            return l1;
        } else {
            l2->next = Solution3(l1, l2->next);
            return l2;
        }
    }
};

#endif