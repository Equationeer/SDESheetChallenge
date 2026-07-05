class Solution {
public:
    vector<vector<int> > verticalTraversal(TreeNode* root) {
    	//your code goes here
        vector<vector<int>> ans;

        if(root == NULL)
            return ans;
        map<int, map<int, multiset<int>>> mp;

        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0, 0}});

        while(!q.empty()){

            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int vertical = it.second.first;
            int level = it.second.second;

            mp[vertical][level].insert(node->data);

            if(node->left)
                q.push({node->left, {vertical - 1, level + 1}});

            if(node->right)
                q.push({node->right, {vertical + 1, level + 1}});
        }

        for(auto &v : mp){

            vector<int> col;

            for(auto &lvl : v.second){

                for(auto val : lvl.second)
                    col.push_back(val);
            }

            ans.push_back(col);
        }

        return ans;
    }
};