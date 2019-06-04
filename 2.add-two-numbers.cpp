/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        ListNode* result = NULL;
        int t = 0;
        while(node1 != NULL && node2 != NULL) {
            ListNode* node = new ListNode((node1->val + node2->val + t) % 10);
            t = (node1->val + node2->val + t) / 10;
            node->next = result;
            result = node;
            node1 = node1->next;
            node2 = node2->next;
        }
        while(node1 != NULL) {
            ListNode* node = new ListNode((node1->val + t) % 10);
            t = (node1->val + t) / 10;
            node->next = result;
            result = node;
            node1 = node1->next;
        }
        while(node2 != NULL) {
            ListNode* node = new ListNode((node2->val + t) % 10);
            t = (node2->val + t) / 10;
            node->next = result;
            result = node;
            node2 = node2->next;
        }
        if(t) {
            ListNode* node = new ListNode(t);
            node->next = result;
            result = node;
        }
        ListNode* head = NULL;
        ListNode* n = result;
        while(n != NULL) {
            ListNode* t = n->next;
            n->next = head;
            head = n;
            n = t;
        }
        return head;
    }
};

