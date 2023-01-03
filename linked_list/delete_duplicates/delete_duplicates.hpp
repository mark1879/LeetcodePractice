#ifndef DELETE_DUPLICATES_HPP
#define DELETE_DUPLICATES_HPP
#include <iostream>
#include "list.hpp"

using namespace List;
using namespace std;

class DeleteDuplicates {
public:
    ListNode* Solution(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* prev = dummy;
        ListNode* left = head;

        while (left) {
            ListNode* right = left;

            while (right->next != nullptr && right->val == right->next->val)
                right = right->next;

            if (left == right) {
                prev = left;
            } else {
                prev->next = right->next;
                while (left != right) {
                    ListNode* next = left->next;
                    delete left;
                    left = next;
                }
            }

            left = prev->next;
        }

        ListNode* ret = dummy->next;
        delete dummy;

        return ret;
    }

};

#endif