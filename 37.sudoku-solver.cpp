/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */
class Solution {
public:

    void dfs(vector<vector<char>>& result, vector<vector<char>>& board, int index, vector<vector<bool>>& row, vector<vector<bool>>& column, vector<vector<bool>>& block) {
        if(index > 80) {
            result = board;
            return;
        }
        int i = index / 9;
        int j = index % 9;
        if(board[i][j] == '.') {
            for(int k = 0; k < 9; k++) {
                if(row[i][k] && column[j][k] && block[(i / 3) * 3 + j / 3][k]) {
                    board[i][j] = '1' + k;
                    row[i][k] = false;
                    column[j][k] = false;
                    block[(i / 3) * 3 + j / 3][k] = false;
                    dfs(result, board, index + 1, row, column, block);
                    board[i][j] = '.';
                    row[i][k] = true;
                    column[j][k] = true;
                    block[(i / 3) * 3 + j / 3][k] = true;
                }
            }
        }
        else {
            dfs(result, board, index + 1, row, column, block);
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9,vector<bool>(9, true));
        vector<vector<bool>> column(9,vector<bool>(9, true));
        vector<vector<bool>> block(9,vector<bool>(9, true));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    row[i][board[i][j] - '1'] = false;
                }
            }
            for(int j = 0; j < 9; j++) {
                if(board[j][i] != '.') {
                    column[i][board[j][i] - '1'] = false;
                }
            }
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 3; k++) {
                    if(board[(i / 3) * 3 + j][(i % 3) * 3 + k] != '.') {
                        block[i][board[(i / 3) * 3 + j][(i % 3) * 3 + k] - '1'] = false;
                    }
                }
            }
        }
        vector<vector<char>> result;
        dfs(result, board, 0, row, column, block);
        board = result;
    }
};

