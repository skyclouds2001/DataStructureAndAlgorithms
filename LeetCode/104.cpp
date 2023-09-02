class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int l_depth = maxDepth(root -> left);
        int r_depth = maxDepth(root -> right);
        int depth = max(l_depth, r_depth) + 1;

        return depth;
    }
};

class Solution {
    int result = 0;

    void getDepth(TreeNode* node, int depth) {
        result = max(result, depth);

        if (node -> left != nullptr) {
            ++depth;
            getDepth(node -> left, depth);
            --depth;
        }

        if (node -> right != nullptr) {
            ++depth;
            getDepth(node -> right, depth);
            --depth;
        }
    }
public:
    int maxDepth(TreeNode* root) {
        if (root != nullptr) {
            getDepth(root, 1);
        }

        return result;
    }
};
