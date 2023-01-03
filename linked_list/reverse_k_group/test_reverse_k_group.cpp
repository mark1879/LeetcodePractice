#include "reverse_k_group.hpp"
#include <vector>
#include <gtest/gtest.h>
#include <functional>

using Solution = std::function<ListNode*(ListNode*, int)>;

void TestCase(vector<int> vec, int k, vector<int> ans, Solution solution) {
    ListNode* li = GenerateList(vec);

    ListNode* ret = solution(li, k);
    ListNode* cur = ret;

    for (auto it : ans) {
        EXPECT_EQ(it, cur->val);
        cur = cur->next;
    }
    
    FreeList(ret);
}

int main() {

    cout << "<<<<<< test_reverse_k_group..." << endl;

    ReverseKGroup reverse;

    TestCase({1, 2, 3, 4, 5}, 2, {2, 1, 4, 3, 5}, std::bind(&ReverseKGroup::Solution, reverse, std::placeholders::_1, std::placeholders::_2));
    TestCase({1, 2, 3, 4, 5}, 3, {3, 2, 1, 4, 5}, std::bind(&ReverseKGroup::Solution, reverse, std::placeholders::_1, std::placeholders::_2));

    cout << "test done!" << endl << endl;

    return 0;
}