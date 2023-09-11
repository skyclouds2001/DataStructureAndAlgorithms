class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root;

        if (root == nullptr) {
            return new TreeNode(val);
        }

        while (true) {
            if (node -> val > val) {
                if (node -> left != nullptr) {
                    node = node -> left;
                } else {
                    node -> left = new TreeNode(val);
                    break;
                }
            } else if (node -> val < val) {
                if (node -> right != nullptr) {
                    node = node -> right;
                } else {
                    node -> right = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        if (root -> val < val) {
            root -> right = insertIntoBST(root -> right, val);
        } else if (root -> val > val) {
            root -> left = insertIntoBST(root -> left, val);
        }

        return root;
    }
};
