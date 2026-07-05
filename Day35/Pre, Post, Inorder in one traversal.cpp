class Solution{
	public:
		vector<vector<int>> treeTraversal(TreeNode* root){
			//your code goes here
             vector<int> pre, in, post;

        if(root == NULL)
            return {in, pre, post};

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        while(!st.empty()){

            auto it = st.top();
            st.pop();

            TreeNode* node = it.first;
            int state = it.second;

            if(state == 1){
                pre.push_back(node->data);

                st.push({node, 2});

                if(node->left)
                    st.push({node->left, 1});
            }
            else if(state == 2){
                in.push_back(node->data);

                st.push({node, 3});

                if(node->right)
                    st.push({node->right, 1});
            }
            else{
                post.push_back(node->data);
            }
        }

        return {in, pre, post};
		}
};