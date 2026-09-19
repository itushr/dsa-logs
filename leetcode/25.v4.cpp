/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;

        while(curr) {
            n++;
            curr = curr->next;
        }

        if(n < 2 || k < 2) return head;

        curr = head;

        int ngrp = n/k;

        if(n%k) {
            ngrp++;
        }

        ListNode* ans = nullptr;
        ListNode* prev = nullptr;
        ListNode* currhead = nullptr;
        ListNode* prevhead = nullptr;

        for(int i=0; i<ngrp; i++) {
            if(i == n/k) {
                prevhead->next = curr;
                break;
            }

            currhead = curr;
            prev = curr;
            curr = curr->next;


            for(int j=0; j<k-2; j++) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            if(!prevhead) {
                ans = curr;
            } else {
                prevhead->next = curr;
            }
            prevhead = currhead;
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        return ans;
    }
};