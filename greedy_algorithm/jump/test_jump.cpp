#include "jump.hpp"
#include <gtest/gtest.h>

void TestCase(vector<int> vec, int ans) {
    Jump jump;

    EXPECT_EQ(jump.Solution1(vec), ans);
    EXPECT_EQ(jump.Solution2(vec), ans);
}

int main() {

    cout << "<<<<<< test_jump..." << endl;

    TestCase({2, 3, 1, 1, 4}, 2);
    TestCase({2, 3, 0, 1, 4}, 2);
    TestCase({0}, 0);
    TestCase({1, 2, 3}, 2);

    cout << "test done!" << endl << endl;;

    return 0;
}