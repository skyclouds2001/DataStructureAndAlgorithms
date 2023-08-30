class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        swap(root -> left, root -> right);
        invertTree(root -> left);
        invertTree(root -> right);

        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        stack<TreeNode*> stack;

        stack.push(root);
        while(!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();

            swap(node -> left, node -> right);
            if (node -> left != nullptr) {
                stack.push(node -> left);
            }
            if (node -> right != nullptr) {
                stack.push(node -> right);
            }
        }

        return root;
    }
};
