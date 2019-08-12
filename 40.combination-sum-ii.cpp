/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
class Solution {
public:

    void dfs(vector<vector<int>>& result, vector<int>& path, vector<bool>& pos, int index, int sum, vector<int>& candidates, int target) {
        if(sum >= target) {
            if(sum == target) {
                result.push_back(path);
            }
            return;
        }
        for(int i = index; i < candidates.size(); i++) {
            if(pos[i]) {
                pos[i] = false;
                path.push_back(candidates[i]);
                dfs(result, path, pos, i + 1, sum + candidates[i], candidates, target);
                pos[i] = true;
                path.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> pos(candidates.size(), true);
        sort(candidates.begin(), candidates.end());
        dfs(result, path, pos, 0, 0, candidates, target);
        return result;
    }
};

