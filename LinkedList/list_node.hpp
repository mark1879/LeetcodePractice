#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

struct ListNode {
    int val_;
    ListNode *next_;

    ListNode() : val_(0), next_(nullptr) {}
    ListNode(int x) : val_(x), next_(nullptr) { }
    ListNode(int x, ListNode* next) : val_(x), next_(next) { }
};

#endif