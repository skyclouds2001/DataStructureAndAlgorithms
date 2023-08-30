class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head, * q = nullptr;
        while (p != nullptr) {
            ListNode* t = p;
            p = p -> next;
            t -> next = q;
            q = t;
        }
        return q;
    }
};
