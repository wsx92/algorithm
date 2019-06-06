/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
class Solution {
public:
    double findMedian(vector<int>& v1, int l1, int r1, vector<int>& v2, int l2, int r2) {
        int l = 0;
        int r = 0;
        while(l1 <= r1 && l2 <= r2) {
            if(v1[l1] < v2[l2]) {
                l = v1[l1++];
            }
            else {
                l = v2[l2++];
            }
            if(v1[r1] < v2[r2]) {
                r = v2[r2--];
            }
            else {
                r = v1[r1--];
            }
        }
        if(l1 > r1 && l2 > r2) {
            return (l + r) / 2;
        }
        else if(l1 > r1) {
            return (v2[(r2 - l2) / 2] + v2[((r2 - l2) + 1) / 2]) / 2;
        }
        else {
            return (v1[(r1 - l1) / 2] + v1[((r1 - l1) + 1) / 2]) / 2;
        }
    }

    double merge(vector<int>& v1, vector<int>& v2) {
        int l = 0;
        int r = 0;
        int l1 = 0;
        int l2 = 0;
        int r1 = v1.size() - 1;
        int r2 = v2.size() - 1;
        while(l1 <= r1 && l2 <= r2) {
            if(v1[l1] < v2[l2]) {
                l = v1[l1++];
            }
            else {
                l = v2[l2++];
            }
            if(v1[r1] < v2[r2]) {
                r = v2[r2--];
            }
            else {
                r = v1[r1--];
            }
        }
        if(l1 > r1 && l2 > r2) {
            return (double)(l + r) / 2;
        }
        else if(l1 > r1) {
            return (double)(v2[l2 + (r2 - l2) / 2] + v2[l2 + ((r2 - l2) + 1) / 2]) / 2;
        }
        else {
            return (double)(v1[l1 + (r1 - l1) / 2] + v1[l1 + ((r1 - l1) + 1) / 2]) / 2;
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return merge(nums1, nums2);
    }
};

