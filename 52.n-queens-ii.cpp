/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */
class Solution {
public:

    void dfs(int& result, int N, int index, vector<int>& pos) {
        if(index == N) {
            result++;
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
                pos[index] = i;
                dfs(result, N, index + 1, pos);
                pos[index] = -1;
            }
        }
    }

    int totalNQueens(int n) {
        int result = 0;
        vector<int> pos(n, -1);
        dfs(result, n, 0, pos);
        return result;
    }
};

