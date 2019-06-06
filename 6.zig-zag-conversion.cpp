/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) {
            return s;
        }
        vector<string> v(numRows);
        int index = 0;
        bool dir = true;
        for(int i = 0; i < s.size(); i++) {
            v[index].push_back(s[i]);
            if(dir) {
                if(index == numRows - 1) {
                    index--;
                    dir = false;
                }
                else {
                    index++;
                }
            }
            else {
                if(index == 0) {
                    index ++;
                    dir = true;
                }
                else {
                    index--;
                }
            }
        }
        string result;
        for(int i = 0; i < v.size(); i++) {
            result += v[i];
        }
        return result;
    }
};

