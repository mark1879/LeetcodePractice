#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode* next) : val(x), next(next) { }
};


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

void InOrderBinaryTree(TreeNode* root, vector<int>& ans) {
    TreeNode *p = root;
    stack<TreeNode*> s;

    while(p != nullptr || !s.empty())
    {
        while(p != nullptr)
        {
            s.push(p);
            p = p->left;
        }

        if(!s.empty())
        {
            p = s.top();
            ans.push_back(p->val);
            s.pop();
            p = p->right;
        }
    }    
}

void FreeBinaryTree(TreeNode* &node) {
    if (node == nullptr)
        return;

    while (node->left != nullptr)
        FreeBinaryTree(node->left);

    while (node->right != nullptr)
        FreeBinaryTree(node->right);

    delete node;
    node = nullptr;
}

#endif