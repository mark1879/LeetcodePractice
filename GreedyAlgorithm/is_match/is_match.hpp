#ifndef IS_MATCH_HPP
#define IS_MATCH_HPP
/**
    44. 通配符匹配
    
    给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
    '?' 可以匹配任何单个字符。
    '*' 可以匹配任意字符串（包括空字符串）。
    两个字符串完全匹配才算匹配成功。
    
    说明:
        s 可能为空，且只包含从 a-z 的小写字母。
        p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
 */

#include <iostream>
#include <vector>

using namespace std;

class IsMatch {
public:
    // 回朔法
    bool Solution1(string s, string p) {
        int size_s = (int)s.size();
        int size_p = (int)p.size();
        int i = 0, j = 0;
        int star = -1;
        int last_match = -1;

        while (i < size_s) {
            if (j < size_p && (s[i] == p[j] || p[j] == '?')) {
                ++i;
                ++j;
            } else if (j < size_p && p[j] == '*') {
                last_match = i;
                star = j;
                j++;
            } else if (star != -1) {
                i = last_match++;
                j = star + 1;
            } else {
                return false;
            }
        }

        while (j < size_p && p[j] == '*')
            j++;

        return j == size_p;
    }

    // 动态规划
    bool Solution2(string s, string p) { 
        int size_s = (int)s.size();
        int size_p = (int)p.size();

        vector<vector<bool>> dp(size_s + 1, vector<bool>(size_p + 1));
        dp[0][0] = true;

        for (int j = 1; j <= size_p; j++) {
            if (p[j - 1] == '*')
                dp[0][j] = true;
            else
                break;
        }

        for (int i = 1; i <= size_s; i++) {
            for (int j = 1; j <= size_p; j++) {
               if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[size_s][size_p];
    }

};

#endif