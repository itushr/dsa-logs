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
    pair<int, int> duck(ListNode* node) {
        if(!node->next) return {node->val, 1};

        pair<int, int> tmp = duck(node->next);

        return {node->val*pow(2, tmp.second)+tmp.first, tmp.second+1};
    }

    int getDecimalValue(ListNode* head) {
        if(!head) return 0;

        return duck(head).first;
    }
};