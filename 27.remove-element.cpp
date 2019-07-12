/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = -1;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] != val) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        return i + 1;
    }
};

