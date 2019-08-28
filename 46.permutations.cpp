/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
class Solution {
public:

    void dfs(vector<vector<int>>& result, vector<int>& nums, vector<int>& path, vector<bool>& pos) {
        if(path.size() >= nums.size()) {
            result.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(pos[i]) {
                path.push_back(nums[i]);
                pos[i] = false;
                dfs(result, nums, path, pos);
                pos[i] = true;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> pos(nums.size(), true);
        dfs(result, nums, path, pos);
        return result;
    }
};

