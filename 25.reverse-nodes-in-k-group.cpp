/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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

    ListNode* reverse(ListNode* head) {
        ListNode* result = NULL;
        ListNode* node = head;
        while(node != NULL) {
            ListNode* t = node;
            node = node->next;
            t->next = result;
            result = t;
        }
        return result;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head ->next == NULL || k <= 1) {
            return head;
        }
        ListNode* result = head;
        for(int i = 0; i < k - 1; i++) {
            if(result->next == NULL) {
                return head;
            }
            result = result->next;
        }
        ListNode* node = head;
        ListNode* pre = NULL;
        while(true) {
            if(node == NULL) {
                break;
            }
            ListNode* t = node;
            for(int i = 0; i < k - 1; i++) {
                if(node->next == NULL) {
                    if(pre != NULL) {
                        pre->next = t;
                        return result;
                    }
                }
                node = node->next;
            }
            ListNode* tail = node;
            node = node->next;
            tail->next = NULL;
            reverse(t);
            if(pre != NULL) {
                pre->next = tail;
            }
            pre = t;
        }
        return result;
    }
};

