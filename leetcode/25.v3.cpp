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
    pair<ListNode*, ListNode*> duck(ListNode* node, int k, int kmax) {
        if(!node) return { nullptr, nullptr };

        if(k == 1) {
            auto [newHead, nextNewHead] = duck(node->next, kmax, kmax);
            return { node, nextNewHead };
        }

        auto [newHead, nextNewHead] = duck(node->next, k-1, kmax);
        if(!newHead) {
            if(k == kmax) {
                return { nullptr, node };
            } else {
                return { nullptr, nullptr };
            }
        }
        node->next->next = node;
        if(k == kmax) {
            node->next = nextNewHead;
            return { nullptr, newHead };
        }
        return { newHead, nextNewHead };
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        return duck(head, k, k).second;
    }
};