/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty()) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size() - 1; i++) {
            int l = 0;
            int r = nums.size() - 1;
            while(l < i && i < r) {
                if(nums[l] + nums[i] + nums[r] == 0) {
                    vector<int> v = {nums[l], nums[i], nums[r]};
                    bool flag = true;
                    for(int j = 0; j < result.size(); j++) {
                        if(v.size() == result[j].size()) {
                            bool same = true;
                            for(int k = 0; k < v.size(); k++) {
                                if(v[k] != result[j][k]) {
                                    same = false;
                                    break;
                                }
                            }
                            if(same) {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if(flag) {
                        result.push_back(v);
                    }
                    l++;
                    while(l < nums.size() && nums[l] == nums[l - 1]) {
                        l++;
                    }
                    r--;
                    while(r > 0 && nums[r] == nums[r + 1]) {
                        r--;
                    }

                }
                else if(nums[l] + nums[i] + nums[r] > 0) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        return result;
    }
};

