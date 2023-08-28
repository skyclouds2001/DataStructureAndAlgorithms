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
