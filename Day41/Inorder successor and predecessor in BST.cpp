class Solution {
public:
    vector<int> succPredBST(TreeNode* root, int key) {
        int pred = -1, succ = -1;
        TreeNode* curr = root;
        while (curr) {
            if (key > curr->data) {
                pred = curr->data;
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        curr = root;

        while (curr) {
            if (key < curr->data) {
                succ = curr->data;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        return {pred, succ};
    }
};