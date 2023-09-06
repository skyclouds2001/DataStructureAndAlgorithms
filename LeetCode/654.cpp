class Solution {
private:
    TreeNode* createTree(vector<int>& nums, vector<int>::iterator begin, vector<int>::iterator end) {
        TreeNode* root = new TreeNode();

        auto p = max_element(begin, end);
        root -> val = *p;

        if (begin != p) {
            root -> left = createTree(nums, begin, p);
        }
        if (p != end - 1) {
            root -> right = createTree(nums, p + 1, end);
        }

        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return createTree(nums, nums.begin(), nums.end());;
    }
};