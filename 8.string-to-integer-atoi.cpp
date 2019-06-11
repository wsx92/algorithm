/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        if(str.empty()) {
            return 0;
        }
        int index = 0;
        bool flag = false;
        while(index < str.size()) {
            if(str[index] >= '0' && str[index] <= '9') {
                break;
            }
            else if(str[index] == ' '){
                index++;
            }
            else if(str[index] == '-') {
                flag = true;
                index++;
                break;
            }
            else if(str[index] == '+') {
                index++;
                break;
            }
            else {
                return 0;
            }
        }
        while(index < str.size()) {
            if(str[index] >= '0' && str[index] <= '9') {
                result *= 10;
                result += str[index] - '0';
                index++;
                if(result > INT_MAX) {
                    if(flag) {
                        return INT_MIN;
                    }
                    else {
                        return INT_MAX;
                    }
                }
            }
            else {
                break;
            }
        }
        if(flag) {
            result = -result;
        }
        if(result > INT_MAX) {
            return INT_MAX;
        }
        if(result < INT_MIN) {
            return INT_MIN;
        }
        return result;
    }
};

