class Solution {
private:
    ListNode* getMiddle(ListNode* start, ListNode* end) {
        ListNode* fast = start;
        ListNode* slow = start;

        while (fast != end && fast -> next != end) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        return slow;
    }
    TreeNode* buildTree(ListNode* start, ListNode* end) {
        if (start == end) {
            return nullptr;
        }

        ListNode* mid = getMiddle(start, end);

        int val = mid -> val;
        TreeNode* left = buildTree(start, mid);
        TreeNode* right = buildTree(mid -> next, end);

        return new TreeNode(val, left, right);
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, nullptr);
    }
};
