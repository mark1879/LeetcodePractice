#include "max_profit.hpp"
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

void TestCase(vector<int> prices, int ans) {
    MaxProfit max_profit;

    EXPECT_EQ(max_profit.Solution(prices), ans);
    EXPECT_EQ(max_profit.Solution2(prices), ans);
}

int main() {

    cout << "<<<<<< test_max_profit..." << endl;

    TestCase({7, 1, 5, 3, 6, 4}, 5);
    TestCase({7, 6, 4, 3, 1}, 0);

    cout << "test done!" << endl;

    return 0;
}