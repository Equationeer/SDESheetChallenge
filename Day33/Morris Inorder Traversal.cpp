class Solution {
public:
    vector<int> getInorder(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->data);
                curr = curr->right;
            } 
            else {
                TreeNode* prev = curr->left;

                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }
                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                }
                else {
                    prev->right = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};