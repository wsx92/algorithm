/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
        ListNode* result = NULL;
        ListNode* node = head;
        ListNode* pre = NULL;
        while(node != NULL) {
            if(node->next == NULL || node->next->val != node->val) {
                if(pre != NULL) {
                    pre->next = node;
                }
                pre = node;
                if(result == NULL) {
                    result = node;
                }
                node = node->next;
            }
            else {
                ListNode* t = node;
                while(t != NULL && t->val == node->val) {
                    t = t->next;
                }
                node = t;
                if(node == NULL) {
                    if(pre != NULL) {
                        pre->next = NULL;
                    }
                }
            }
        }
        return result;
    }
};

