class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* min = new ListNode(), *ik = min;
        ListNode* max = new ListNode(), *mk = max;

        ListNode* p = head;
        while (p != nullptr) {
            if (p -> val < x) {
                ik -> next = p;
                ik = p;
            } else {
                mk -> next = p;
                mk = p;
            }
            p = p -> next;
        }

        ik -> next = max -> next;
        mk -> next = nullptr;

        return min -> next;
    }
};
