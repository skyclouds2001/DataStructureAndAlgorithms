class Solution {
private:
    void traversal(TreeNode* p, vector<int>& v) {
        if (p == nullptr) return;

        v.push_back(p -> val);
        traversal(p -> left, v);
        traversal(p -> right, v);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        traversal(root, v);
        return v;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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

            if (t -> right != nullptr) {
                s.push(t -> right);
            }
            if (t -> left != nullptr) {
                s.push(t -> left);
            }
        }

        return v;
    }
};
