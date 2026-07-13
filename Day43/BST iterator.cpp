class BSTIterator {
    stack<TreeNode*> st;

    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (node->right)
            pushAll(node->right);

        return node->data;
    }
};