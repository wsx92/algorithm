/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) {
            return nums.size();
        }
        int i = 1;
        for(int j = 2; j < nums.size(); j++) {
            if(nums[j] != nums[i] || nums[j] != nums[i - 1]) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        return i + 1;
    }
};

