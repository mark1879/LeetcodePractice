#include "length_of_longest_sub_string.hpp"
#include <gtest/gtest.h>


void TestCase(string s, int ans) {
    LengthOfLongestSubString lolss;

    EXPECT_EQ(lolss.Solution1(s), ans);
    EXPECT_EQ(lolss.Solution2(s), ans);
    EXPECT_EQ(lolss.Solution3(s), ans);
}

int main() {

    cout << "<<<<<< test_length_of_longest_sub_string..." << endl;

    TestCase("abcabcbb", 3);
    TestCase("bbbbb", 1);
    TestCase("pwwkew", 3);

    cout << "<<<<<< test done!" << endl << endl;

    return 0;
}