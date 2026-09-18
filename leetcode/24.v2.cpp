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
    ListNode* duck(ListNode* pair) {
        if(pair && pair->next) {
            ListNode* nxt = duck(pair->next->next);
            ListNode* tmp = pair->next;
            pair->next->next = pair;
            pair->next = nxt;
            return tmp;
        }else {
            return pair;
        }
    }

    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* ans = head->next;

        duck(head);

        return ans;
    }
};