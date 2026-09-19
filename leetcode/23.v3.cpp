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

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.push({ lists[i]->val, i });
            }
        }

        while (!pq.empty()) {
            auto [val, i] = pq.top();
            pq.pop();

            anstail->next = lists[i];
            anstail = anstail->next;
            lists[i] = lists[i]->next;
            if(lists[i] != nullptr) {
                pq.push({ lists[i]->val, i });
            }
        }

        anstail->next = nullptr;

        anstail = ans->next;
        delete ans;
        ans = anstail;
        return ans;
    }
};