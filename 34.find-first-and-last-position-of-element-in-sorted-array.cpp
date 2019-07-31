/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        vector<int> result;
        if(nums.empty()) {
            return {-1,-1};
        }
        if(nums.size() == 1 && nums[0] == target) {
            return {0,0};
        }
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        if(nums[l] == target) {
            result.push_back(l);
        }
        else {
            result.push_back(-1);
        }
        l = 0;
        r = nums.size() - 1;
        while(l < r) {
            int mid = l + (r - l + 1) / 2;
            if(nums[mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid;
            }
        }
        if(nums[r] == target) {
            result.push_back(r);
        }
        else {
            result.push_back(-1);
        }
        return result;
    }
};

