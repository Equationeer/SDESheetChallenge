class Node {
public:
    int key, value, cnt;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        value = v;
        cnt = 1;
        prev = next = NULL;
    }
};

class List {
public:
    int size;
    Node *head, *tail;

    List() {
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
};

class LFUCache {
public:
    int cap, minFreq;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void updateFreq(Node *node) {
        int freq = node->cnt;
        freqList[freq]->removeNode(node);

        if (freq == minFreq && freqList[freq]->size == 0)
            minFreq++;

        node->cnt++;

        if (freqList.find(node->cnt) == freqList.end())
            freqList[node->cnt] = new List();

        freqList[node->cnt]->addFront(node);
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end())
            return -1;

        Node *node = keyNode[key];
        updateFreq(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cap == 0)
            return;

        if (keyNode.find(key) != keyNode.end()) {
            Node *node = keyNode[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        if (keyNode.size() == cap) {
            List *list = freqList[minFreq];
            Node *node = list->tail->prev;
            list->removeNode(node);
            keyNode.erase(node->key);
            delete node;
        }

        Node *newNode = new Node(key, value);
        minFreq = 1;

        if (freqList.find(1) == freqList.end())
            freqList[1] = new List();

        freqList[1]->addFront(newNode);
        keyNode[key] = newNode;
    }
};