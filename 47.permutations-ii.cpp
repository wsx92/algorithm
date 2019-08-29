/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */
class Solution {
public:

    void dfs(vector<vector<int>>& result, vector<int>& nums, vector<int>& path, vector<bool>& pos) {
        if(path.size() >= nums.size()) {
            result.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1] && pos[i - 1]) {
                continue;
            }
            if(pos[i]) {
                path.push_back(nums[i]);
                pos[i] = false;
                dfs(result, nums, path, pos);
                pos[i] = true;
                path.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> pos(nums.size(), true);
        sort(nums.begin(), nums.end());
        dfs(result, nums, path, pos);
        return result;
    }
};

