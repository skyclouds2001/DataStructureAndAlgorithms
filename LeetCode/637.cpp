class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> v;
        queue<TreeNode*> q;

        if (root != nullptr) {
            q.push(root);
        }

        while (!q.empty()) {
            const int size = q.size();
            double sum = 0;

            for (int i = 0; i < size; ++i) {
                TreeNode* p = q.front();
                q.pop();

                sum += p -> val;
                if (p -> left != nullptr) {
                    q.push(p -> left);
                }
                if (p -> right != nullptr) {
                    q.push(p -> right);
                }
            }

            v.push_back(sum / size);
        }

        return v;
    }
};
