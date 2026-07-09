class Solution {
public:
    bool checkChildrenSum(TreeNode* root) {
        if (root == NULL)
            return true;

        // Leaf node
        if (root->left == NULL && root->right == NULL)
            return true;

        int leftSum = 0, rightSum = 0;

        if (root->left)
            leftSum = root->left->val;

        if (root->right)
            rightSum = root->right->val;

        return (root->val == leftSum + rightSum) &&
               checkChildrenSum(root->left) &&
               checkChildrenSum(root->right);
    }
};
