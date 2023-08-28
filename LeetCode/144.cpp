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
