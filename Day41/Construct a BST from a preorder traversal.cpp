class Solution {
public:
    TreeNode* build(vector<int>& preorder, int &idx, int bound) {
        if (idx == preorder.size() || preorder[idx] > bound)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[idx++]);

        root->left = build(preorder, idx, root->data);
        root->right = build(preorder, idx, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return build(preorder, idx, INT_MAX);
    }
};