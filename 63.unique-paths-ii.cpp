/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        vector<vector<long>> dp(row, vector<long>(column, 0));
        for(int i = 0; i < row; i++) {
            if(obstacleGrid[i][0]) {
                dp[i][0] = 0;
                break;
            }
            else {
                dp[i][0] = 1;
            }
        }
        for(int i = 0; i < column; i++) {
            if(obstacleGrid[0][i]) {
                dp[0][i] = 0;
                break;
            }
            else {
                dp[0][i] = 1;
            }
        }
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < column; j++) {
                if(obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[row - 1][column - 1];
    }
};

