class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* pa = list1;
        ListNode* pb = list1;
        ListNode* p = list2;

        for (int i = 0; i < a - 1; ++i) {
            pa = pa -> next;
        }
        for (int i = 0; i < b + 1; ++i) {
            pb = pb -> next;
        }

        while (p -> next != nullptr) {
            p = p -> next;
        }

        pa -> next = list2;
        p -> next = pb;

        return list1;
    }
};
