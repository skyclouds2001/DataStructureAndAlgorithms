class Solution {
private:
    TreeNode* head = nullptr;
    TreeNode* p = head;
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        auto l = root -> left;
        auto r = root -> right;

        if (head == nullptr) {
            head = root;
            p = head;
            root -> left = nullptr;
            root -> right = nullptr;
        } else {
            p -> right = root;
            p = root;
            root -> left = nullptr;
            root -> right = nullptr;
        }

        flatten(l);
        flatten(r);
    }
};
