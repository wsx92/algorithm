/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        long l = 0;
        long r = INT_MAX;
        r += 2;
        bool flag = false;
        long k = dividend;
        long n = divisor;
        if(k < 0 && n < 0) {
            k = -k;
            n = -n;
        }
        if(k < 0) {
            k = -k;
            flag = true;
        }
        if(n < 0) {
            n = -n;
            flag = true;
        }
        while(l < r) {
            long mid = l + (r - l) / 2;
            if(l + 1 == r) {
                break;
            }
            if(mid * n == k) {
                if(flag) {
                    if(-mid < INT_MIN) {
                        return INT_MIN;
                    }
                    return -mid;
                }
                if(mid > INT_MAX) {
                    return INT_MAX;
                }
                return mid;
            }
            else if(mid * n < k) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        if(flag) {
            if(-l < INT_MIN) {
                return INT_MAX;
            }
            return -l;
        }
        if(l > INT_MAX) {
            return INT_MAX;
            
        }
        return l;
    }
};

