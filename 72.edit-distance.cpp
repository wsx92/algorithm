/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        dp[0][0] = 0;
        for(int i = 1; i <= word1.size(); i++) {
            dp[i][0] = i;
        }
        for(int i = 1; i <= word2.size(); i++) {
            dp[0][i] = i;
        }
        for(int i = 1; i <= word1.size(); i++) {
            for(int j = 1; j <= word2.size(); j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i][j - 1] + 1, dp[i -1][j] + 1));
                }
                else {
                    dp[i][j] = std::min(dp[i - 1][j - 1] + 1, std::min(dp[i][j - 1] + 1, dp[i -1][j] + 1));
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

