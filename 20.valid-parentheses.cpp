/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.push_back(s[i]);
            }
            else {
                if(stack.empty()) {
                    return false;
                }
                if(s[i] == ')') {
                    if(stack[stack.size() - 1] != '(') {
                        return false;
                    }
                }
                if(s[i] == ']') {
                    if(stack[stack.size() - 1] != '[') {
                        return false;
                    }
                }
                if(s[i] == '}') {
                    if(stack[stack.size() - 1] != '{') {
                        return false;
                    }
                }
                stack.pop_back();
            }
        }
        if(stack.empty()) {
            return true;
        }
        return false;
    }
};

