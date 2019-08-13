/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
class Solution {
public:

    void heightFirst(vector<int>& height, int& sum, int l, int r) {
        if(l + 1 >= r) {
            return;
        }
        int first = l;
        int second = l + 1;
        if(height[first] < height[second]) {
            swap(first, second);
        }
        for(int i = l + 2; i <= r; i++) {
            if(height[i] > height[first]) {
                second = first;
                first = i;
            }
            else if(height[i] > height[second]) {
                second = i;
            }
        }
        int low = height[second];
        if(first > second) {
            swap(first, second);
        }
        for(int i = first + 1; i < second; i++) {
            sum += low - height[i];
        }
        heightFirst(height, sum, l, first);
        heightFirst(height, sum, second, r);
    }

    int trap(vector<int>& height) {
        int result = 0;
        heightFirst(height, result, 0, height.size() - 1);
        return result;
    }
};

