/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) {
            return 0;
        }
        int result = 1;
        int index = 0;
        if(index + nums[index] >= nums.size() - 1) {
            return result;
        }
        while(index < nums.size() - 1) {
            int next = index + 1;
            for(int i = index + 1; i <= index + nums[index]; i++) {
                if(i >= nums.size() - 1) {
                    next = i;
                    break;
                }
                if(i + nums[i] >= nums.size() - 1) {
                    next = i + nums[i];
                    result++;
                    break;
                }
                if(i + nums[i] > next + nums[next]) {
                    next = i;
                }
            }
            index = next;
            if(index >= nums.size() - 1) {
                break;
            }
            result++;
        }
        return result;
    }
};

