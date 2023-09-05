class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> queue;
        int ans;

        queue.push(root);

        while (!queue.empty()) {
            const int size = queue.size();

            ans = queue.front() -> val;

            for (int i = 0; i < size; ++i) {
                auto node = queue.front();
                queue.pop();

                if (node -> left != nullptr) {
                    queue.push(node -> left);
                }
                if (node -> right != nullptr) {
                    queue.push(node -> right);
                }
            }
        }

        return ans;
    }
};

class Solution {
private:
    int res;
    int maxDepth = INT_MIN;
    void traversal(TreeNode* node, int depth) {
        if (node -> left == nullptr && node -> right == nullptr) {
            if (depth > maxDepth) {
                maxDepth = depth;
                res = node -> val;
            }
            return;
        }

        if (node -> left != nullptr) {
            ++depth;
            traversal(node -> left, depth);
            --depth;
        }

        if (node -> right != nullptr) {
            ++depth;
            traversal(node -> right, depth);
            --depth;
        }
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return res;
    }
};
