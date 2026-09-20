struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int x, int y) {
        key = x;
        val = y;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    int size;
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> ump;

    LRUCache(int capacity) {
        size = 0;
        cap = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        if(ump.find(key) == ump.end()) {
            return -1;
        }

        Node* node = ump[key];

        if(node == head) {
            return head->val;
        }

        if(node == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        node->next = head;
        head->prev = node;
        head = node;
        head->prev = nullptr;

        return head->val;
    }
    
    void put(int key, int value) {
        if(ump.find(key) != ump.end()) {
            Node* node = ump[key];
            node->val = value;

            if(node == head) {
                return;
            }

            if(node == tail) {
                tail = node->prev;
                tail->next = nullptr;
                node->next = head;
                head->prev = node;
                head = node;
                head->prev = nullptr;
                return;
            }

            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next = head;
            head->prev = node;
            head = node;
            head->prev = nullptr;

            return;
        }

        if(size >= cap) {
            if(size == 1) {
                ump.erase(head->key);
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                Node* oldtail = tail;
                tail = tail->prev;
                tail->next = nullptr;
                ump.erase(oldtail->key);
                delete oldtail;
                oldtail = nullptr;
            }
            size--;
        }

        Node* node = new Node(key, value);
        ump[key] = node;
        

        if(size == 0) {
            head = node;
            tail = node;
            size++;
            return;
        }

        node->next = head;
        head->prev = node;
        head = node;
        head->prev = nullptr;
        size++;
    }
};