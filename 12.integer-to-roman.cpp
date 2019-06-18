/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */
class Solution {
public:
    string intToRoman(int num) {
        string result;
        while(num >= 1000) {
            result.push_back('M');
            num -= 1000;
        }
        while(num >= 100) {
            if(num >= 900) {
                result.push_back('C');
                result.push_back('M');
                num -= 900;
            }
            else if(num >= 500) {
                result.push_back('D');
                num -= 500;
            }
            else if(num >= 400) {
                result.push_back('C');
                result.push_back('D');
                num -= 400;
            }
            else {
                int x = num / 100;
                for(int i = 0; i < x; i++) {
                    result.push_back('C');
                    num -= 100;
                }
            }
        }
        while(num >= 10) {
            if(num >= 90) {
                result.push_back('X');
                result.push_back('C');
                num -= 90;
            }
            else if(num >= 50) {
                result.push_back('L');
                num -= 50;
            }
            else if(num >= 40) {
                result.push_back('X');
                result.push_back('L');
                num -= 40;
            }
            else {
                int x = num / 10;
                for(int i = 0; i < x; i++) {
                    result.push_back('X');
                    num -= 10;
                }
            }
        }
        while(num >= 1) {
            if(num >= 9) {
                result.push_back('I');
                result.push_back('X');
                num -= 9;
            }
            else if(num >= 5) {
                result.push_back('V');
                num -= 5;
            }
            else if(num >= 4) {
                result.push_back('I');
                result.push_back('V');
                num -= 4;
            }
            else {
                int x = num / 1;
                for(int i = 0; i < x; i++) {
                    result.push_back('I');
                    num -= 1;
                }
            }
        }
        return result;
    }
};

