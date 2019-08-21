/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) {
            return false;
        }
        int l = 0;
        int r = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        while(l <= r && top <= bottom) {
            int i = top + (bottom - top) / 2;
            int j = l + (r - l) / 2;
            if(matrix[i][l] == target || matrix[i][r] == target) {
                return true;
            }
            else if(matrix[i][l] > target) {
                bottom = i - 1;
            }
            else if(matrix[i][r] < target) {
                top = i + 1;
            }
            else {
                if(matrix[i][j] == target) {
                    return true;
                }
                else if(matrix[i][j] > target) {
                    r = j - 1;
                }
                else {
                    l = j + 1;
                }
            }
        }
        return false;
    }
};

