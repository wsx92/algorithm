/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */
class Solution {
public:
    int mySqrt(int x) {
        if(x <= 0) {
            return 0;
        }
        int l = 1;
        int r = x / 2;
        while(l < r) {
            long mid = l + (r - l + 1) / 2;
            long multi = mid * mid;
            if(multi == x) {
                return mid;
            }
            else if(multi > x) {
                r = mid - 1;
            }
            else {
                l = mid;
            }
        }
        return l;
    }
};

