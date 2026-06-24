class ArrayStack {
public:
    vector<int> st;

    ArrayStack() {
    }
    
    void push(int x) {
        st.push_back(x);
    }
    
    int pop() {
        if(st.empty()) return -1;

        int val = st.back();
        st.pop_back();
        return val;
    }
    
    int top() {
        if(st.empty()) return -1;

        return st.back();
    }
    
    bool isEmpty() {
        return st.empty();
    }
};