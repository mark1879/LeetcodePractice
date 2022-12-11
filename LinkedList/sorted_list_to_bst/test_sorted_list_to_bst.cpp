#include "sorted_list_to_bst.hpp"
#include "sorted_list_to_bst.hpp"
#include <vector>
#include <gtest/gtest.h>

using Solution = std::function<TreeNode*(ListNode*)>;

void TestCase(vector<int> data, Solution solution) {
    ListNode* head = GenerateList(data);
    TreeNode* ret = solution(head);

    vector<int> ans;
    InOrderBinaryTree(ret, ans);

    EXPECT_EQ(data.size(), ans.size());

    for (int i = 0, size = (int)data.size(); i < size; i++) {
        EXPECT_EQ(data[i], ans[i]);
    }

    FreeList(head);
    FreeBinaryTree(ret);
}

int main() {

    cout << "<<<<<< test_sorted_list_to_bst..." << endl;

    SortedListToBst sorted_list_to_bst;

    TestCase({-10, -3, 0, 5, 9}, std::bind(&SortedListToBst::Solution1, sorted_list_to_bst, std::placeholders::_1));
    TestCase({-10, -3, 0, 5, 9}, std::bind(&SortedListToBst::Solution2, sorted_list_to_bst, std::placeholders::_1));

    TestCase({}, std::bind(&SortedListToBst::Solution1, sorted_list_to_bst, std::placeholders::_1));
    TestCase({}, std::bind(&SortedListToBst::Solution2, sorted_list_to_bst, std::placeholders::_1));

    TestCase({1, 2}, std::bind(&SortedListToBst::Solution1, sorted_list_to_bst, std::placeholders::_1));
    TestCase({1, 2}, std::bind(&SortedListToBst::Solution2, sorted_list_to_bst, std::placeholders::_1));

    cout << "test done!" << endl << endl;

    return 0;
}