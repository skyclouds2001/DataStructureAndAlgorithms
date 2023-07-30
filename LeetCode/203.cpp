class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head -> val == val) {
            ListNode* t = head;
            head = head -> next;
            delete t;
        }

        ListNode* p = head;
        while (p != NULL && p -> next != NULL) {
            if (p -> next -> val == val) {
                ListNode* t = p -> next;
                p -> next = p -> next -> next;
                delete t;
            } else {
                p = p -> next;
            }
        }

        return head;
    }
};
