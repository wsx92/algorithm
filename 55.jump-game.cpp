/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(index < i) {
                break;
            }
            if(i + nums[i] > index) {
                index = i + nums[i];
            }
        }
        if(index >= nums.size() - 1) {
            return true;
        }
        return false;
    }
};

