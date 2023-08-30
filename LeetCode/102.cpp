class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> queue;
        if (root != nullptr) {
            queue.push(root);
        }

        vector<vector<int>> result;

        while (!queue.empty()) {
            int size = queue.size();
            vector<int> vector;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = queue.front();
                queue.pop();

                vector.push_back(node -> val);
                if (node -> left != nullptr) {
                    queue.push(node -> left);
                }
                if (node -> right != nullptr) {
                    queue.push(node -> right);
                }
            }

            result.push_back(vector);
        }

        return result;
    }
};
