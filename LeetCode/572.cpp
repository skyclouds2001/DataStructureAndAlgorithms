class Solution {
private:
    bool compare(TreeNode* left, TreeNode* right) {
        bool flag;

        if (left == nullptr && right == nullptr) {
            flag = true;
        } else if (left != nullptr && right == nullptr || left == nullptr && right != nullptr) {
            flag = false;
        } else if (left -> val != right -> val) {
            flag = false;
        } else {
            flag = compare(left -> left, right -> left) & compare(left -> right, right -> right);
        }

        return flag;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool flag = false;

        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty() && !flag) {
            TreeNode* p = s.top();
            s.pop();

            flag = compare(p, subRoot);

            if (p -> left != nullptr) {
                s.push(p -> left);
            }
            if (p -> right != nullptr) {
                s.push(p -> right);
            }
        }

        return flag;
    }
};
