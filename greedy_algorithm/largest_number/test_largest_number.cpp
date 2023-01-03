#include "largest_number.hpp"
#include <gtest/gtest.h>

void TestSolution(vector<int> vec, string ans) {
    LargestNumber larget_number;

    EXPECT_EQ(larget_number.Solution(vec), ans);
}

int main() {
    cout << "<<<<<< test_largest_number..." << endl;

    TestSolution({10, 2}, "210");
    TestSolution({3, 30, 34, 5, 9}, "9534330");

    cout << "test done!" << endl << endl;
}