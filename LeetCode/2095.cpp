class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* p = new ListNode(0, head);
        ListNode* fast = p;
        ListNode* slow = p;

        while(fast -> next != nullptr && fast -> next -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        slow -> next = slow -> next -> next;

        return p -> next;
    }
};
