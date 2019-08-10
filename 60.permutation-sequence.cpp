/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */
class Solution {
public:

    void next(string& str) {
        int r = str.size() - 1;
        while(r > 0 && str[r - 1] > str[r]) {
            r--;
        }
        int l = r - 1;
        reverse(str.begin() + r, str.end());
        r = str.size() - 1;
        for(int i = r; i > l; i--) {
            if(str[i] > str[l] && str[i] < str[r]) {
                r = i;
            }
        }
        swap(str[l], str[r]);
    }

    string getPermutation(int n, int k) {
        string result;
        for(int i = 0; i < n; i++) {
            result.push_back('1' + i);
        }
        while(k > 1) {
            next(result);
            k--;
        }
        return result;
    }
};

