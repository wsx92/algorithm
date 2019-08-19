/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string dir;
        int i = 0;
        while(i < path.size()) {
            if(path[i] == '/') {
                if(!dir.empty()) {
                    stack.push_back(dir);
                    dir.clear();
                }
            }
            else {
                if(path[i] == '.') {
                    if(i + 1 < path.size()) {
                        if(path[i + 1] == '.') {
                            if(i + 2 < path.size()) {
                                if(path[i + 2] == '/') {
                                    if(!stack.empty()) {
                                        stack.pop_back();
                                    }
                                }
                                else {
                                    dir.push_back(path[i]);
                                    dir.push_back(path[i + 1]);
                                    dir.push_back(path[i + 2]);
                                }
                                i += 2;
                            }
                            else {
                                if(!stack.empty()) {
                                    stack.pop_back();
                                }
                            }
                        }
                        else if(path[i + 1] != '/') {
                            dir.push_back(path[i]);
                        }
                    }
                }
                else if(path[i] != '/') {
                    dir.push_back(path[i]);
                }
            }
            i++;
        }
        if(!dir.empty()) {
            stack.push_back(dir);
        }
        string result;
        for(int j = 0; j < stack.size(); j++) {
            result.push_back('/');
            result += stack[j];
        }
        if(stack.empty()) {
            return "/";
        }
        return result;
    }
};

