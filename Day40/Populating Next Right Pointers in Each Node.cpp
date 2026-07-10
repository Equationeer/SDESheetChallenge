class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return NULL;

        Node* leftMost = root;

        while (leftMost->left != NULL) {
            Node* curr = leftMost;

            while (curr != NULL) {
                curr->left->next = curr->right;

                if (curr->next != NULL)
                    curr->right->next = curr->next->left;

                curr = curr->next;
            }

            leftMost = leftMost->left;
        }

        return root;
    }
};