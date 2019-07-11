/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int l = 0;
        int r = l + 1;
        while(l < nums.size() && r < nums.size()) {
            if(nums[l] != nums[r]) {
                l++;
                swap(nums[l], nums[r]);
            }
            r++;
        }
        return l + 1;
    }
};

