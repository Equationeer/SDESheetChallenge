class Solution {
public:
    void deleteNode(ListNode* node) {
        // Your code goes here
         node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = temp->next;
        delete temp;
    }
};