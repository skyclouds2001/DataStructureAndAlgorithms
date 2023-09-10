class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root == p) {
            return p;
        }

        if (root == q) {
            return q;
        }

        auto l = lowestCommonAncestor(root -> left, p, q);
        auto r = lowestCommonAncestor(root -> right, p, q);

        if (l != nullptr && r != nullptr) {
            return root;
        } else if (l != nullptr) {
            return l;
        } else if (r != nullptr) {
            return r;
        } else {
            return nullptr;
        }
    }
};
