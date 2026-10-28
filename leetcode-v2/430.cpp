/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* duck(Node* node) {
        if(!node->next) {
            if(!node->child) return node;
            Node* childtail = duck(node->child);
            node->next = node->child; node->child->prev = node;
            node->child = nullptr;
            return childtail;
        }

        if(!node->child) return duck(node->next);
        
        Node* childtail = duck(node->child);
        childtail->next = node->next; node->next->prev = childtail;
        node->next = node->child; node->child->prev = node;        
        node->child = nullptr;
        return duck(childtail->next);
    }

    Node* flatten(Node* head) {
        if(!head) return nullptr;

        duck(head);
        return head;
    }
};