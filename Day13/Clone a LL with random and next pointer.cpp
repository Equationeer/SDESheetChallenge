class Solution {
public:
    ListNode* copyRandomList(ListNode* head) {
         if(head == NULL)
            return NULL;
        ListNode* curr = head;

        while(curr) {
            ListNode* copy = new ListNode(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }
        curr = head;

        while(curr) {

            if(curr->random)
                curr->next->random = curr->random->next;

            curr = curr->next->next;
        }

        curr = head;
        ListNode* copyHead = head->next;

        while(curr) {

            ListNode* copy = curr->next;

            curr->next = copy->next;

            if(copy->next)
                copy->next = copy->next->next;

            curr = curr->next;
        }

        return copyHead;
    }
};