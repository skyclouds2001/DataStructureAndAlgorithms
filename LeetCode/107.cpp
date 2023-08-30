class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> queue;
        if (root != nullptr) {
            queue.push(root);
        }

        vector<vector<int>> result;

        while (!queue.empty()) {
            int size = queue.size();
            vector<int> v;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = queue.front();
                queue.pop();

                v.push_back(node -> val);
                if (node -> left != nullptr) {
                    queue.push(node -> left);
                }
                if (node -> right != nullptr) {
                    queue.push(node -> right);
                }
            }

            result.push_back(v);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
