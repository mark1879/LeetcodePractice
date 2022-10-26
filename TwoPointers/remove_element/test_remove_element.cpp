#include "remove_element.hpp"
#include <gtest/gtest.h>

void TestCase(vector<int> nums, int val, vector<int> ans) {
    RemoveElement remove_element;

    int len1 = remove_element.Solution1(nums, val);
    EXPECT_EQ(len1, ans.size());
    for (int i = 0; i < len1; i++) {
        EXPECT_EQ(nums[i], ans[i]);
    }

    int len2 = remove_element.Solution2(nums, val);
    EXPECT_EQ(len2, ans.size());
    for (int i = 0; i < len2; i++) {
        EXPECT_EQ(nums[i], ans[i]);
    }
}

int main() {
    cout << "<<<<< test_remove_element..." << endl;

    TestCase({3, 2, 2, 3}, 3, {2, 2});
    TestCase({0, 1, 2, 2, 3, 0, 4, 2}, 2, {0, 1, 4, 0, 3});

    cout << "test done!" << endl << endl;

    return 0;
}