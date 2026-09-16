//Copyright (c) 2026 Tushar Ramgirkar

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* start = head;
        ListNode* prestart = nullptr;

        for(int i=1; i<left; i++) {
            prestart = start;    
            start = start->next;
        }

        ListNode* node = start;
        ListNode* prev = nullptr;

        while(right >= left) {
            ListNode* tmp = node->next;
            node->next = prev;
            prev = node;
            node = tmp;
            right--;
        }

        start->next = node;

        if(left == 1){
            return prev;
        }else {
            prestart->next = prev;
            return head;
        }
    }
};