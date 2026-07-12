class Solution{	
	public:
		vector<int> floorCeilOfBST(TreeNode* root,int key){
			//your code goes here
             int floor = -1;
        int ceil = -1;
        TreeNode* curr = root;
        while (curr) {
            if (curr->data == key) {
                floor = curr->data;
                break;
            }

            if (curr->data < key) {
                floor = curr->data;
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        curr = root;
        while (curr) {
            if (curr->data == key) {
                ceil = curr->data;
                break;
            }

            if (curr->data > key) {
                ceil = curr->data;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        return {floor, ceil};
		}
};