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
    void duck(ListNode* head, ListNode* &ordered, bool &brake) {
        if(!head || brake) return;

        duck(head->next, ordered, brake);

        if(ordered == head) {
            head->next = nullptr;
            brake = true;
            return;
        }

        ListNode* nxt = ordered->next;
        ordered->next = head;

        if(nxt == head) {
            head->next = nullptr;
            brake = true;
            return;
        }

        head->next = nxt;
        ordered = nxt;
    }

    void reorderList(ListNode* head) {
        ListNode* node = head;
        ListNode* ordered = head;
        bool brake = false;

        duck(node, ordered, brake);
    }
};

