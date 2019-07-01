/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            while(i > 0 && i < nums.size() && nums[i] == nums[i -1]) {
                i++;
            }
            for(int j = nums.size() - 1; j > i + 2; j--) {
                while(j > 0 && j < nums.size() - 1 && nums[j] == nums[j + 1]) {
                    j--;
                }
                int l = i + 1;
                int r = j - 1;
                int sum = nums[i] + nums[j];
                while(l < r) {
                    if(sum + nums[l] + nums[r] == target) {
                        result.push_back({nums[i], nums[l], nums[r], nums[j]});
                        l++;
                        while(l < r && nums[l - 1] == nums[l]) {
                            l++;
                        }
                        r--;
                        while(l < r && nums[r] == nums[r + 1]) {
                            r--;
                        }
                    }
                    else if(sum + nums[l] + nums[r] < target) {
                        l++;
                    }
                    else {
                        r--;
                    }
                }
            }
        }
        return result;
    }
};

