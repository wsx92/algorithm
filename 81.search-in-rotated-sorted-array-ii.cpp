/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */
class Solution {
public:

    bool binary_search(vector<int>& nums, int l, int r, int target) {
        if(l > r) {
            return false;
        }
        int mid = l + (r - l) / 2;
        if(nums[mid] == target) {
            return true;
        }
        if(nums[l] == nums[r]) {
            if(nums[l] == target) {
                return true;
            }
            int i = l;
            int j = r;
            while(i < nums.size() && nums[i] == nums[l]) {
                i++;
            }
            while(j >= 0 && nums[j] == nums[r]) {
                j--;
            }
            return binary_search(nums, i, j, target);
        }
        else if(nums[l] <= nums[mid] && nums[mid] <= nums[r]) {
            if(nums[mid] < target) {
                return binary_search(nums, mid + 1, r, target);
            }
            else {
                return binary_search(nums, l, mid - 1, target);
            }
        }
        else if(nums[l] <= nums[mid] && nums[mid] >= nums[r]) {
            if(nums[l] <= target && target <= nums[mid]) {
                return binary_search(nums, l, mid - 1, target);
            }
            else {
                return binary_search(nums, mid + 1, r, target);
            }
        }
        else {
            if(nums[mid] <= target && target <= nums[r]) {
                return binary_search(nums, mid + 1, r, target);
            }
            else {
                return binary_search(nums, l, mid - 1, target);
            }
        }
    }

    bool search(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size() - 1, target);
    }
};

