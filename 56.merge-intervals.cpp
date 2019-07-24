/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
class Solution {
public:

    static bool compare(const vector<int>& l,const vector<int>& r) {
        int index = 0;
        while(index < l.size() && index < r.size()) {
            if(l[index] < r[index]) {
                return true;
            }
            else if(l[index] > r[index]) {
                return false;
            }
            index++;
        }
        return l.size() < r.size();
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.empty()) {
            return result;
        }
        sort(intervals.begin(), intervals.end(), compare);
        vector<int> cur = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            if(cur[0] <= intervals[i][0] && cur[1] >= intervals[i][1]) {
                continue;
            }
            if(cur[1] < intervals[i][0]) {
                result.push_back(cur);
                cur = intervals[i];
            }
            else {
                cur[1] = intervals[i][1];
            }
        }
        result.push_back(cur);
        return result;
    }
};

