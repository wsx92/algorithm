/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */
class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0) {
            return 0;
        }
        if(s[0] == '0') {
            return 0;
        }
        if(s.size() == 1) {
            return 1;
        }
        vector<int> dp(s.size(), 0);
        if(s[0] != '0') {
            dp[0] = 1;
        }
        dp[1] = dp[0];
        if((s[0] == '1' && s[1] >= '1' && s[1] <= '9') || (s[0] == '2' && s[1] >= '1' && s[1] <= '6')) {
            dp[1] += 1;
        }
        else if(s[1] == '0' && s[0] >= '3') {
            dp[1] = 0;
        }
        for(int i = 2; i < s.size(); i++) {
            if(s[i] != '0') {
                dp[i] = dp[i - 1];
            }
            if((s[i - 1] == '1' && s[i] >= '0' && s[i] <= '9') || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6')) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.size() - 1];
    }
};

