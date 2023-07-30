class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* p = head;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1 -> val > list2 -> val) {
                p -> next = list2;
                list2 = list2 -> next;
            } else {
                p -> next = list1;
                list1 = list1 -> next;
            }
            p = p -> next;
        }
        while (list1 != nullptr) {
            p -> next = list1;
            list1 = list1 -> next;
            p = p -> next;
        }
        while (list2 != nullptr) {
            p -> next = list2;
            list2 = list2 -> next;
            p = p -> next;
        }
        return head -> next;
    }
};
