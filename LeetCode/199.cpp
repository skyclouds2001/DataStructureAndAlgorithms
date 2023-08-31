class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        queue<TreeNode*> q;

        if (root != nullptr) {
            q.push(root);
        }

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                TreeNode* p = q.front();
                q.pop();

                if (i == size - 1) {
                    v.push_back(p -> val);
                }

                if (p -> left != nullptr) {
                    q.push(p -> left);
                }
                if (p -> right != nullptr) {
                    q.push(p -> right);
                }
            }
        }

        return v;
    }
};
