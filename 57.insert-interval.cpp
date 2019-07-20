/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
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

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), compare);
        int i = 0;
        for(; i < intervals.size(); i++) {
            if(newInterval[0] <= intervals[i][0] && newInterval[1] >= intervals[i][1]) {
                continue;
            }
            if(newInterval[1] < intervals[i][0]) {
                break;
            }
            if(intervals[i][1] < newInterval[0]) {
                result.push_back(intervals[i]);
            }
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        result.push_back(newInterval);
        for(; i < intervals.size(); i++) {
            result.push_back(intervals[i]);
        }
        return result;
    }
};

