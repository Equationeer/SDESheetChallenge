class StackQueue {
public:
    stack<int> s1, s2;

    StackQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }

    void transfer() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    int pop() {
        if (s2.empty()) {
            transfer();
        }

        if (s2.empty()) return -1;

        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        if (s2.empty()) {
            transfer();
        }

        if (s2.empty()) return -1;

        return s2.top();
    }
    
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};