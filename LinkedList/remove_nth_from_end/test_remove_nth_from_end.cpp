#include "remove_nth_from_end.hpp"
#include <vector>
#include <gtest/gtest.h>
#include <functional>

using Solution = std::function<ListNode*(ListNode*, int)>;

void TestCase(vector<int> vec, int n, vector<int> ans, Solution solution) {
    ListNode* head = GenerateList(vec);

    ListNode* ret = solution(head, n);
    ListNode* cur = ret;

    for (auto it : ans) {
        EXPECT_EQ(it, cur->val);
        cur = cur->next;
    }
    
    FreeList(ret);
}

int main() {

    cout << "<<<<<< test_remove_nth_from_end..." << endl;

    RemoveNthFromEnd remove;
    TestCase({1, 2, 3, 4, 5}, 2, {1, 2, 3, 5}, std::bind(&RemoveNthFromEnd::Solution1, remove, placeholders::_1, placeholders::_2));
    TestCase({1, 2, 3, 4, 5}, 2, {1, 2, 3, 5}, std::bind(&RemoveNthFromEnd::Solution2, remove, placeholders::_1, placeholders::_2));
    TestCase({1, 2, 3, 4, 5}, 2, {1, 2, 3, 5}, std::bind(&RemoveNthFromEnd::Solution3, remove, placeholders::_1, placeholders::_2));

    TestCase({1}, 1, {}, std::bind(&RemoveNthFromEnd::Solution1, remove, placeholders::_1, placeholders::_2));
    TestCase({1}, 1, {}, std::bind(&RemoveNthFromEnd::Solution2, remove, placeholders::_1, placeholders::_2));
    TestCase({1}, 1, {}, std::bind(&RemoveNthFromEnd::Solution3, remove, placeholders::_1, placeholders::_2));

    TestCase({1, 2}, 1, {1}, std::bind(&RemoveNthFromEnd::Solution1, remove, placeholders::_1, placeholders::_2));
    TestCase({1, 2}, 1, {1}, std::bind(&RemoveNthFromEnd::Solution2, remove, placeholders::_1, placeholders::_2));
    TestCase({1, 2}, 1, {1}, std::bind(&RemoveNthFromEnd::Solution3, remove, placeholders::_1, placeholders::_2));

    cout << "test done!" << endl << endl;

    return 0;
}