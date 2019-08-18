/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0) {
            return 0;
        }
        if(n == 1) {
            return 1;
        }
        if(n == 2) {
            return 2;
        }
        int n1 = 1;
        int n2 = 2;
        for(int i = 2; i < n ; i++) {
            int t = n2;
            n2 = n1 + n2;
            n1 = t;
        }
        return n2;
    }
};

