class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root -> val == val) {
            return root;
        }

        if (root -> val > val) {
            return searchBST(root -> left, val);
        }
        if (root -> val < val) {
            return searchBST(root -> right, val);
        }

        return nullptr;
    }
};
