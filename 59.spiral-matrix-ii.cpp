/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        if(n <= 0) {
            return result;
        }
        result = vector<vector<int>>(n, vector<int>(n));
        int l = 0;
        int r = n - 1;
        int top = 0;
        int bottom = n - 1;
        int index = 1;
        while(l < r && top < bottom) {
            for(int i = l; i <= r; i++) {
                result[top][i] = index++;
            }
            for(int i = top + 1; i < bottom; i++) {
                result[i][r] = index++;
            }
            for(int i = r; i >= l; i--) {
                result[bottom][i] = index++;
            }
            for(int i = bottom - 1; i > top; i--) {
                result[i][l] = index++;
            }
            l++;
            r--;
            top++;
            bottom--;
        }
        if(l < r && top == bottom) {
            for(int i = l; i <= r; i++) {
                result[top][i] = index++;
            }
        }
        if(top < bottom && l == r) {
            for(int i = top; i <= bottom; i++) {
                result[i][l] = index++;
            }
        }
        if(l == r && top == bottom) {
            result[top][l] = index++;
        }
        return result;
    }
};

