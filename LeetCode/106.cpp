class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) {
            return nullptr;
        }

        int val = postorder.back();

        auto p = find(inorder.begin(), inorder.end(), val);

        vector<int> il(inorder.begin(), p);
        vector<int> ir(p + 1, inorder.end());

        int ls = il.size();
        int rs = ir.size();

        vector<int> pl(postorder.begin(), postorder.begin() + ls);
        vector<int> pr(postorder.end() - rs - 1, postorder.end() - 1);

        TreeNode* left = traversal(il, pl);
        TreeNode* right = traversal(ir, pr);

        return new TreeNode(val, left, right);
    }
};
