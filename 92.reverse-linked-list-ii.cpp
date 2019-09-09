/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        if(m == n) {
            return head;
        }
        ListNode* r = head;
        for(int i = 0; i <= n - m; i++) {
            r = r->next;
        }
        ListNode* l = head;
        ListNode* pre = NULL;
        for(int i = 1; i < m; i++) {
            pre = l;
            l = l->next;
            r = r->next;
        }
        ListNode* next = r;
        ListNode* newhead = NULL;
        ListNode* newtail = l;
        while(l != r) {
            ListNode* t = l;
            l = l->next;
            t->next = newhead;
            newhead = t;
        }
        newtail->next = next;
        if(pre == NULL) {
            return newhead;
        }
        pre->next = newhead;
        return head;
    }
};

