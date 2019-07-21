/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        int i = s.size() - 1;
        for(; i >= 0; i--) {
            if(s[i] != ' ') {
                break;
            }
        }
        for(; i >= 0; i--) {
            if(s[i] == ' ') {
                break;
            }
            result++;
        }
        return result;
    }
};

