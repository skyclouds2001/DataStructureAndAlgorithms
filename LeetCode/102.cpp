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

class Solution {
private:
    void order(TreeNode* node, vector<vector<int>>& v, int depth) {
        if (node == nullptr) {
            return;
        }

        if (v.size() == depth) {
            v.push_back(vector<int>());
        }

        v[depth].push_back(node -> val);

        order(node -> left, v, depth + 1);
        order(node -> right, v, depth + 1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;

        order(root, v, 0);

        return v;
    }
};
