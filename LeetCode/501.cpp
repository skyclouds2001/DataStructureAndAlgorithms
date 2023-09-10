class Solution {
private:
    vector<int> ans;
    int max = INT_MIN;
    int count = 0;
    TreeNode* pre = nullptr;

    void traversal(TreeNode* node) {
        if (node != nullptr) {
            traversal(node -> left);

            if (pre == nullptr) {
                count = 0;
                ++count;
            } else if (pre -> val == node -> val) {
                ++count;
            } else if (pre -> val != node -> val) {

                count = 0;
                ++count;
            }

            if (max == count) {
                ans.push_back(node -> val);
            } else if (max < count) {
                max = count;
                ans.clear();
                ans.push_back(node -> val);
            } else if (max > count) {}

            pre = node;

            traversal(node -> right);
        }
    }
public:
    vector<int> findMode(TreeNode* root) {
        traversal(root);

        return ans;
    }
};
