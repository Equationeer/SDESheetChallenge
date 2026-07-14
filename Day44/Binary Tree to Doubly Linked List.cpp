class Solution {
public:
    TreeNode* prev;
    TreeNode* head;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev == NULL) {
            head = root;
        } else {
            prev->right = root;
            root->left = prev;
        }

        prev = root;

        inorder(root->right);
    }

    TreeNode* bToDLL(TreeNode* root) {
        prev = NULL;   
        head = NULL;   

        inorder(root);

        return head;
    }
};