class Solution {
private:
    bool compare(TreeNode* p, TreeNode* q) {
        bool flag;

        if (p == nullptr && q == nullptr) {
            flag = true;
        } else if (p != nullptr && q == nullptr || p == nullptr && q != nullptr) {
            flag = false;
        } else if (p -> val != q -> val) {
            flag = false;
        } else {
            flag = compare(p -> left, q -> left) && compare(p -> right, q -> right);
        }

        return flag;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compare(p, q);
    }
};
