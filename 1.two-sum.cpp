/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
class Solution {
public:

    void qsort(vector<int>& v, int l, int r, vector<int>& pos) {
        if(l > r) {
            return;
        }
        int key = v[l];
        int j = l;
        for(int i = l + 1; i <= r; i++) {
            if(v[i] < key) {
                j++;
                std::swap(v[i], v[j]);
                std::swap(pos[i], pos[j]);
            }
        }
        std::swap(v[l], v[j]);
        std::swap(pos[l], pos[j]);
        qsort(v, l, j - 1, pos);
        qsort(v, j + 1, r, pos);
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.empty()) {
            return result;
        }
        vector<int> pos;
        for(int i = 0; i < nums.size(); i++) {
            pos.push_back(i);
        }
        qsort(nums, 0, nums.size() - 1, pos);
        int l = 0;
        int r = nums.size() - 1;
        while(l < r) {
            if(nums[l] + nums[r] == target) {
                break;
            }
            else if(nums[l] + nums[r] < target) {
                l++;
            }
            else {
                r--;
            }
        }
        result.push_back(pos[l]);
        result.push_back(pos[r]);
        return result;
    }
};

