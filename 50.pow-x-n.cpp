/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        for(int i = n; i != 0; i /= 2) {
            if(i % 2) {
                result *= x;
            }
            x *= x;
        }
        if(n < 0) {
            return 1 / result; 
        }
        else {
            return result;
        }
    }
};

