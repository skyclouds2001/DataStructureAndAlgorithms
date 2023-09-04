class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int ls = sumOfLeftLeaves(root -> left);

        if (root -> left != nullptr && root -> left -> left == nullptr && root -> left -> right == nullptr) {
            ls = root -> left -> val;
        }

        int rs = sumOfLeftLeaves(root -> right);

        return ls + rs;
    }
};
