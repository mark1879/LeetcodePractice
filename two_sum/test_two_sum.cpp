#include "two_sum.hpp"
#include <gtest/gtest.h>

int main() {

    cout << "test two_sum..." << endl;

    TwoSum two_sum;

    vector<int> vec1 = {2, 7, 11, 15};
    auto ans1 = two_sum.Solution(vec1, 9);
    EXPECT_EQ(ans1.size(), 2);
    EXPECT_EQ(ans1[0], 0);
    EXPECT_EQ(ans1[1], 1);

    vector<int> vec2 = {3, 2, 4};
    auto ans2 = two_sum.Solution(vec2, 6);
    EXPECT_EQ(ans2.size(), 2);
    EXPECT_EQ(ans2[0], 1);
    EXPECT_EQ(ans2[1], 2);

    vector<int> vec3 = {3, 3};
    auto ans3 = two_sum.Solution(vec3, 6);
    EXPECT_EQ(ans3.size(), 2);
    EXPECT_EQ(ans3[0], 0);
    EXPECT_EQ(ans3[1], 1);

    return 0;
}