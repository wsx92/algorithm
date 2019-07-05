/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
class Solution {
public:

    void dfs(vector<string>& result, string& path, int l, int r) {
        if(l < 0 || r < 0) {
            return;
        }
        if(r == 0) {
            result.push_back(path);
            return;
        }
        if(l < r) {
            path.push_back('(');
            dfs(result, path, l - 1, r);
            path.pop_back();
            path.push_back(')');
            dfs(result, path, l, r - 1);
            path.pop_back();
        }
        else {
            path.push_back('(');
            dfs(result, path, l - 1, r);
            path.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;
        dfs(result, path, n, n);
        return result;
    }
};

