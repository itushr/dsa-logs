struct Node {
    int val;
    Node* next;
    Node* prev;

    Node(int val = 0) : val(val), next(nullptr), prev(nullptr) {}
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;

        size = 0;
    }

    Node* getNode(int index) {
        if (index < 0 || index >= size) return nullptr;

        Node* node;

        if (index < size / 2) {
            node = head->next;
            for (int i = 0; i < index; i++)
                node = node->next;
        } else {
            node = tail->prev;
            for (int i = size - 1; i > index; i--)
                node = node->prev;
        }

        return node;
    }

    int get(int index) {
        Node* node = getNode(index);
        return node ? node->val : -1;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0) index = 0;
        if (index > size) return;

        Node* nextNode;

        if (index == size) {
            nextNode = tail;
        } else {
            nextNode = getNode(index);
        }

        Node* prevNode = nextNode->prev;
        Node* newNode = new Node(val);

        newNode->next = nextNode;
        newNode->prev = prevNode;

        prevNode->next = newNode;
        nextNode->prev = newNode;

        size++;
    }

    void deleteAtIndex(int index) {
        Node* node = getNode(index);
        if (!node) return;

        node->prev->next = node->next;
        node->next->prev = node->prev;

        delete node;
        size--;
    }

    ~MyLinkedList() {
        Node* node = head;

        while (node) {
            Node* nextNode = node->next;
            delete node;
            node = nextNode;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */