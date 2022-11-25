#include "rotate_right.hpp"
#include <vector>
#include <gtest/gtest.h>
#include <functional>

using Solution = std::function<ListNode*(ListNode*, int)>;

void TestCase(vector<int> vec, int k, vector<int> ans, Solution solution) {
    ListNode* ret = solution(GenerateList(vec), k);
    ListNode* curr = ret;

    for (auto it : ans) {
        EXPECT_EQ(it, curr->val);
        curr = curr->next;
    }

    FreeList(ret);

}

int main() {
    cout << "<<<<<< test_rotate_right..." << endl;

    RotateRight rotate;
    TestCase({1, 2, 3, 4, 5}, 0, {1, 2, 3, 4, 5}, std::bind(&RotateRight::Solution, rotate, std::placeholders::_1, std::placeholders::_2));
    TestCase({1, 2, 3, 4, 5}, 1, {5, 1, 2, 3, 4}, std::bind(&RotateRight::Solution, rotate, std::placeholders::_1, std::placeholders::_2));
    TestCase({1, 2, 3, 4, 5}, 2, {4, 5, 1, 2, 3}, std::bind(&RotateRight::Solution, rotate, std::placeholders::_1, std::placeholders::_2));
    TestCase({1, 2, 3, 4, 5}, 3, {3, 4, 5, 1, 2}, std::bind(&RotateRight::Solution, rotate, std::placeholders::_1, std::placeholders::_2));
    TestCase({1, 2, 3, 4, 5}, 4, {2, 3, 4, 5, 1}, std::bind(&RotateRight::Solution, rotate, std::placeholders::_1, std::placeholders::_2));
    TestCase({1, 2, 3, 4, 5}, 5, {1, 2, 3, 4, 5}, std::bind(&RotateRight::Solution, rotate, std::placeholders::_1, std::placeholders::_2));
    TestCase({1, 2, 3, 4, 5}, 6, {5, 1, 2, 3, 4}, std::bind(&RotateRight::Solution, rotate, std::placeholders::_1, std::placeholders::_2));
    TestCase({}, 6, {}, std::bind(&RotateRight::Solution, rotate, std::placeholders::_1, std::placeholders::_2));

    cout << "test done!" << endl;

    return 0;
}