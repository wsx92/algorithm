/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* node = head->next;
        ListNode* pre = head;
        while(node != NULL) {
            if(node->val == pre->val) {
                pre->next = node->next;
            }
            else {
                pre = node;
            }
            node = node->next;
        }
        return head;
    }
};

