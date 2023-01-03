#ifndef RANGE_SUM_BST_HPP
#define RANGE_SUM_BST_HPP
/**
 * 938. 二叉搜索树的范围和
 * 
 * 给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之间的所有结点的值的和。
    
    提示：
        树中节点数目在范围 [1, 2 * 104] 内
        1 <= Node.val <= 105
        1 <= low <= high <= 105
        所有 Node.val 互不相同
 */
#include <queue>
#include "bst_tree.hpp"

using namespace BSTree;
using namespace std;

class RangeSumBST {
public:
    int Solution1(TreeNode* root, int low, int high) {
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr)
                continue;

            if (node->val > high) {
                q.push(node->left);
            }
            else if (node->val < low) {
                q.push(node->right);
            } else {
                sum += node->val;
                q.push(node->left);
                q.push(node->right);
            }
        }

        return sum;
    }

    int Solution2(TreeNode* root, int low, int high) {
        if (root == nullptr)
            return 0;

        if (root->val > high)
            return Solution2(root->left, low, high);

        if (root->val < low)
            return Solution2(root->right, low, high);

        return root->val + Solution2(root->left, low, high) + Solution2(root->right, low, high);
    }

};

#endif