class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* pos = new ListNode(0);
        pos -> next = head;

        ListNode* fast = head;
        ListNode* slow = head;

        for (int i = 0; i < k; ++i) {
            fast = fast -> next;
        }

        while (fast != nullptr) {
            fast = fast -> next;
            slow = slow -> next;
        }

        return slow;
    }
};