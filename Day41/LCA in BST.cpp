class Solution{	
	public:
		TreeNode* lca(TreeNode* root, int p, int q){
	        //your code goes here
             if (root == nullptr)
            return nullptr;

        if (p < root->data && q < root->data)
            return lca(root->left, p, q);

        if (p > root->data && q > root->data)
            return lca(root->right, p, q);

        return root;
		}
};