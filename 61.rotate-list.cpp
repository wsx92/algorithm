/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k <= 0) {
            return head;
        }
        ListNode* node = head;
        ListNode* tail = head;
        int length = 0;
        while(node != NULL) {
            length++;
            tail = node;
            node = node->next;
        }
        k %= length;
        if(k == 0) {
            return head;
        }
        node = head;
        ListNode* node1 = head;
        while(k >= 0) {
            node = node->next;
            k--;
        }
        while(node1 != NULL && node != NULL) {
            node1 = node1->next;
            node = node->next;
        }
        ListNode* result = node1->next;
        node1->next = NULL;
        tail->next = head;
        return result;
    }
};

