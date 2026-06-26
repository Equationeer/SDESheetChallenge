class Node {
public:
    int key, value;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = NULL;
    }
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node *node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key_) {
        if (mp.find(key_) == mp.end())
            return -1;

        Node *node = mp[key_];

        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key_, int value) {
        if (mp.find(key_) != mp.end()) {
            Node *node = mp[key_];
            node->value = value;

            remove(node);
            insert(node);
            return;
        }

        if (mp.size() == cap) {
            Node *lru = tail->prev;

            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node *newNode = new Node(key_, value);

        insert(newNode);
        mp[key_] = newNode;
    }
};