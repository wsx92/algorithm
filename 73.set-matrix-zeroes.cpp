/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row = false;
        bool column = false;
        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[i][0] == 0) {
                column = true;
            }
        }
        for(int i = 0; i < matrix[0].size(); i++) {
            if(matrix[0][i] == 0) {
                row = true;
            }
        }
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[i].size(); j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(row) {
            for(int i = 0; i < matrix[0].size(); i++) {
                matrix[0][i] = 0;
            }
        }
        if(column) {
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

