/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.empty() && p.empty()) {
            return true;
        }
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= p.size(); i++) {
            if(p[i - 1] == '*') {
                if(dp[0][i - 2]) {
                    dp[0][i] = true;
                }
            }
        }
        for(int i = 1; i <= s.size(); i++) {
            for(int j = 1; j <= p.size(); j++) {
                bool match = false;
                if(s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    match |= dp[i - 1][j - 1];
                }
                if(p[j - 1] == '*') {
                    match |= dp[i][j - 2];
                    int k = i;
                    while(k > 0) {
                        if(p[j - 2] == s[k - 1] || p[j - 2] == '.') {
                            match |= dp[k - 1][j - 2];
                            k--;
                        }
                        else {
                            break;
                        }
                    }
                }
                dp[i][j] = match;
            }
        }
        return dp[s.size()][p.size()];
    }
};

