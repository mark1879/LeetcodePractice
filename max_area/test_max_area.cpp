#include "max_area.hpp"
#include <gtest/gtest.h>

void TestCase(vector<int> vec, int ans) {
    MaxArea max_area;

    EXPECT_EQ(max_area.Solution1(vec), ans);
    EXPECT_EQ(max_area.Solution2(vec), ans);
}

int main() {
    cout << "<<<<<< test_max_area..." << endl;

    TestCase({1, 8, 6, 2, 5, 4, 8, 3, 7}, 49);
    TestCase({1, 1}, 1);

    cout << "test done!" << endl << endl;
    return 0;
}