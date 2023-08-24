struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head -> next == nullptr) {
            return head;
        }

        int len = 0;

        auto start = head;
        auto end = head;
        for (; end != nullptr && end -> next != nullptr; end = end -> next) {
            ++len;
        }
        ++len;
        end -> next = start;

        const int move = len - k % len - 1;

        auto p = head;
        auto q = p;
        for (int i = 0; i < move; ++i) {
            p = p -> next;
        }
        q = p -> next;

        p -> next = nullptr;

        return q;
    }
};
