class Solution {
public:
    unordered_set<int> st;

    bool dfs(TreeNode* root, int k) {
        if (!root) return false;

        if (st.count(k - root->data))
            return true;

        st.insert(root->data);

        return dfs(root->left, k) || dfs(root->right, k);
    }

    bool twoSumBST(TreeNode* root, int k) {
        return dfs(root, k);
    }
};