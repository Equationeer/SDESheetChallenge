class Solution {
public:
    unordered_map<int, int> mp;
    int postIndex;

    TreeNode* solve(vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postIndex--]);

        int pos = mp[root->data];

        root->right = solve(postorder, pos + 1, inEnd);
        root->left = solve(postorder, inStart, pos - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        postIndex = postorder.size() - 1;

        return solve(postorder, 0, inorder.size() - 1);
    }
};