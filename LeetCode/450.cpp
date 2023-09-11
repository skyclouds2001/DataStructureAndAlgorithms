class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root -> val == key) {
            if (root -> left == nullptr && root -> right == nullptr) {
                return nullptr;
            } else if (root -> left == nullptr) {
                return root -> right;
            } else if (root -> right == nullptr) {
                return root -> left;
            } else {
                TreeNode* p = root -> right;
                while (p -> left != nullptr) {
                    p = p -> left;
                }
                p -> left = root -> left;
                return root -> right;
            }
        } else if (root -> val < key) {
            root -> right = deleteNode(root -> right, key);
        } else if (root -> val > key) {
            root -> left = deleteNode(root -> left, key);
        }

        return root;
    }
};
