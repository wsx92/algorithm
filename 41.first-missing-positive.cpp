/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            while(nums[i] > 0 && nums[i] - 1 != i && nums[i] - 1 < nums.size()) {
                if(nums[i] == nums[nums[i] - 1]) {
                    break;
                }
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        int i = 0;
        for(; i < nums.size(); i++) {
            if(i != nums[i] - 1) {
                return i + 1;
            }
        }
        return i + 1;
    }
};

