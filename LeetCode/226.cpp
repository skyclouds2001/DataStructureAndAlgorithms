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
        stack<TreeNode*> stack;
        if (root != nullptr) {
            stack.push(root);
        }

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

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> queue;
        if (root != nullptr) {
            queue.push(root);
        }

        while(!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = queue.front();
                queue.pop();

                swap(node -> left, node -> right);
                if (node -> left != nullptr) {
                    queue.push(node -> left);
                }
                if (node -> right != nullptr) {
                    queue.push(node -> right);
                }
            }
        }

        return root;
    }
};
