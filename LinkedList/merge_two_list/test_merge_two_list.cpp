#include "merge_two_list.hpp"
#include <functional>
#include <vector>
#include <gtest/gtest.h>

using Solution = std::function<ListNode*(ListNode*, ListNode*)>;

void TestCase(vector<int> vec1, vector<int> vec2, vector<int> ans, Solution solution) {
    ListNode* l1 = GenerateList(vec1);
    ListNode* l2 = GenerateList(vec2);

    ListNode* ret = solution(l1, l2);
    ListNode* cur = ret;

    for (auto it : ans) {
        EXPECT_EQ(it, cur->val);
        cur = cur->next;
    }

    FreeList(ret);
}

int main() {

    cout << "<<<<<< test_merge_list..." << endl;

    MergeTwoList merge;
    TestCase({1, 2, 4}, {1, 3, 4}, {1, 1, 2, 3, 4, 4}, std::bind(&MergeTwoList::Solution1, merge, placeholders::_1, placeholders::_2));
    TestCase({1, 2, 4}, {1, 3, 4}, {1, 1, 2, 3, 4, 4}, std::bind(&MergeTwoList::Solution2, merge, placeholders::_1, placeholders::_2));
    TestCase({1, 2, 4}, {1, 3, 4}, {1, 1, 2, 3, 4, 4}, std::bind(&MergeTwoList::Solution3, merge, placeholders::_1, placeholders::_2));

    TestCase({}, {}, {}, std::bind(&MergeTwoList::Solution1, merge, placeholders::_1, placeholders::_2));
    TestCase({}, {}, {}, std::bind(&MergeTwoList::Solution2, merge, placeholders::_1, placeholders::_2));
    TestCase({}, {}, {}, std::bind(&MergeTwoList::Solution3, merge, placeholders::_1, placeholders::_2));

    TestCase({}, {0}, {0}, std::bind(&MergeTwoList::Solution1, merge, placeholders::_1, placeholders::_2));
    TestCase({}, {0}, {0}, std::bind(&MergeTwoList::Solution2, merge, placeholders::_1, placeholders::_2));
    TestCase({}, {0}, {0}, std::bind(&MergeTwoList::Solution3, merge, placeholders::_1, placeholders::_2));

    cout << "test done!" << endl << endl;

    return 0;
}
