class Node{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache = {};
    Node* left = new Node(0, 0);
    Node* right = new Node(0, 0);
    
    int cap;

public:
    LRUCache(int capacity) {
        cache.clear();
        cap = capacity;
        left->next = right;
        right->prev = left;
    }
    void insert(Node* cur){
        Node* prevright = right->prev;
        prevright->next = cur;
        cur->prev = prevright;
        cur->next = right;
        right->prev = cur;
    }
    void remove(Node* cur){
        Node* prevcur = cur->prev;
        Node* nextcur = cur->next;

        prevcur->next = nextcur;
        nextcur->prev = prevcur;
    }

    int get(int key) {
        if(cache.count(key)){
            Node* cur = cache[key];
            remove(cur);
            insert(cur);
            return cur->val;

        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            Node* cur = cache[key];
            remove(cur);
            cur->val = value;
            insert(cur);
        }
        else{
            Node* newNode = new Node(key, value);
            insert(newNode);
            cache[key] = newNode;
        }
        if (cache.size() > cap){
            Node* oldest = left->next;
            remove(oldest);
            cache.erase(oldest->key);
            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
