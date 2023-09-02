class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int l_depth = maxDepth(root -> left);
        int r_depth = maxDepth(root -> right);
        int depth = max(l_depth, r_depth) + 1;

        return depth;
    }
};
