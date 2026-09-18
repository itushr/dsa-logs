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
        ListNode* lhead = head;
        ListNode* prelhead = nullptr;

        while (lhead && lhead->val >= x) {
            prelhead = lhead;
            lhead = lhead->next;
        }

        ListNode* ltail = lhead;
        ListNode* rhead = head;

        if (!lhead)
            return head;
        if (prelhead) {
            prelhead->next = lhead->next;
            lhead->next = head;
            rhead = prelhead;
        } else {
            while (rhead && rhead->val < x) {
                rhead = rhead->next;
            }
            if (!rhead)
                return head;
            lhead->next = rhead;
        }


        while (rhead->next) {
            if (rhead->next->val >= x) {
                rhead = rhead->next;
                continue;
            }

            ListNode* tmp = ltail->next;
            ltail->next = rhead->next;
            ltail = ltail->next;
            ltail->next = tmp;
            rhead->next = rhead->next->next;
        }

        return lhead;
    }
};