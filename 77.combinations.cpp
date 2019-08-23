/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */
class Solution {
public:
    
    void dfs(vector<vector<int>>& result, vector<int>& path, int n, int k, int index) {
        if(path.size() >= k) {
            result.push_back(path);
            return;
        }
        for(int i = index; i <= n; i++) {
            path.push_back(i);
            dfs(result, path, n, k, i + 1);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if(n < k) {
            return result;
        }
        vector<int> path;
        dfs(result, path, n, k, 1);
        return result;
    }
};

