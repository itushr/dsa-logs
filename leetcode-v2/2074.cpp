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
    pair<ListNode*, ListNode*> rev(ListNode* node, ListNode* grphead, int n, int nmax) {
        if(!node) return {nullptr, grphead};

        if(n < nmax) {
            if(!node->next) {
                if(n%2 == 0) {
                    grphead->next = node->next;
                    return {node, node};
                } else {
                    return {nullptr, grphead};
                }
            }

            auto [nextNode, newHead] = rev(node->next,grphead, n+1, nmax);
            if(!nextNode) return {nullptr, grphead};
            nextNode->next = node;
            return {node, newHead};
        }

        if(n%2 == 0) {
            grphead->next = rev(node->next, node->next, 1, nmax+1).second;
            return {node, node};
        }

        node->next = rev(node->next, node->next, 1, nmax+1).second;
        return {nullptr, grphead};
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        rev(head, head, 1, 1);
        return head;
    }
};