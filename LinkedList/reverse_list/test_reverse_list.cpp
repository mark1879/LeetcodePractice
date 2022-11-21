#include "reverse_list.hpp"
#include <vector>
#include <gtest/gtest.h>
#include <functional>

using Solution = std::function<ListNode* (ListNode*)>;

void TestCase(vector<int> data, Solution solution) {
    ListNode* list = GenerateList(data);

    ListNode* head = solution(list);
    ListNode* cur = head;

    for (auto it = data.crbegin(); it != data.crend(); it++) {
        EXPECT_EQ(*it, cur->val);
        cur = cur->next;
    }

    FreeList(head);
}

int main() {
    cout << "test_reverse_list..." << endl;

    ReverseList reverse;

    TestCase({1, 2, 3, 4, 5}, std::bind(&ReverseList::Solution1, reverse, std::placeholders::_1));
    TestCase({1, 2, 3, 4, 5}, std::bind(&ReverseList::Solution2, reverse, std::placeholders::_1));

    TestCase({1}, std::bind(&ReverseList::Solution1, reverse, std::placeholders::_1));
    TestCase({1}, std::bind(&ReverseList::Solution2, reverse, std::placeholders::_1));

    TestCase({}, std::bind(&ReverseList::Solution1, reverse, std::placeholders::_1));
    TestCase({}, std::bind(&ReverseList::Solution2, reverse, std::placeholders::_1));

    cout << "test done!" << endl << endl;

    return 0;
}