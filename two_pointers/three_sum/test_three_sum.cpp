#include "three_sum.hpp"
#include <gtest/gtest.h>

void TestCase(vector<int> nums, vector<vector<int>> ans) {
    ThreeSum three_sum;
    
    vector<vector<int>> result = three_sum.Solution(nums);

    EXPECT_EQ(ans.size(), result.size());

    for (int i = 0, size = (int)ans.size(); i < size; i++) {
        EXPECT_EQ(ans[i].size(), result[i].size());

        for (int j = 0, size1 = (int)ans[i].size(); j < size1; j++) {
            EXPECT_EQ(ans[i][j], result[i][j]);
        }
    }
}

int main() {

    cout << "<<<<<< test_three_sum..." << endl;

    TestCase({-1, 0, 1, 2, -1, -4}, {{-1,-1,2}, {-1, 0, 1}});
    TestCase({0, 1, 1}, {});
    TestCase({0, 0, 0}, {{0, 0, 0}});

    cout << "test done!" << endl << endl;

    return 0;
}