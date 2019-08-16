/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty()) {
            return b;
        }
        if(b.empty()) {
            return a;
        }
        string result;
        int i = 0;
        int t = 0;
        while(i < a.size() && i < b.size()) {
            int n = a[a.size() - 1 - i] - '0' + b[b.size() - 1 - i] - '0' + t;
            result.push_back(n % 2 + '0');
            t = n / 2;
            i++;
        }
        while(i < a.size()) {
            int n = a[a.size() - 1 - i] - '0' + t;
            result.push_back(n % 2 + '0');
            t = n / 2;
            i++;
        }
        while(i < b.size()) {
            int n = b[b.size() - 1 - i] - '0' + t;
            result.push_back(n % 2 + '0');
            t = n / 2;
            i++;
        }
        while(t) {
            result.push_back(t % 2 + '0');
            t /= 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

