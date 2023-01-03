#include <gtest/gtest.h>
#include <vector>
#include "add_two_numbers.hpp"

using namespace std;

void TestCase(vector<int> vec1, vector<int> vec2, vector<int> ans) {
    AddTwoNumbers add_two_numbers;

    ListNode* l1 = GenerateList(vec1);
    ListNode* l2 = GenerateList(vec2);

    ListNode* head = add_two_numbers.Solution(l1, l2);
    ListNode* tail = head;

    for (auto it = ans.cbegin(); it != ans.cend(); it++) {
        EXPECT_TRUE(tail != nullptr);
        EXPECT_EQ(*it, tail->val);
        tail = tail->next;
    }

    FreeList(head);
}

int main() {

    cout << "<<<<<< test_add_two_numbers..." << endl;

    TestCase({2, 4, 3}, {5, 6, 4}, {7, 0, 8});
    TestCase({0}, {0}, {0});
    TestCase({9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}, {8, 9, 9, 9, 0, 0, 0, 1});

    cout << "test done!" << endl << endl;

    return 0;
}