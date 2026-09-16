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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val) {
            head = head->next;
        }

        if(!head) return head;

        ListNode* node = head;
        
        while(node) {
            ListNode* tmp = node->next;
            
            while(tmp && tmp->val == val) {
                tmp = tmp->next;
            }

            node->next = tmp;
            node = tmp;
        }

        return head;
    }
};