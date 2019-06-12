/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        long reverse = 0;
        int t = x;
        while(t > 0) {
            reverse *= 10;
            reverse += t % 10;
            t /= 10;
        }
        if(reverse == x) {
            return true;
        }
        return false;
    }
};

