class Solution {	
public:	
    TreeNode* searchBST(TreeNode* root, int val) {
    	//your code goes here
        while (root != nullptr) {
            if (root->data == val)
                return root;

            if (val < root->data)
                root = root->left;
            else
                root = root->right;
        }

        return nullptr;
    }
};