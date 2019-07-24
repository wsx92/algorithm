/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) {
            return;
        }
        int l = nums.size() - 1;
        while(l >= 0) {
            l--;
            if(l >= 0) {
                if(nums[l] < nums[l + 1]) {
                    break;
                }
            }
        }
        if(l < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        reverse(nums.begin() + l + 1, nums.end());
        int r = -1;
        for(int i = l + 1; i < nums.size(); ++i) {
            if(nums[i] > nums[l]) {
                if(r == -1) {
                    r = i;
                }
                else if(nums[i] < nums[r]) {
                    r = i;
                }
            }
        }
        swap(nums[l], nums[r]);
    }
};

