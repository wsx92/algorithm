/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) {
            return head;
        }
        ListNode* l = head;
        ListNode* r = head;
        for(int i = 0; i < n; i++) {
            if(r == NULL) {
                return head;
            }
            r = r->next;
        }
        if(r == NULL) {
            return head->next;
        }
        while(r->next != NULL) {
            l = l->next;
            r = r->next;
        }
        l->next = l->next->next;
        return head;
    }
};

