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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode();
        ListNode* anstail = ans;

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>>
            pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.push({lists[i]->val, lists[i]});
                lists[i] = lists[i]->next;
            }
        }

        while (!pq.empty()) {
            auto [top, topnode] = pq.top();

            for (int i = 0; i < lists.size(); i++) {
                while (lists[i] != nullptr && lists[i]->val <= top) {
                    pq.push({lists[i]->val, lists[i]});
                    lists[i] = lists[i]->next;
                }
            }

            pair tmp = pq.top();
            top = tmp.first;
            topnode = tmp.second;
            pq.pop();

            anstail->next = topnode;
            anstail = anstail->next;

            if (pq.empty()) {
                for (int i = 0; i < lists.size(); i++) {
                    if (lists[i] != nullptr) {
                        pq.push({lists[i]->val, lists[i]});
                        lists[i] = lists[i]->next;
                    }
                }
            }
        }

        anstail->next = nullptr;

        anstail = ans->next;
        delete ans;
        ans = anstail;
        return ans;
    }
};