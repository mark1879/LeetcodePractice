#include "reverse_list.hpp"
#include <vector>
#include <gtest/gtest.h>

ListNode* GenerateData(vector<int>& data) {
    ListNode* head = nullptr;
    ListNode* curr = nullptr;

    for (auto i : data) {
        if (head == nullptr) {
            head = new ListNode(i);
            curr = head;
        } else {
            curr->next = new ListNode(i);
            curr = curr->next;
        }
    }

    return head;
}

void TestCase(vector<int> data) {
    ReverseList reverse;

    ListNode* head = reverse.Solution1(GenerateData(data));

    for (auto it = data.crbegin(); it != data.crend(); it++) {
        EXPECT_EQ(*it, head->val);
        head = head->next;
    }

    head = reverse.Solution2(GenerateData(data));
    for (auto it = data.crbegin(); it != data.crend(); it++) {
        EXPECT_EQ(*it, head->val);
        head = head->next;
    }
}

int main() {

    cout << "test_reverse_list..." << endl;

    TestCase({1, 2, 3, 4, 5});
    TestCase({1});
    TestCase({});

    cout << "test done!" << endl << endl;

    return 0;
}