/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */
class Solution {
public:

    int longestValidParentheses(string s) {
        if(s.size() <= 1) {
            return 0;
        }
        vector<int> dp(s.size());
        int result = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                dp[i] = 0;
            }
            else {
                if(i - 1 >= 0) {
                    if(s[i - 1] == '(') {
                        dp[i] = 2;
                        if(i - 2 >= 0) {
                            dp[i] += dp[i - 2];
                        }
                    }
                    else {
                        if(i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '(') {
                            dp[i] = dp[i - 1] + 2;
                            if(i - 1 - dp[i - 1] - 1 >= 0) {
                                dp[i] += dp[i - 1 - dp[i - 1] - 1];
                            }
                        }
                    }
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};

