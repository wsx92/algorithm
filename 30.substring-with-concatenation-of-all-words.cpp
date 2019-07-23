/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */
class Solution {
public:

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(words.empty()) {
            return result;
        }
        int l = 0;
        int len = words[0].size();
        if(s.size() < words.size() * len) {
            return result;
        }
        unordered_map<string, int> count;
        for(int i = 0; i < words.size(); i++) {
            count[words[i]]++;
        }
        while(l < s.size()) {
            unordered_map<string, int> pos;
            int r = l;
            while(r < s.size()) {
                string str = s.substr(r, len);
                if(count.find(str) == count.end()) {
                    break;
                }
                pos[str]++;
                if(pos[str] > count[str]) {
                    break;
                }
                r += len;
            }
            if(r == l + words.size() * len) {
                result.push_back(l);
            }
            l += 1;
        }
        return result;
    }
};

