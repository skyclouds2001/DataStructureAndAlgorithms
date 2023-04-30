/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ha = NULL, * hb = NULL;

        int lena = 0, lenb = 0;
        ha = headA;
        hb = headB;
        while(ha != NULL) {
            ++lena;
            ha = ha -> next;
        }
        while(hb != NULL) {
            ++lenb;
            hb = hb -> next;
        }

        ha = headA;
        hb = headB;
        if (lena > lenb) {
            for (int i = 0; i < lena - lenb; ++i) {
                ha = ha -> next;
            }
        }
        if (lena < lenb) {
            for (int i = 0; i < lenb - lena; ++i) {
                hb = hb -> next;
            }
        }

        while (ha != hb && ha != NULL && hb != NULL) {
            ha = ha -> next;
            hb = hb -> next;
        }

        return ha;
    }
};
