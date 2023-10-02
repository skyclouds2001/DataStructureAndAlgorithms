class Solution {
private:
    void traversal(TreeNode* root, vector<int>& v) {
        if (root == nullptr) {
            return;
        }

        traversal(root -> left, v);
        traversal(root -> right, v);

        if (root -> left == nullptr && root -> right == nullptr) {
            v.push_back(root -> val);
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;

        traversal(root1, v1);
        traversal(root2, v2);

        return v1 == v2;
    }
};
