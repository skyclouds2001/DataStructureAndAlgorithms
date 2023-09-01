class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> v;
        queue<TreeNode*> q;

        if (root != nullptr) {
            q.push(root);
        }

        while (!q.empty()) {
            const int count = q.size();
            int val = INT_MIN;

            for (int i = 0; i < count; ++i) {
                TreeNode* n = q.front();
                q.pop();

                val = max(val, n -> val);
                if (n -> left) {
                    q.push(n -> left);
                }
                if (n -> right) {
                    q.push(n -> right);
                }
            }

            v.push_back(val);
        }

        return v;
    }
};
