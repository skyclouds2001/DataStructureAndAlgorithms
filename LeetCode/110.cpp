class Solution {
private:
    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int l = getHeight(node -> left);
        int r = getHeight(node -> right);

        return abs(l - r) > 1 || l == -1 || r == -1 ? -1 : max(l, r) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
};
