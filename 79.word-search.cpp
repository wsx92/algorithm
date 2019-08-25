/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
class Solution {
public:

    bool dfs(vector<vector<char>>& board, string& word, int index, vector<vector<bool>>& pos, int i, int j) {
        if(index >= word.size()) {
            return true;
        }
        if(i > 0 && pos[i - 1][j] && word[index] == board[i - 1][j]) {
            pos[i - 1][j] = false;
            if(dfs(board, word, index + 1, pos, i - 1, j)) {
                return true;
            }
            pos[i - 1][j] = true;
        }
        if(j > 0 && pos[i][j - 1] && word[index] == board[i][j - 1]) {
            pos[i][j - 1] = false;
            if(dfs(board, word, index + 1, pos, i, j - 1)) {
                return true;
            }
            pos[i][j - 1] = true;
        }
        if(i < board.size() - 1 && pos[i + 1][j] && word[index] == board[i + 1][j]) {
            pos[i + 1][j] = false;
            if(dfs(board, word, index + 1, pos, i + 1, j)) {
                return true;
            }
            pos[i + 1][j] = true;
        }
        if(j < board[0].size() - 1 && pos[i][j + 1] && word[index] == board[i][j + 1]) {
            pos[i][j + 1] = false;
            if(dfs(board, word, index + 1, pos, i, j + 1)) {
                return true;
            }
            pos[i][j + 1] = true;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == word[0]) {
                    vector<vector<bool>> pos(board.size(), vector<bool>(board[0].size(), true));
                    pos[i][j] = false;
                    if(dfs(board, word, 1, pos, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

