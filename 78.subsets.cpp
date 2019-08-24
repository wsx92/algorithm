/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */
class Solution {
public:

    void dfs(vector<vector<int>>& result, vector<int>& path, vector<int>& nums, int n, int index, vector<bool>& pos) {
        if(path.size() >= n) {
            result.push_back(path);
            return;
        }
        for(int i = index; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1] && !pos[i - 1]) {
                continue;
            }
            if(pos[i]) {
                path.push_back(nums[i]);
                pos[i] = false;
                dfs(result, path, nums, n, i + 1, pos);
                pos[i] = true;
                path.pop_back();
            }
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        result.push_back(path);
        sort(nums.begin(), nums.end());
        for(int i = 1; i <= nums.size(); i++) {
            vector<bool> pos(nums.size(), true);
            dfs(result, path, nums, i, 0, pos);
        }
        return result;
    }
};

