/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = NULL;
        ListNode* node = NULL;
        while(true) {
            ListNode* t = NULL;
            int index = -1;
            for(int i = 0; i < lists.size(); i++) {
                if(lists[i] != NULL) {
                    if(t == NULL) {
                        t = lists[i];
                        index = i;
                    }
                    else if(lists[i]->val < t->val) {
                        t = lists[i];
                        index = i;
                    }
                }
            }
            if(t != NULL) {
                lists[index] = lists[index]->next;
                if(result == NULL) {
                    result = t;
                }
                if(node == NULL) {
                    node = t;
                }
                else {
                    node->next = t;
                    node = t;
                }
            }
            else {
                break;
            }
        }
        return result;
    }
};

