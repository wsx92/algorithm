/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        if(digits.empty()) {
            return result;
        }
        int t = 1;
        for(int i = digits.size() - 1; i >= 0; i--) {
            int n = digits[i] + t;
            result.push_back(n % 10);
            t = n / 10;
        }
        while(t) {
            result.push_back(t % 10);
            t /= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

