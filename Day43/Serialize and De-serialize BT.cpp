class Solution {
public:

    string serialize(TreeNode* root) {

        if (root == NULL)
            return "";

        queue<TreeNode*> q;
        q.push(root);

        string ans = "";

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                ans += "N ";
                continue;
            }

            ans += to_string(node->data) + " ";

            q.push(node->left);
            q.push(node->right);
        }

        return ans;
    }

    TreeNode* deserialize(string data) {

        if (data.size() == 0)
            return NULL;

        stringstream ss(data);

        string str;

        ss >> str;

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            ss >> str;

            if (str != "N") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            ss >> str;

            if (str != "N") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};