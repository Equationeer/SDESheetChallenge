class Solution {
public:

    void inorder(TreeNode* root, int &cnt, int k, int &small) {
        if (!root || small != -1) return;

        inorder(root->left, cnt, k, small);

        cnt++;
        if (cnt == k) {
            small = root->data;
            return;
        }

        inorder(root->right, cnt, k, small);
    }

    void reverseInorder(TreeNode* root, int &cnt, int k, int &large) {
        if (!root || large != -1) return;

        reverseInorder(root->right, cnt, k, large);

        cnt++;
        if (cnt == k) {
            large = root->data;
            return;
        }

        reverseInorder(root->left, cnt, k, large);
    }

    vector<int> kLargesSmall(TreeNode* root, int k) {

        int small = -1;
        int large = -1;

        int cnt = 0;
        inorder(root, cnt, k, small);

        cnt = 0;
        reverseInorder(root, cnt, k, large);

        return {small, large};
    }
};