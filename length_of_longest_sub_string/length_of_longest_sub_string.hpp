#ifndef LENGTH_OF_LONGEST_SUB_STRING_HPP
#define LENGTH_OF_LONGEST_SUB_STRING_HPP

/**
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 0 <= s.length <= 5 * 104
 * s 由英文字母、数字、符号和空格组成
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

class LengthOfLongestSubString {
public:
    int Solution1(string s) {
        unordered_map<char, int> occ;
        int max_length = 0;
        int lp = 0;

        for (int i = 0, size = (int)s.size(); i < size; i++) {
            auto it = occ.find(s[i]);
            while (it != occ.end() && it->second >= lp) {
                lp = it->second + 1;
            }

            occ[s[i]] = i;
            max_length = max(max_length, (i - lp + 1));
        }
     
        return max_length;
    }

    int Solution2(string s) {
        int max_length = 0;
        vector<char> vec;

        for (auto c : s) {
            auto it = find(vec.begin(), vec.end(), c);
            if (it != vec.end()) {
                max_length = max(max_length, (int)vec.size());
                vec.erase(vec.begin(), it + 1);
            }

            vec.push_back(c);
        }

        return max(max_length, (int)vec.size());
    }

    int Solution3(string s) {
        int max_length = 0;
        unordered_set<char> uos;
        int rp = -1;

        for (int i = 0, size = (int)s.size(); i < size; i++) {
            if (i > 0)
                uos.erase(s[i - 1]);

            while (rp + 1 < size && !uos.count(s[rp + 1])) {
                uos.insert(s[rp + 1]);
                ++rp;
            }

            max_length = max(max_length, (rp - i + 1));

            if (rp == size - 1)
                break;
        }

        return max_length;
    }
};

#endif