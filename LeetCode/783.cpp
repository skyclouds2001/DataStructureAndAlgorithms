class Solution {
private:
    vector<int> v;
    void traversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        traversal(node -> left);
        v.push_back(node -> val);
        traversal(node -> right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        traversal(root);

        const int size = v.size();
        int ans = INT_MAX;
        for (int i = 1; i < size; ++i) {
            ans = min(ans, v[i] - v[i - 1]);
        }

        return ans;
    }
};
