/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
class Solution {
public:
    int reverse(int x) {
        bool flag = false;
        long t = x;
        if(t < 0) {
            flag = true;
            t = -t;
        }
        long result = 0;
        while(t > 0) {
            result *= 10;
            result += t % 10;
            t /= 10;
        }
        if(flag) {
            result = -result;
        }
        if(result > INT_MAX || result < INT_MIN) {
            return 0;
        }
        return result;
    }
};

