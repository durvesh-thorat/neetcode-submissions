class Node {
public:
    int val, key;
    Node* prev;
    Node* next;

    Node(int key, int val) {
        prev = next = NULL;
        this->key = key;
        this->val = val;
    }
};
class LRUCache {
public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mp;
    int limit;

    void addNode(Node* newNode) {
        Node* oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->next = oldNext;
        newNode->prev = head;
    }

    void delNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!mp.contains(key))
            return -1;

        Node* ansNode = mp[key];
        int ans = ansNode->val;
        
        delNode(ansNode);

        addNode(ansNode);
        mp[key] = ansNode;

        return ans;
    }

    void put(int key, int value) {
        if (mp.contains(key)) {
            Node* old = mp[key];
            delNode(old);
            mp.erase(key);
        }

        if (mp.size() == limit) {
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */