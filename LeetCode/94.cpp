class Solution {
private:
    void traversal(TreeNode* p, vector<int>& v) {
        if (p == nullptr) return;

        traversal(p -> left, v);
        v.push_back(p -> val);
        traversal(p -> right, v);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        traversal(root, v);
        return v;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode*> s;
        TreeNode* p;
        vector<int> v;

        p = root;
        while(!s.empty() || p != nullptr) {
            if (p != nullptr) {
                s.push(p);
                p = p -> left;
            } else {
                p = s.top();
                s.pop();
                v.push_back(p -> val);
                p = p -> right;
            }
        }

        return v;
    }
};
