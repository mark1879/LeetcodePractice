#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP
#include <vector>
#include <stack>

using namespace std;

namespace List {
    struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode* next) : val(x), next(next) { }
};


ListNode* GenerateList(const vector<int>& vec) {
    ListNode* head = nullptr;
    ListNode* prev = nullptr;
    for (int i = 0, size = (int)vec.size(); i < size; i++) {
        ListNode* new_node = new ListNode(vec[i]);
        if (i != 0) {
            prev->next = new_node;
            prev = new_node;
        } else {
            head = new_node;
            prev = head;
        }
    }

    return head;
}

void FreeList(ListNode* list) {
    while (list != nullptr) {
        ListNode* tmp = list;
        list = list->next;
        delete tmp;
    }
}
};

#endif