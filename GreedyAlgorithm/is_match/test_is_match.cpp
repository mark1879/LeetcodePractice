#include "is_match.hpp"
#include <gtest/gtest.h>

void TestCase(string s, string p, bool ans) {
    IsMatch is_match;

    EXPECT_EQ(is_match.Solution1(s, p), ans);
    EXPECT_EQ(is_match.Solution2(s, p), ans);
}

int main() {

    cout << "<<<<<< test_is_match..." << endl;

    TestCase("aa", "a", false);
    TestCase("aa", "*", true);
    TestCase("cb", "?a", false);
    TestCase("adceb", "*a*b", true);
    TestCase("acdcb", "a*c?b", false);
    TestCase("", "***", true);

    cout << "test done!" << endl << endl;

    return 0;
}