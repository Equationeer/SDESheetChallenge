class ArrayQueue {
public:
    vector<int> q;
    int frontIdx;

    ArrayQueue() {
        frontIdx = 0;
    }
    
    void push(int x) {
        q.push_back(x);
    }
    
    int pop() {
        if (isEmpty()) return -1;

        return q[frontIdx++];
    }
    
    int peek() {
        if (isEmpty()) return -1;

        return q[frontIdx];
    }
    
    bool isEmpty() {
        return frontIdx >= q.size();
    }
};