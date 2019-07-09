/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* result = head->next;
        ListNode* node = head;
        ListNode* pre = NULL;
        while(node != NULL && node->next != NULL) {
            ListNode* node2 = node->next;
            ListNode* t= node2->next;
            node2->next = node;
            node->next = t;
            if(pre == NULL) {
                pre = node;
            }
            else {
                pre->next = node2;
                pre = node;
            }
            node = t;
        }
        return result;
    }
};

