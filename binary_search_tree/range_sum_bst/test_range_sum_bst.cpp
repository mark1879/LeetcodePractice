#include "range_sum_bst.hpp"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <functional>

using Solution = std::function<int(TreeNode*, int, int)>;

void TestCase(vector<int> data, int low, int high, Solution solution, int ans) {
    TreeNode *root = BSTree::CreateBSTree(data);

    EXPECT_EQ(solution(root, low, high), ans);

    BSTree::FreeBSTree(root);
}

int main() {

    std::cout << "<<<<<< test_range_sum_bst..." << std::endl;

    RangeSumBST range_sum_bst;

    TestCase({3, 5, 7, 10, 15, 18}, 7, 15, std::bind(&RangeSumBST::Solution1, 
            range_sum_bst, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), 32);

    TestCase({3, 5, 7, 10, 15, 18}, 7, 15, std::bind(&RangeSumBST::Solution2, 
            range_sum_bst, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), 32);


    TestCase({1, 3, 5, 6, 7, 10, 13, 15, 18}, 6, 10, std::bind(&RangeSumBST::Solution1, 
            range_sum_bst, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), 23);
     TestCase({1, 3, 5, 6, 7, 10, 13, 15, 18}, 6, 10, std::bind(&RangeSumBST::Solution2, 
            range_sum_bst, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), 23);

    std::cout << "test done!" << std::endl << std::endl;

    return 0;
}