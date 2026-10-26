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
    pair<ListNode*, ListNode*> rev(ListNode* grphead, ListNode* node, int k, int i) {
        if(!node) return {nullptr, grphead};

        if(i == k) {
            grphead->next = rev(node->next, node->next, k, 1).second;
            return {node, node};
        }

        auto [nextNode, newHead] = rev(grphead, node->next, k, i+1);
        if(!nextNode) return {nullptr, grphead};
        nextNode->next = node;
        return {node, newHead};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        return rev(head, head, k, 1).second;
    }
};