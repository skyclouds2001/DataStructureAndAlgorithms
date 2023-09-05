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
