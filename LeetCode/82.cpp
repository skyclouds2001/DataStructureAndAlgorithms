class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* p = new ListNode(0, head);
        ListNode* pp = p;

        while (p -> next != nullptr && p -> next -> next != nullptr) {
            if (p -> next -> val == p -> next -> next -> val) {
                int t = p -> next -> val;

                while (p -> next != nullptr && p -> next -> val == t) {
                    p -> next = p -> next -> next;
                }
            } else {
                p = p -> next;
            }
        }

        return pp -> next;
    }
};
