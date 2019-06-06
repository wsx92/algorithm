/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
class Solution {
public:
    string longestPalindrome(string s) {
        string result;
        for(int i = 0; i < s.size(); i++) {
            int l = i;
            int r = i;
            while(l >= 0 && r < s.size()) {
                if(s[l] == s[r]) {
                    if(r - l + 1 >= result.size()) {
                        result = s.substr(l, r - l + 1);
                    }
                    l--;
                    r++;
                }
                else {
                    break;
                }
            }
            l = i;
            r = i + 1;
            while(l >= 0 && r < s.size()) {
                if(s[l] == s[r]) {
                    if(r - l + 1 >= result.size()) {
                        result = s.substr(l, r - l + 1);
                    }
                    l--;
                    r++;
                }
                else {
                    break;
                }
            }
        }
        return result;
    }
};

