struct CacheNode {
    int key;
    int val;
    CacheNode* prev;
    CacheNode* next;

    CacheNode(int key, int val) {
        this->key = key;
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    int size;
    CacheNode* head; // most recently used;
    CacheNode* tail; // least recently used;
    unordered_map<int, CacheNode*> cacheMap;

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    int get(int key) {
        if(cacheMap.find(key) != cacheMap.end()) {
            CacheNode* cache = cacheMap[key];
            
            if(cache == this->head) {
                return cache->val;
            }

            if(cache == this->tail) {
                this->tail = cache->prev;
            }

            cache->prev->next = cache->next;
            cache->next = this->head;
            this->head->prev = cache;
            this->head = cache;
            return cache->val;
        }else {
            return -1;
        }
    }

    void put(int key, int value) {
        if(cacheMap.find(key) != cacheMap.end()) {
            cacheMap[key]->val = value;
            return;
        }

        CacheNode* cache = new CacheNode(key, value);
        cacheMap[key] = cache;

        if (this->size + 1 > this->capacity) {
            CacheNode* newTail = this->tail->prev;
            cacheMap.erase(this->tail->key);
            delete this->tail;
            this->tail = newTail;
            this->size = this->size-1;
            if(this->size == 0) {
                this->head = nullptr;
            }
        }

        if (this->size == 0) {
            this->size = 1;
            this->head = cache;
            this->tail = cache;
            return;
        }

        this->size = this->size+1;
        cache->next = this->head;
        this->head->prev = cache;
        this->head = cache;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */