class Solution {
public:
    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* solve(vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preIndex++]);

        int pos = mp[root->data];

        root->left = solve(preorder, inStart, pos - 1);
        root->right = solve(preorder, pos + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return solve(preorder, 0, inorder.size() - 1);
    }
};