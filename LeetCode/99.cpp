class Solution {
public:
    void recoverTree(TreeNode* root) {
        auto p = root;
        stack<TreeNode*> s;
        TreeNode* pre = nullptr;
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;

        while (!s.empty() || p != nullptr) {
            while (p != nullptr) {
                s.push(p);
                p = p -> left;
            }

            p = s.top();
            s.pop();

            if (pre != nullptr && pre -> val > p -> val) {
                y = p;
                if (x == nullptr) {
                    x = pre;
                } else {
                    break;
                }
            }

            pre = p;
            p = p -> right;
        }

        swap(x -> val, y -> val);
    }
};
