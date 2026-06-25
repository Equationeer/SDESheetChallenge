class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for (char ch : str) {

            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                if (st.empty()) return false;

                if ((ch == ')' && st.top() == '(') ||
                    (ch == '}' && st.top() == '{') ||
                    (ch == ']' && st.top() == '[')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};