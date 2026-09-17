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
    ListNode* duck(ListNode* head, ListNode* node, int &k) {
        if(!node) return head;


        head = duck(head, node->next, k);

        if(k <= 0) {
            if(k < 0) return head;

            node->next = nullptr;
            k -= 1;
            return head;
        }

        node->next = head;
        k -= 1;
        return node;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        return duck(head, head, k);
    }
};