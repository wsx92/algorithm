/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
class Solution {
public:

    void dfs(vector<vector<int>>& result, vector<int>& path, int index, int sum, vector<int>& candidates, int target) {
        if(sum >= target) {
            if(sum == target) {
                result.push_back(path);
            }
            return;
        }
        for(int i = index; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            dfs(result, path, i, sum + candidates[i], candidates, target);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(result, path, 0, 0, candidates, target);
        return result;
    }
};

