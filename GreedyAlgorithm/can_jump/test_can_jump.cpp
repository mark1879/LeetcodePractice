#include "can_jump.hpp"
#include <gtest/gtest.h>

void TestCase(vector<int> vec, bool ans) {
    CanJump can_jump;

    EXPECT_EQ(can_jump.Solution1(vec), ans);
    // EXPECT_EQ(can_jump.Solution2(vec), ans);
}

int main() {
    cout << "<<<<<< test_can_jump..." << endl;
    
    TestCase({2, 3, 1, 1, 4}, true);
    TestCase({3, 2, 1, 0, 4}, false);

    cout << "test done!" << endl << endl;
    return 0;
}