class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int l = countNodes(root -> left);
        int r = countNodes(root -> right);
        int c = l + r + 1;

        return c;
    }
};
