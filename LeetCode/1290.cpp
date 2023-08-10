class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* p = head;
        int ans = 0;

        while (p != nullptr) {
            ans *= 2;
            ans += p -> val;
            p = p -> next;
        }

        return ans;
    }
};
