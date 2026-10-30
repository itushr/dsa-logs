class LFUCache {
    struct Node {
        int key, val, freq;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            freq = 1;
            prev = next = nullptr;
        }
    };

    struct DoublyList {
        Node* head;
        Node* tail;
        int size;

        DoublyList() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);

            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addFront(Node* node) {
            node->next = head->next;
            node->prev = head;

            head->next->prev = node;
            head->next = node;

            size++;
        }

        void remove(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->prev = nullptr;
            node->next = nullptr;

            size--;
        }

        Node* removeLRU() {
            if (size == 0) return nullptr;

            Node* node = tail->prev;
            remove(node);

            return node;
        }

        ~DoublyList() {
            delete head;
            delete tail;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node*> nodes;
    unordered_map<int, DoublyList*> freqLists;

    void increaseFreq(Node* node) {
        int oldFreq = node->freq;

        freqLists[oldFreq]->remove(node);

        if (freqLists[oldFreq]->size == 0) {
            if (minFreq == oldFreq)
                minFreq++;

            delete freqLists[oldFreq];
            freqLists.erase(oldFreq);
        }

        node->freq++;

        if (!freqLists.count(node->freq))
            freqLists[node->freq] = new DoublyList();

        freqLists[node->freq]->addFront(node);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (!nodes.count(key))
            return -1;

        Node* node = nodes[key];

        increaseFreq(node);

        return node->val;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (nodes.count(key)) {
            Node* node = nodes[key];

            node->val = value;
            increaseFreq(node);

            return;
        }

        if (nodes.size() == capacity) {
            Node* victim = freqLists[minFreq]->removeLRU();

            nodes.erase(victim->key);
            delete victim;

            if (freqLists[minFreq]->size == 0) {
                delete freqLists[minFreq];
                freqLists.erase(minFreq);
            }
        }

        Node* node = new Node(key, value);

        nodes[key] = node;

        if (!freqLists.count(1))
            freqLists[1] = new DoublyList();

        freqLists[1]->addFront(node);

        minFreq = 1;
    }

    ~LFUCache() {
        for (auto& [key, node] : nodes)
            delete node;

        for (auto& [freq, list] : freqLists)
            delete list;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */