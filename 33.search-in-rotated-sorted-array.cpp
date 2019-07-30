/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
class Solution {
public:

    int binary_search(vector<int>& v, int l, int r, int target) {
        if(l > r) {
            return -1;
        }
        int mid = l + (r - l) / 2;
        if(v[mid] == target) {
            return mid;
        }
        if(v[l] <= v[mid] && v[mid] <= v[r]) {
            if(target < v[mid]) {
                return binary_search(v, l, mid - 1, target);
            }
            else {
                return binary_search(v, mid + 1, r, target);
            }
        }
        else if(v[l] <= v[mid] && v[mid] >= v[r]) {
            if(target < v[mid] && target >= v[l]) {
                return binary_search(v, l, mid - 1, target);
            }
            else {
                return binary_search(v, mid + 1, r, target);
            }
        }
        else {
            if(target > v[mid] && target <= v[r]) {
                return binary_search(v, mid + 1, r, target);
            }
            else {
                return binary_search(v, l, mid -1 , target);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size() - 1, target);
    }
};

