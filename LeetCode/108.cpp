class Solution {
private:
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int index = left + ((right - left) / 2);

        TreeNode* l = traversal(nums, left, index - 1);
        TreeNode* r = traversal(nums, index + 1, right);

        return new TreeNode(nums[index], l, r);
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traversal(nums, 0, nums.size() - 1);
    }
};
