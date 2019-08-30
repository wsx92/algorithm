/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int l = 0;
        int r = n - 1;
        int top = 0;
        int bottom = n - 1;
        while(l < r && top < bottom) {
            for(int i = 0; i < r - l; i++) {
                swap(matrix[top][l + i], matrix[top + i][r]);
                swap(matrix[top][l + i], matrix[bottom][r - i]);
                swap(matrix[top][l + i], matrix[bottom - i][l]);
            }
            l++;
            r--;
            top++;
            bottom--;
        }
    }
};

