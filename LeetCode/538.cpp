class Solution {
private:
    int val = 0;
    void traversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        traversal(root -> right);

        root -> val += val;
        val = root -> val;

        traversal(root -> left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        traversal(root);

        return root;
    }
};
