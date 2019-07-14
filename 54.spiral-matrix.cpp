/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty() || matrix[0].empty()) {
            return result;
        }
        int l = 0;
        int r = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        while(l < r && top < bottom) {
            for(int i = l; i <= r; i++) {
                result.push_back(matrix[top][i]);
            }
            for(int i = top + 1; i < bottom; i++) {
                result.push_back(matrix[i][r]);
            }
            for(int i = r; i >= l; i--) {
                result.push_back(matrix[bottom][i]);
            }
            for(int i = bottom - 1; i > top; i--) {
                result.push_back(matrix[i][l]);
            }
            l++;
            r--;
            top++;
            bottom--;
        }
        if(l < r && top == bottom) {
            for(int i = l; i <= r; i++) {
                result.push_back(matrix[top][i]);
            }
        }
        if(top < bottom && l == r) {
            for(int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][l]);
            }
        }
        if(l == r && top == bottom) {
            result.push_back(matrix[top][l]);
        }
        return result;
    }
};

