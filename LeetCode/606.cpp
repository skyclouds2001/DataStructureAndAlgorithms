class Solution {
public:
    string tree2str(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }

        string middle = to_string(root -> val);

        string left = tree2str(root -> left);
        string right = tree2str(root -> right);

        string res = middle;
        if (left.length() == 0 && right.length() == 0) {
            res += "";
        } else if (left.length() == 0) {
            res += "(" + left + ")" + "(" + right + ")";
        } else if (right.length() == 0) {
            res += "(" + left + ")";
        } else {
            res += "(" + left + ")" + "(" + right + ")";
        }

        return res;
    }
};
