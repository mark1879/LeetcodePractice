#ifndef REVERSE_LIST_HPP
#define REVERSE_LIST_HPP

#include <iostream>
#include "list_node.hpp"

using namespace std;

class ReverseList {
public:
    ListNode* Solution1(ListNode* head) {
        ListNode* next = nullptr;

        while (head != nullptr) {
            ListNode* tmp = head->next_;
            head->next_ = next;
            next = head;
            head = tmp;
        }

        return next;
    }

    ListNode* Solution2(ListNode* head) {
        if (!head || !head->next_) {
            return head;
        }

        ListNode* new_head = Solution2(head->next_);
        head->next_->next_ = head;
        head->next_ = nullptr;

        return new_head;
    }
};

#endif