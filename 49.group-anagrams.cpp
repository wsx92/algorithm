/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
class Solution {
public:

    bool equals(string& str1, string& str2) {
        if(str1.size() != str2.size()) {
            return false;
        }
        vector<int> hash1(26);
        for(int i = 0; i < str1.size(); i++) {
            if(str1[i] < 'a' || str1[i] > 'z') {
                return false;
            }
            hash1[str1[i] - 'a']++;
        }
        vector<int> hash2(26);
        for(int i = 0; i < str2.size(); i++) {
            if(str2[i] < 'a' || str2[i] > 'z') {
                return false;
            }
            hash2[str2[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(hash1[i] != hash2[i]) {
                return false;
            }
        }
        return true;
    }

    int hash(string& str) {
        int hash = 0;
        for(int i = 0; i < str.size(); i++) {
            hash += str[i] - 'a';
        }
        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<int, vector<string>> map;
        for(int i = 0; i < strs.size(); i++) {
            map[hash(strs[i])].push_back(strs[i]);
        }
        for(auto it = map.begin(); it != map.end(); it++) {
            vector<string> s = it->second;
            vector<vector<string>> part;
            for(int i = 0; i < s.size(); i++) {
                int index = -1;
                for(int j = 0; j < part.size(); j++) {
                    if(hash(part[j][0]) == hash(s[i]) && equals(part[j][0], s[i])) {
                        index = j;
                    }
                }
                if(index >=0 && index < part.size()) {
                    part[index].push_back(s[i]);
                }
                else {
                    part.push_back(vector<string>(1, s[i]));
                }
            }
            for(int i = 0; i < part.size(); i++) {
                result.push_back(part[i]);
            }
        }
        return result;
    }
};

