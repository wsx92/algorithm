/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        string result;
        if(strs.empty()) {
            return result;
        }
        while(true) {
            bool flag = false;
            for(string str : strs) {
                if(index >= str.size()) {
                    flag = true;
                    break;
                }
                else if(strs[0][index] != str[index]) {
                    flag = true;
                    break;
                }
            }
            if(flag) {
                break;
            }
            result.push_back(strs[0][index++]);
        }
        return result;
    }
};

