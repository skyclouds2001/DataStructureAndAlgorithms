class Solution {
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
    bool isValidBST(TreeNode* root) {
        traversal(root);

        const int size = v.size();
        bool flag = true;
        for (int i = 1; i < size; ++i) {
            flag = flag && v[i - 1] < v[i];
        }

        return flag;
    }
};
