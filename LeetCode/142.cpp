class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast -> next != NULL && slow -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if (fast == slow) {
                ListNode* start = head;
                ListNode* end = fast;
                while (start != end) {
                    start = start -> next;
                    end = end -> next;
                }
                return start;
            }
        }
        return NULL;
    }
};
