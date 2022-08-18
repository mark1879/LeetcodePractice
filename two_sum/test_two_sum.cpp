#include "two_sum.hpp"
#include <gtest/gtest.h>

using namespace std;

void TestCase(vector<int> vec, int target, vector<int> ans) {
    TwoSum two_sum;

    auto result = two_sum.Solution(vec, target);
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result[0], ans[0]);
    EXPECT_EQ(result[1], ans[1]);
}

int main() {

    cout << "<<<<<< test_two_sum..." << endl;

    TestCase({2, 7, 11, 15}, 9, {0, 1});
    TestCase({3, 2, 4}, 6, {1, 2});
    TestCase({3, 3}, 6, {0, 1});

    cout << "<<<<<< test done!" << endl << endl;

    return 0;
}