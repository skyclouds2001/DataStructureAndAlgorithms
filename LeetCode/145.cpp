class Solution {
private:
    void traversal(TreeNode* p, vector<int>& v) {
        if (p == nullptr) return;

        traversal(p -> left, v);
        traversal(p -> right, v);
        v.push_back(p -> val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        traversal(root, v);
        return v;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;

        if (root == nullptr) {
            return v;
        }

        s.push(root);
        while(!s.empty()) {
            TreeNode* t = s.top();
            s.pop();

            v.push_back(t -> val);

            if (t -> left != nullptr) {
                s.push(t -> left);
            }
            if (t -> right != nullptr) {
                s.push(t -> right);
            }
        }

        reverse(v.begin(), v.end());

        return v;
    }
};
