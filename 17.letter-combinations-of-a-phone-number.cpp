/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
class Solution {
public:

    vector<string> number = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(string& str, int index, string& path, vector<string>& result) {
        if(index >= str.size()) {
            result.push_back(path);
            return;
        }
        for(int i = 0; i < number[str[index] - '2'].size(); i++) {
            path.push_back(number[str[index] - '2'][i]);
            dfs(str, index + 1, path, result);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) {
            return result;
        }
        string path;
        dfs(digits, 0, path, result);
        return result;
    }
};

