class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p = new ListNode(0, head);
        ListNode* psl = nullptr;
        ListNode* ps = p;
        ListNode* psr = nullptr;
        ListNode* pel = nullptr;
        ListNode* pe = p;
        ListNode* per = nullptr;

        ListNode* t = p;
        for (int i = 0; i < k - 1; ++i) {
            t = t -> next;
        }
        psl = t;
        psr = t -> next -> next;
        ps = t -> next;

        for (t = t -> next; t -> next != nullptr;) {
            t = t -> next;
            pe = pe -> next;
        }
        pel = pe;
        per = pe -> next -> next;
        pe = pe -> next;

        if (ps == pe) {
            return p -> next;
        } else if (ps == pel && pe == psr) {
            psl -> next = pe;
            ps -> next = per;
            pe -> next = ps;
        } else if (pe == psl && ps == per) {
            pel -> next = ps;
            pe -> next = psr;
            ps -> next = pe;
        } else {
            psl -> next = pe;
            pel -> next = ps;
            pe -> next = psr;
            ps -> next = per;
        }

        return p -> next;
    }
};
