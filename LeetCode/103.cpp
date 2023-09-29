class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> queue;
        bool flag = true;

        if (root != nullptr) {
            queue.push(root);
        }

        while (!queue.empty()) {
            deque<int> v;
            const int size = queue.size();

            for (int i = 0; i < size; ++i) {
                TreeNode* node = queue.front();
                queue.pop();

                if (flag) {
                    v.push_back(node -> val);
                } else {
                    v.push_front(node -> val);
                }

                if (node -> left != nullptr) {
                    queue.push(node -> left);
                }
                if (node -> right != nullptr) {
                    queue.push(node -> right);
                }
            }

            ans.push_back(vector<int>(v.begin(), v.end()));
            flag = !flag;
        }

        return ans;
    }
};
