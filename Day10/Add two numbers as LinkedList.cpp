class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* &linkedList1, ListNode* &linkedList2) {
            //your code goes here
            
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int carry = 0;

        while (linkedList1 || linkedList2 || carry) {

            int sum = carry;

            if (linkedList1) {
                sum += linkedList1->data;
                linkedList1 = linkedList1->next;
            }

            if (linkedList2) {
                sum += linkedList2->data;
                linkedList2 = linkedList2->next;
            }

            carry = sum / 10;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy->next;
        }
};