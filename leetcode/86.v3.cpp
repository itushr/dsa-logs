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
    ListNode* partition(ListNode* head, int x) {
        ListNode* chain1 = nullptr;
        ListNode* chain2 = nullptr;

        ListNode* head1 = nullptr;
        ListNode* head2 = nullptr;

        while(head) {
            if(head->val < x) {
                if(chain1) {
                    chain1->next = head;
                    chain1 = chain1->next;
                }else {
                    chain1 = head;
                    head1 = head;
                }
            }else {
                if(chain2) {
                    chain2->next = head;
                    chain2 = chain2->next;
                }else {
                    chain2 = head;
                    head2 = head;
                }
            }

            head = head->next;
        }

        if(!head1) return head2;
        if(!head2) return head1;

        chain1->next = head2;
        chain2->next = nullptr;

        return head1;
    }
};