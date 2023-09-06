class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }

        int val = preorder.front();

        auto p = find(inorder.begin(), inorder.end(), val);

        vector<int> il(inorder.begin(), p);
        vector<int> ir(p + 1, inorder.end());

        int ls = il.size();
        int rs = ir.size();

        vector<int> pl(preorder.begin() + 1, preorder.begin() + ls + 1);
        vector<int> pr(preorder.end() - rs, preorder.end());

        TreeNode* left = buildTree(pl, il);
        TreeNode* right = buildTree(pr, ir);

        return new TreeNode(val, left, right);
    }
};
