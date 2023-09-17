class BSTIterator {
private:
    stack<TreeNode*> stack;
    TreeNode* pos;
public:
    BSTIterator(TreeNode* root) {
        pos = root;
    }

    int next() {
        while (pos != nullptr) {
            stack.push(pos);
            pos = pos -> left;
        }

        pos = stack.top();
        stack.pop();

        int v = pos -> val;

        pos = pos -> right;

        return v;
    }

    bool hasNext() {
        return !stack.empty() || pos != nullptr;
    }
};
