class Solution {
    void traversal(TreeNode* node, int sum, vector<int>& path, vector<vector<int>>& paths) {
        if (node == nullptr) {
            return;
        }

        path.push_back(node -> val);

        if (sum == node -> val && node -> left == nullptr && node -> right == nullptr) {
            paths.push_back(vector<int>(path));

            path.pop_back();
            return;
        }

        traversal(node -> left, sum - node -> val, path, paths);
        traversal(node -> right, sum - node -> val, path, paths);

        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;

        traversal(root, targetSum, path, paths);

        return paths;
    }
};
