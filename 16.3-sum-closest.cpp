/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        long result = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size() - 1; i++) {
            int l = 0;
            int r = nums.size() - 1;
            while(l < i && i < r) {
                long sum = nums[l] + nums[i] + nums[r];
                if(sum == target) {
                    return target;
                }
                else if(sum < target) {
                    l++;
                    if(result < target) {
                        if(target - result > target - sum) {
                            result = sum;
                        }
                    }
                    else {
                        if(result - target > target - sum) {
                            result = sum;
                        }
                    }
                }
                else {
                    r--;
                    if(result < target) {
                        if(target - result > sum - target) {
                            result = sum;
                        }
                    }
                    else {
                        if(result - target > sum - target) {
                            result = sum;
                        }
                    }
                }
            }
        }
        return result;
    }
};

