class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        ListNode* p = nullptr;
        if (fast == nullptr) {
            p = slow;
        } else {
            p = slow -> next;
        }

        ListNode* pr = nullptr;
        ListNode* af = nullptr;
        while(p != nullptr) {
            af = p -> next;
            p -> next = pr;
            pr = p;
            p = af;
        }

        ListNode* pre = head;
        ListNode* aft = pr;
        bool flag = true;
        while(pre != nullptr && aft != nullptr) {
            if (pre -> val != aft -> val) {
                flag = false;
                break;
            }
            pre = pre -> next;
            aft = aft -> next;
        }

        return flag;
    }
};
