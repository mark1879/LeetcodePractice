#include "can_complete_circuit.hpp"
#include <gtest/gtest.h>

void TestCase(vector<int> gas, vector<int> cost, int ans) {
    CanCompleteCircuit can_complete_circuit;

    EXPECT_EQ(can_complete_circuit.Solution1(gas, cost), ans);
    EXPECT_EQ(can_complete_circuit.Solution2(gas, cost), ans);
}

int main() {

    cout << "test_can_complete_circuit..." << endl;

    TestCase({1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}, 3);
    TestCase({2, 3, 4}, {3, 4, 3}, -1);

    cout << "test_done!" << endl << endl;

    return 0;
}