/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */
class Solution {
public:

    string plus(string n1, string n2) {
        if(n1.empty()) {
            return n2;
        }
        if(n2.empty()) {
            return n1;
        }
        string result;
        reverse(n1.begin(), n1.end());
        reverse(n2.begin(), n2.end());
        int i = 0;
        int t = 0;
        while(i < n1.size() && i < n2.size()) {
            int n = (n1[i] - '0') + (n2[i] - '0') + t;
            result.push_back(n % 10 + '0');
            t = n / 10;
            i++;
        }
        while(i < n1.size()) {
            int n = (n1[i] - '0') + t;
            result.push_back(n % 10 + '0');
            t = n / 10;
            i++;
        }
        while(i < n2.size()) {
            int n = (n2[i] - '0') + t;
            result.push_back(n % 10 + '0');
            t = n / 10;
            i++;
        }
        while(t) {
            result.push_back(t % 10 + '0');
            t /= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    string multi(string str, char c) {
        if(c == '0') {
            return "0";
        }
        string result;
        int t = 0;
        for(int i = str.size() - 1; i >= 0; i--) {
            int n1 = str[i] - '0';
            int n2 = c - '0';
            int n = n1 * n2 + t;
            result.push_back(n % 10 + '0');
            t = n / 10;
        }
        while(t) {
            result.push_back(t % 10 + '0');
            t /= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    string multiply(string num1, string num2) {
        string result;
        for(int i = num2.size() - 1; i >= 0; i--) {
            string str = multi(num1, num2[i]);
            if(str != "0") {
                for(int j = num2.size() - 1; j > i; j--) {
                    str.push_back('0');
                }
            }
            result = plus(result, str);
        }
        return result;
    }
};

