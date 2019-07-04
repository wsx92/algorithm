/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) {
            return l2;
        }
        if(l2 == NULL) {
             return l1;
        }
        ListNode* result = NULL;
        ListNode* node = NULL;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                ListNode* t = l1->next;
                l1->next = NULL;
                if(result == NULL) {
                    result = l1;
                }
                if(node == NULL) {
                    node = l1;
                }
                else {
                    node->next = l1;
                }
                node = l1;
                l1 = t;
            }
            else {
                ListNode* t = l2->next;
                l2->next = NULL;
                if(result == NULL) {
                    result = l2;
                }
                if(node == NULL) {
                    node = l2;
                }
                else {
                    node->next = l2;
                }
                node = l2;
                l2 = t;
            }
        }
        if(l1 != NULL) {
            node->next = l1;
        }
        if(l2 != NULL) {
            node->next = l2;
        }
        return result;
    }
};

