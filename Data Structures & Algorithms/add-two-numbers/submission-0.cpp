class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int firstDigit = (l1 != nullptr) ? l1->val : 0;
            int secondDigit = (l2 != nullptr) ? l2->val : 0;

            int sum = firstDigit + secondDigit + carry;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            carry = sum / 10;

            if (l1 != nullptr) {
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        return dummy.next;
    }
};