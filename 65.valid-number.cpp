/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */
class Solution {
public:
    bool isNumber(string s) {
        if(s.empty()) {
            return false;
        }
        bool flag = false;
        int i = 0;
        while(s[i] == ' '){
            i++;
            if(i >= s.size()) {
                return false;
            }
        }
        if(s[i] == '-' || s[i] == '+') {
            i++;
            if(i >= s.size()) {
                return false;
            }
        }
        while(s[i] >= '0' && s[i] <= '9') {
            flag = true;
            i++;
            if(i >= s.size()) {
                return true;
            }
        }
        if(s[i] == '.') {
            i++;
            if(i >= s.size()) {
                if(flag) {
                    return true;
                }
                else {
                    return false;
                }
            }
            if(s[i] == ' ') {
                while(s[i] == ' ') {
                    i++;
                    if(i >= s.size()) {
                        if(flag) {
                            return true;
                        }
                        else {
                            return false;
                        }
                    }
                }
                if(i >= s.size()) {
                    if(flag) {
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
            if(!(s[i] >= '0' && s[i] <= '9') && s[i] != 'e') {
                return false;
            }
        }
        else {
            if(s[i] != 'e' && s[i] != ' ') {
                return false;
            }
        }
        while(s[i] >= '0' && s[i] <= '9') {
            flag = true;
            i++;
            if(i >= s.size()) {
                return true;
            }
        }
        if(s[i] == 'e') {
            if(!flag) {
                return false;
            }
            i++;
            if(i >= s.size()) {
                return false;
            }
            if(s[i] == ' ') {
                while(s[i] == ' ') {
                    i++;
                    if(i >= s.size()) {
                        return false;
                    }
                }
            }
        }
        if(s[i] == '-' || s[i] == '+') {
            i++;
            if(i >= s.size()) {
                return false;
            }
        }
        while(s[i] >= '0' && s[i] <= '9') {
            i++;
            if(i >= s.size()) {
                return true;
            }
        }
        while(s[i] == ' '){
            i++;
            if(i >= s.size()) {
                return true;
            }
        }
        if(i >= s.size()) {
            return true;
        }
        return false;
    }
};

