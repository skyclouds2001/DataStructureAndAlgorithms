class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* p = head;
        ListNode* q = nullptr;
        ListNode* r = nullptr;
        while (p -> next != nullptr) {
            int t = 0;
            p = p -> next;

            while (p -> val != 0) {
                t += p -> val;
                p = p -> next;
            }

            ListNode* qq = new ListNode(t, nullptr);
            if (q != nullptr) {
                r -> next = qq;
                r = r -> next;
            } else {
                q = qq;
                r = q;
            }
        }
        return q;
    }
};
