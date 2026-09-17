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
    ListNode* duck(ListNode* node, ListNode* ordered) {
        if(!node) return ordered;

        ordered = duck(node->next, ordered);

        if(!ordered) return nullptr;

        if(ordered == node) {
            node->next = nullptr;
            return nullptr;
        }
        
        ListNode* tmp = ordered->next;
        ordered->next = node;

        if(tmp == node) {
            node->next = nullptr;
            return nullptr;
        }

        node->next = tmp;

        return tmp;
    }

    void reorderList(ListNode* head) {
        duck(head, head);
    }
};