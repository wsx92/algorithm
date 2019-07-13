/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */
class Solution {
public:

    void dfs(vector<vector<string>>& result, vector<string>& path, const int N, int index, vector<int>& pos) {
        if(index == N) {
            result.push_back(path);
            return;
        }
        for(int i = 0; i < N; i++) {
            bool flag = true;
            for(int j = 0; j < index; j++) {
                if(pos[j] == i || abs(index - j) == abs(i - pos[j])) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                path[index][i] = 'Q';
                pos[index] = i;
                dfs(result, path, N, index + 1, pos);
                pos[index] = -1;
                path[index][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> path(n, string(n, '.'));
        vector<int> pos(n, -1);
        dfs(result, path, n, 0, pos);
        return result;
    }
};

