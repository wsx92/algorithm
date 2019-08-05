/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            set<char> s1;
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    if(s1.find(board[i][j]) != s1.end()) {
                        return false;
                    }
                    s1.insert(board[i][j]);
                }
            }
            set<char> s2;
            for(int j = 0; j < 9; j++) {
                if(board[j][i] != '.') {
                    if(s2.find(board[j][i]) != s2.end()) {
                        cout<<2;
                        return false;
                    }
                    s2.insert(board[j][i]);
                }
            }
            set<char> s3;
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 3; k++) {
                    if(board[(i / 3) * 3 + j][(i % 3) * 3 + k] != '.') {
                        if(s3.find(board[(i / 3) * 3 + j][(i % 3) * 3 + k]) != s3.end()) {
                            return false;
                        }
                        s3.insert(board[(i / 3) * 3 + j][(i % 3) * 3 + k]);
                    }
                }
            }
        }
        return true;
    }
};

