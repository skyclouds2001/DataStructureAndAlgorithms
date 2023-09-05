class Solution {
    bool traversal(TreeNode* node, int sum) {
        if (node == nullptr) {
            return false;
        }
        if (sum == node -> val && node -> left == nullptr && node -> right == nullptr) {
            return true;
        }

        return traversal(node -> left, sum - node -> val) || traversal(node -> right, sum - node -> val);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return root != nullptr && traversal(root, targetSum);
    }
};
