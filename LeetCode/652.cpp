class Solution {
private:
    unordered_set<TreeNode*> s;
    unordered_map<string, TreeNode*> m;

    string traversal(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }

        string left = traversal(root -> left);
        string right = traversal(root -> right);

        string cur = to_string(root -> val) + "(" + left + ")" + "(" + right + ")";

        if (m.count(cur) == 0) {
            m.insert(pair<string, TreeNode*>(cur, root));
        } else {
            s.insert(m.at(cur));
        }

        return cur;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traversal(root);

        return vector<TreeNode*>(s.begin(), s.end());
    }
};
