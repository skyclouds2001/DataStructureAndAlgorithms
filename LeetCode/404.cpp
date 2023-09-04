class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int ls = sumOfLeftLeaves(root -> left);

        if (root -> left != nullptr && root -> left -> left == nullptr && root -> left -> right == nullptr) {
            ls = root -> left -> val;
        }

        int rs = sumOfLeftLeaves(root -> right);

        return ls + rs;
    }
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        int sum = 0;

        if (root != nullptr) {
            q.push(root);
        }

        while (!q.empty()) {
            const int size = q.size();

            for (int i = 0; i < size; ++i) {
                auto p = q.front();
                q.pop();

                if (p -> left != nullptr && p -> left -> left == nullptr && p -> left -> right == nullptr) {
                    sum += p -> left -> val;
                }

                if (p -> left != nullptr) {
                    q.push(p -> left);
                }
                if (p -> right != nullptr) {
                    q.push(p -> right);
                }
            }
        }

        return sum;
    }
};
