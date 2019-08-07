/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */
class Solution {
public:
    string countAndSay(int n) {
        if(n < 1) {
            return "";
        }
        string result = "1";
        while(n > 1) {
            string str;
            char last = result[0];
            int count = 1;
            for(int i = 1; i < result.size(); i++) {
                if(last == result[i]) {
                    count ++;
                }
                else {
                    str.push_back(count + '0');
                    str.push_back(last);
                    last = result[i];
                    count = 1;
                }
            }
            str.push_back(count + '0');
            str.push_back(last);
            result = str;
            n --;
        }
        return result;
    }
};

