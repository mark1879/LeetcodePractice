#ifndef SORTED_LIST_TO_BST
#define SORTED_LIST_TO_BST
/**
 *  109. 有序链表转换二叉搜索树
 * 
 *  给定一个单链表的头节点  head ，其中的元素 按升序排序 ，将其转换为高度平衡的二叉搜索树。
    本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差不超过 1。

    提示:
        head 中的节点数在[0, 2 * 104] 范围内
        -105 <= Node.val <= 105
 */

#include <iostream>
#include "list_node.hpp"
using namespace std;

class SortedListToBst {
private:
     int GetLength(ListNode* head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }

        return len;
    }

    TreeNode* BuildTree(ListNode*& head, int left, int right) {
        if (left > right)
            return nullptr;

        int mid = (left + right + 1) / 2;
        TreeNode* root = new TreeNode();
        root->left = BuildTree(head, left, mid - 1);
        root->val = head->val;
        head = head->next;
        root->right = BuildTree(head, mid + 1, right);

        return root;
    }

    ListNode* GetMedian(ListNode* left, ListNode* right) {
        ListNode* fast = left;
        ListNode* slow = left;
        while (fast != right && fast->next != right) {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    TreeNode* BuildTree2(ListNode* left, ListNode* right) {
        if (left == right) {
            return nullptr;
        }
        ListNode* mid = GetMedian(left, right);
        TreeNode* root = new TreeNode(mid->val);
        root->left = BuildTree2(left, mid);
        root->right = BuildTree2(mid->next, right);
        return root;
    }

public:
    TreeNode* Solution1(ListNode* head) {
        return BuildTree(head, 0, GetLength(head) - 1);
    }

    TreeNode* Solution2(ListNode* head) {
        return BuildTree2(head, nullptr);
    }
};


#endif