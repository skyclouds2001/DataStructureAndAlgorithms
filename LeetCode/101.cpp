class Solution {
private:
    bool compare(TreeNode* left, TreeNode* right) {
        bool flag;

        if (left == nullptr && right == nullptr) {
            flag = true;
        } else if (left != nullptr && right == nullptr || left == nullptr && right != nullptr) {
            flag = false;
        } else if (left -> val != right -> val) {
            flag = false;
        } else {
            flag = compare(left -> left, right -> right) & compare(left -> right, right -> left);
        }

        return flag;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || compare(root -> left, root -> right);
    }
};
