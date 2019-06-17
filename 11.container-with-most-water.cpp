/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int result = min(height[l], height[r]) * (r - l);
        while(l < r) {
            if(height[l] < height[r]) {
                while(l < r) {
                    l++;
                    if(min(height[l], height[r]) * (r - l) > result) {
                        result = min(height[l], height[r]) * (r - l);
                    }
                    if(height[l] > height[r]) {
                        break;
                    }
                }
            }
            else {
                while(l < r) {
                    r--;
                    if(min(height[l], height[r]) * (r - l) > result) {
                        result = min(height[l], height[r]) * (r - l);
                    }
                    if(height[l] < height[r]) {
                        break;
                    }
                }
            }
        }
        return result;
    }
};

