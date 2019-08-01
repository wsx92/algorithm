/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        if(nums[l] >= target) {
            return 0;
        }
        if(nums[r] == target) {
            return r;
        }
        if(nums[r] < target) {
            return r + 1;
        }
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(l + 1 == r) {
                break;
            }
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return l + 1;
    }
};

