class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * p1 = l1;
        ListNode * p2 = l2;

        ListNode* head = new ListNode(0, nullptr);
        ListNode* p = head;
        int val = 0;

        while (p1 != nullptr && p2 != nullptr) {
            val += p1 -> val + p2 -> val;
            p -> next = new ListNode(val % 10, nullptr);
            val /= 10;
            p = p -> next;
            p1 = p1 -> next;
            p2 = p2 -> next;
        }

        while (p1 != nullptr) {
            val += p1 -> val;
            p -> next = new ListNode(val % 10, nullptr);
            val /= 10;
            p = p -> next;
            p1 = p1 -> next;
        }

        while (p2 != nullptr) {
            val += p2 -> val;
            p -> next = new ListNode(val % 10, nullptr);
            val /= 10;
            p = p -> next;
            p2 = p2 -> next;
        }

        if (val > 0) {
            p -> next = new ListNode(val, nullptr);
            p = p -> next;
        }

        return head -> next;
    }
};
