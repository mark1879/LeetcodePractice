#ifndef REMOVE_NTH_FROM_END
#define REMOVE_NTH_FROM_END
/**
 * 19. 删除链表的倒数第 N 个结点
 * 
    给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
    链表中结点的数目为 sz
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz
 */
#include <iostream>
#include <stack>
#include "list.hpp"

using namespace List;
using namespace std;

class RemoveNthFromEnd {
private:
    int GetSize(ListNode* head) {
        int size = 0;
        ListNode* curr = head;

        while (curr != nullptr) {
            ++size;
            curr = curr->next;
        }

        return size;
    }
public:
    ListNode* Solution1(ListNode* head, int n) {
        ListNode* curr = nullptr;
        int size = GetSize(head);

        for (int i = 0; i < size - n; i++)
            curr = (curr == nullptr) ? head : curr->next;

        if (curr == nullptr)
            head = head->next;
        else if (curr->next != nullptr)
            curr->next = curr->next->next;

        return head;
    }

    // 在头部增加一个空节点，能避免复杂的判断
    ListNode* Solution2(ListNode* head, int n) {
        int size = GetSize(head);
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;

        for (int i = 0; i < size - n; i++) 
            curr = curr->next;

        curr->next = curr->next->next;
        ListNode* tmp = dummy->next;
        delete dummy;

        return tmp;
    }

    // 双指针
    ListNode* Solution3(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;

        for (int i = 0; i < n; i++) 
            first = first->next;

        while (first) {
            first = first->next;
            second = second->next;
        }

        ListNode* tmp = second->next;
        second->next = second->next->next;
        delete tmp;

        return dummy->next;
    }
    
};

#endif