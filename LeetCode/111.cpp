class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        if (root -> left == nullptr && root -> right == nullptr) {
            return 1;
        }

        int ld = 0x0fffffff, rd = 0x0fffffff;
        if (root -> left != nullptr) {
            ld = minDepth(root -> left);
        }
        if (root -> right != nullptr) {
            rd = minDepth(root -> right);
        }

        int depth = min(ld, rd) + 1;

        return depth;
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int depth = 0;

        if (root != nullptr) {
            q.push(root);
        }

        while (!q.empty()) {
            const int size = q.size();

            ++depth;

            for (int i = 0; i < size; ++i) {
                TreeNode* p = q.front();
                q.pop();

                if (p -> left == nullptr && p -> right == nullptr) {
                    goto EXIT;
                }
                if (p -> left != nullptr) {
                    q.push(p -> left);
                }
                if (p -> right != nullptr) {
                    q.push(p -> right);
                }
            }
        }

        EXIT:

        return depth + 1;
    }
};
