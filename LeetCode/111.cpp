class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        if (root -> left == nullptr && root -> right == nullptr) {
            return 1;
        }

        int ld = 0x0fffffff, rd = 0x0fffffff;
        if (root -> left != nullptr) {
            ld = minDepth(root -> left);
        }
        if (root -> right != nullptr) {
            rd = minDepth(root -> right);
        }

        int depth = min(ld, rd) + 1;

        return depth;
    }
};
