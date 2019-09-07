/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* i = NULL;
        ListNode* pre = NULL;
        ListNode* node = head;
        while(node != NULL) {
            if(node->val < x) {
                if(i == NULL) {
                    if(node == head) {
                        i = head;
                        pre = node;
                        node = node->next;
                    }
                    else {
                        ListNode* n = node->next;
                        node->next = head;
                        pre->next = n;
                        head = node;
                        i = node;
                        node = n;
                    }
                }
                else {
                    if(i->next == node) {
                        i = node;
                        pre = node;
                        node = node->next;
                    }
                    else {
                        ListNode* n = node->next;
                        ListNode* t = i->next;
                        i->next = node;
                        i = i->next;
                        node->next = t;
                        pre->next = n;
                        node = n;
                    }
                }
            }
            else {
                pre = node;
                node = node->next;
            }
        } 
        return head;
    }
};

