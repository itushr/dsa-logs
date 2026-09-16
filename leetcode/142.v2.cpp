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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = new ListNode(0);
        ListNode* fast = new ListNode(0);

        slow->next = head;
        fast->next = head;

        while(slow != fast) {
            if(!fast || !fast->next) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = head;
        fast = fast->next;
        
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};