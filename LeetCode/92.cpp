class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* h = new ListNode(0, head);

        // position at (left-1)
        ListNode* l = h;
        for (int i = 1; i <= left - 1; ++i) {
            l = l -> next;
        }

        // position at (right)
        ListNode* rn = l;
        for (int i = 1; i <= right - left + 1; ++i) {
            rn = rn -> next;
        }

        // position at (left)
        ListNode* ln = l -> next;
        // position at (right+1)
        ListNode* r = rn -> next;

        l -> next = nullptr;
        rn -> next = nullptr;

        ListNode* p = ln;
        ListNode* q = nullptr;
        while (p != nullptr) {
            auto t = p;
            p = p -> next;
            t -> next = q;
            q = t;
        }

        l -> next = rn;
        ln -> next = r;

        return h -> next;
    }
};
