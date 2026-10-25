/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* oldHead = head;
        Node* newHead = new Node(head->val);

        unordered_map<Node*, Node*> rmap;
        rmap[head] = newHead;

        Node* newNode = newHead;
        head = head->next;


        while(head) {
            Node* tmp = new Node(head->val);
            newNode->next = tmp;
            newNode = tmp;
            rmap[head] = tmp;
            head = head->next;
        }

        Node* node = newHead;

        while(oldHead) {
            node->random = rmap[oldHead->random];
            oldHead = oldHead->next;
            node = node->next;
        }

        return newHead;
    }
};