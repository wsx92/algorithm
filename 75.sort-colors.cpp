/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j = -1;
        int k = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                j++;
                k++;
                swap(nums[i], nums[k]);
                swap(nums[j], nums[k]);
            }
            else if(nums[i] == 1) {
                k++;
                swap(nums[i], nums[k]);
            }
        }
    }
};

