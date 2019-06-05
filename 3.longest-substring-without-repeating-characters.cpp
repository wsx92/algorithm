/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int result = 0;
        std::map<char, int> map;
        for(int r = 0; r < s.size(); r++) {
            if(map.find(s[r]) != map.end()) {
                result = std::max(result, (int)map.size());
                for(;l <= map[s[r]]; l++) {
                    map.erase(s[l]);
                }
            }
            map[s[r]] = r;
        }
        result = std::max(result, (int)map.size());
        return result;
    }
};

