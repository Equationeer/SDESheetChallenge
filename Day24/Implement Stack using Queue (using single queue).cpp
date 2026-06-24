class QueueStack {
public:
    queue<int> q;

    QueueStack() {
    }
    
    void push(int x) {
        q.push(x);

        int sz = q.size();

        for(int i = 0; i < sz - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(q.empty()) return -1;

        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        if(q.empty()) return -1;

        return q.front();
    }
    
    bool isEmpty() {
        return q.empty();
    }
};