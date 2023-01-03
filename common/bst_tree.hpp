#ifndef BST_NODE_HPP
#define BST_NODE_HPP
#include <vector>
#include <stack>

namespace BSTree {

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) { }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) { }
};

TreeNode* CreateNode(int left, int right, std::vector<int>& nums) {
    if (left == right)
        return new TreeNode(nums[left]);

    int mid = (left + right + 1) / 2;
    TreeNode* parent = new TreeNode(nums[mid]);

    if (left < mid)
        parent->left = CreateNode(left, mid - 1, nums);

    if (right > mid)
        parent->right = CreateNode(mid + 1, right, nums);

    return parent;
}

TreeNode* CreateBSTree(std::vector<int> nums) {
    return CreateNode(0, (int)nums.size() - 1, nums);
}

void InOrderBSTree(TreeNode* root, std::vector<int>& ans) {
    TreeNode *p = root;
    std::stack<TreeNode*> s;

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

void FreeBSTree(TreeNode* &node) {
    if (node == nullptr)
        return;

    while (node->left != nullptr)
        FreeBSTree(node->left);

    while (node->right != nullptr)
        FreeBSTree(node->right);

    delete node;
    node = nullptr;
}
};

#endif