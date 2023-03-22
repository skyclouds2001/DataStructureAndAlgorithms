/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head -> val == val) {
            ListNode* t = head;
            head = head -> next;
            delete t;
        }

        ListNode* p = head;
        while (p != NULL && p -> next != NULL) {
            if (p -> next -> val == val) {
                ListNode* t = p -> next;
                p -> next = p -> next -> next;
                delete t;
            } else {
                p = p -> next;
            }
        }

        return head;
    }
};
