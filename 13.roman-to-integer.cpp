/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int index = s.size() - 1;
        while(index >= 0) {
            if(s[index] == 'I') {
                result += 1;
            }
            if(s[index] == 'V') {
                if(index - 1 >= 0 && s[index - 1] == 'I') {
                    result += 4;
                    index--;
                }
                else {
                    result += 5;
                }
            }
            if(s[index] == 'X') {
                if(index - 1 >= 0 && s[index - 1] == 'I') {
                    result += 9;
                    index--;
                }
                else {
                    result += 10;
                }
            }
            if(s[index] == 'L') {
                if(index - 1 >= 0 && s[index - 1] == 'X') {
                    result += 40;
                    index--;
                }
                else {
                    result += 50;
                }
            }
            if(s[index] == 'C') {
                if(index - 1 >= 0 && s[index - 1] == 'X') {
                    result += 90;
                    index--;
                }
                else {
                    result += 100;
                }
            }
            if(s[index] == 'D') {
                if(index - 1 >= 0 && s[index - 1] == 'C') {
                    result += 400;
                    index--;
                }
                else {
                    result += 500;
                }
            }
            if(s[index] == 'M') {
                if(index - 1 >= 0 && s[index - 1] == 'C') {
                    result += 900;
                    index--;
                }
                else {
                    result += 1000;
                }
            }
            index--;
        }
        return result;
    }
};

