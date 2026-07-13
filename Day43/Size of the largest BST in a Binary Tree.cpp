class NodeValue {
public:
    int minNode;
    int maxNode;
    int maxSize;

    NodeValue(int mn, int mx, int sz) {
        minNode = mn;
        maxNode = mx;
        maxSize = sz;
    }
};

class Solution {

    NodeValue solve(TreeNode* root) {

        if (root == NULL)
            return NodeValue(INT_MAX, INT_MIN, 0);

        NodeValue left = solve(root->left);
        NodeValue right = solve(root->right);

        if (left.maxNode < root->data &&
            root->data < right.minNode) {

            return NodeValue(
                min(root->data, left.minNode),
                max(root->data, right.maxNode),
                left.maxSize + right.maxSize + 1
            );
        }

        return NodeValue(
            INT_MIN,
            INT_MAX,
            max(left.maxSize, right.maxSize)
        );
    }

public:
    int largestBST(TreeNode* root) {
        return solve(root).maxSize;
    }
};